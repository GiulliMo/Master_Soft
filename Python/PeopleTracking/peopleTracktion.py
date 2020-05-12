from centroidtracker import CentroidTracker
from imutils.object_detection import non_max_suppression
import numpy as np
import argparse
import imutils
import cv2
import rospy
import sys
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError



def callback(msg):
	global net
	net = cv2.dnn.readNetFromCaffe("deploy.prototxt", "res10_300x300_ssd_iter_140000.caffemodel")
	global test
	global trackers
	global hog
	global cv
	global H
	global W
	global OPENCV_OBJECT_TRACKERS 
	bridge = CvBridge()
	print(test)
	try: 
		cv_image = bridge.imgmsg_to_cv2(msg, "bgr8")		
		
		#frame = imutils.resize(cv_image, width=300, height = 300)
		frame = imutils.resize(cv_image, width=min(400, cv_image.shape[1]))
		orig = frame.copy()
		cv2.imshow("Frame:anfang", frame)
		cv2.waitKey(3)
		(rects, weights) = hog.detectMultiScale(frame, winStride=(4, 4), padding=(8, 8), scale=1.05)
		#print(type(detection))
		#detections = np.array(detection)
		#print(type(detections))
		# if the frame dimensions are None, grab them
		#print(H)
		#print(W)
		"""
		if W is None or H is None:
			(H, W) = frame.shape[:2]
		# construct a blob from the frame, pass it through the network,
		# obtain our output predictions, and initialize the list of
		# bounding box rectangles
		#blob = cv2.dnn.blobFromImage(frame, 1.0, (W, H),(104.0, 177.0, 123.0))
		#net.setInput(blob)
		#detections = net.forward()
		rects = []
		print("1")
		# loop over the detections
		for i in range(0, detections.shape[0]):
			# filter out weak detections by ensuring the predicted
			# probability is greater than a minimum threshold
			if detections[0, 0, i, 2] > 0.5:
				# compute the (x, y)-coordinates of the bounding box for
				# the object, then update the bounding box rectangles list
				box = detections[0, 0, i, 3:7] * np.array([W, H, W, H])
				rects.append(box.astype("int"))
				# draw a bounding box surrounding the object so we can
				# visualize it
				(startX, startY, endX, endY) = box.astype("int")
				cv2.rectangle(frame, (startX, startY), (endX, endY),
					(0, 255, 0), 2)
		"""
		for (x, y, w, h) in rects:
			cv2.rectangle(orig, (x, y), (x + w, y + h), (0, 0, 255), 2)

		rects = np.array([[x, y, x + w, y + h] for (x, y, w, h) in rects])
		pick = non_max_suppression(rects, probs=None, overlapThresh=0.65)
		print(pick)
		# draw the final bounding boxes

		for (xA, yA, xB, yB) in pick:

			cv2.rectangle(frame, (xA, yA), (xB, yB), (0, 255, 0), 2)

		# update our centroid tracker using the computed set of bounding
		# box rectangles
		objects = ct.update(pick)
		print(objects)
		# loop over the tracked objects
		for (objectID, centroid) in objects.items():
			# draw both the ID of the object and the centroid of the
			# object on the output frame
			text = "ID {}".format(objectID)
			cv2.putText(frame, text, (centroid[0] - 10, centroid[1] - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
			cv2.circle(frame, (centroid[0], centroid[1]), 4, (0, 255, 0), -1)
		# show the output frame
		cv2.imshow("Frame", frame)
		cv2.waitKey(3)
		
	except CvBridgeError as e:
		print(e)

	
	test = test + 1
	

def initTracker():

	global net
	global test
	global trackers
	global ct
	global H
	global W
	global hog
	hog = cv2.HOGDescriptor()
	hog.setSVMDetector(cv2.HOGDescriptor_getDefaultPeopleDetector())
	#net = cv2.dnn.readNetFromCaffe("deploy.prototxt", "res10_300x300_ssd_iter_140000.caffemodel")
	ct = CentroidTracker()
	(H, W) = (None, None)
	test = 0
	global OPENCV_OBJECT_TRACKERS 

	OPENCV_OBJECT_TRACKERS = {
		"kcf": cv2.TrackerKCF_create,
		"boosting": cv2.TrackerBoosting_create,
		"mil": cv2.TrackerMIL_create,
		"tld": cv2.TrackerTLD_create,
		"medianflow": cv2.TrackerMedianFlow_create,
		"mosse": cv2.TrackerMOSSE_create
	}

	# initialize OpenCV's special multi-object tracker
	trackers = cv2.MultiTracker_create()

def listener():
	#global test
	#test = 0
	rospy.init_node('listener', anonymous=True)
	image_sub = rospy.Subscriber("/kinect2/qhd/image_color",Image,callback)
	try:
    		rospy.spin()
		
  	except KeyboardInterrupt:
    		print("Shutting down")
  	cv2.destroyAllWindows()

			



if __name__ == '__main__':
	initTracker()
	listener()
	






