# import the necessary packages
from __future__ import print_function
from imutils.object_detection import non_max_suppression
from imutils import paths
import numpy as np
import argparse
import imutils
import cv2
import rospy
import sys
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError



def callback(msg):
	global test
	global trackers
	global OPENCV_OBJECT_TRACKERS 

	bridge = CvBridge()
	print(test)			
	try: 
		cv_image = bridge.imgmsg_to_cv2(msg, "bgr8")		
		
		image = imutils.resize(cv_image, width=min(400, cv_image.shape[1]))
		orig = image.copy()



		# grab the updated bounding box coordinates (if any) for each
		# object that is being tracked
		(success, boxes) = trackers.update(image)
		# loop over the bounding boxes and draw then on the frame
		for box in boxes:
			(x, y, w, h) = [int(v) for v in box]
			cv2.rectangle(image, (x, y), (x + w, y + h), (0, 255, 0), 2)

		# show the output frame
		cv2.imshow("Frame", image)
		key = cv2.waitKey(1) & 0xFF
		# if the 's' key is selected, we are going to "select" a bounding
		# box to track
		if key == ord("s"):
			# select the bounding box of the object we want to track (make
			# sure you press ENTER or SPACE after selecting the ROI)
			box = cv2.selectROI("Frame", image, fromCenter=False,
				showCrosshair=True)
			# create a new object tracker for the bounding box and add it
			# to our multi-object tracker
			tracker = OPENCV_OBJECT_TRACKERS['kcf']()
			trackers.add(tracker, image, box)
		


	except CvBridgeError as e:
		print(e)

	test = test + 1
	
def initTracker():
	global test
	global trackers
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

			


	"""
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
	image = imutils.resize(cv_image, width=min(400, cv_image.shape[1]))
	orig = image.copy()



	# grab the updated bounding box coordinates (if any) for each
	# object that is being tracked
	(success, boxes) = trackers.update(image)
	# loop over the bounding boxes and draw then on the frame
	for box in boxes:
		(x, y, w, h) = [int(v) for v in box]
		cv2.rectangle(image, (x, y), (x + w, y + h), (0, 255, 0), 2)

	# show the output frame
	cv2.imshow("Frame", image)
	key = cv2.waitKey(1) & 0xFF
	# if the 's' key is selected, we are going to "select" a bounding
	# box to track
	if key == ord("s"):
		# select the bounding box of the object we want to track (make
		# sure you press ENTER or SPACE after selecting the ROI)
		box = cv2.selectROI("Frame", image, fromCenter=False,
			showCrosshair=True)
		# create a new object tracker for the bounding box and add it
		# to our multi-object tracker
		tracker = OPENCV_OBJECT_TRACKERS['kcf']()
		trackers.add(tracker, image, box)
		

	# if the `q` key was pressed, break from the loop
	"""	

if __name__ == '__main__':
	initTracker()
	listener()
	




"""
# construct the argument parse and parse the arguments
ap = argparse.ArgumentParser()
ap.add_argument("-i", "--images", required=True, help="/home/alf/Bilder")
args = vars(ap.parse_args())
print(args["images"])
# initialize the HOG descriptor/person detector
hog = cv2.HOGDescriptor()
hog.setSVMDetector(cv2.HOGDescriptor_getDefaultPeopleDetector())

# loop over the image paths

# load the image and resize it to (1) reduce detection time
# and (2) improve detection accuracy
image = cv2.imread('/home/alf/Bilder/ped.jpg')

image = imutils.resize(image, width=min(400, image.shape[1]))
orig = image.copy()

# detect people in the image
(rects, weights) = hog.detectMultiScale(image, winStride=(4, 4),
	padding=(8, 8), scale=1.05)

# draw the original bounding boxes
for (x, y, w, h) in rects:
	cv2.rectangle(orig, (x, y), (x + w, y + h), (0, 0, 255), 2)

# apply non-maxima suppression to the bounding boxes using a
# fairly large overlap threshold to try to maintain overlapping
# boxes that are still people
rects = np.array([[x, y, x + w, y + h] for (x, y, w, h) in rects])
pick = non_max_suppression(rects, probs=None, overlapThresh=0.65)

# draw the final bounding boxes
for (xA, yA, xB, yB) in pick:
	cv2.rectangle(image, (xA, yA), (xB, yB), (0, 255, 0), 2)

# show some information on the number of bounding boxes



# show the output images
cv2.imshow("Before NMS", orig)
cv2.imshow("After NMS", image)
cv2.waitKey(0)
"""
