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

class image_converter:

	def __init__(self):
    		self.bridge = CvBridge()
    		self.image_sub = rospy.Subscriber("/kinect2/qhd/image_color",Image,self.callback)

  	def callback(self,data):
    		try:
      			cv_image = self.bridge.imgmsg_to_cv2(data, "bgr8")
    		except CvBridgeError as e:
      			print(e)
    
    #(rows,cols,channels) = cv_image.shape
    #if cols > 60 and rows > 60 :
     # cv2.circle(cv_image, (50,50), 10, 255)

    #AB HIER PT CODE
		# initialize the HOG descriptor/person detector
		hog = cv2.HOGDescriptor()
		hog.setSVMDetector(cv2.HOGDescriptor_getDefaultPeopleDetector())
     		image = imutils.resize(cv_image, width=min(400, cv_image.shape[1]))
		orig = image.copy()

		# detect people in the image
		(rects, weights) = hog.detectMultiScale(image, winStride=(4, 4), padding=(8, 8), scale=1.05)

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
		

		# show the output images

		cv2.imshow("Before NMS", orig)

		cv2.imshow("After NMS", image)
   




    		#cv2.imshow("Image window", cv_image)
    		cv2.waitKey(3)

 

def main(args):
	ic  = image_converter()


if __name__ == '__main__':
	main(sys.argv)
	rospy.init_node('image_converter', anonymous=True)
 	try:
    		rospy.spin()
  	except KeyboardInterrupt:
    		print("Shutting down")
  	cv2.destroyAllWindows()




