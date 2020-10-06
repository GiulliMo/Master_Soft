#!/usr/bin/env python
# license removed for brevity

import pyaudio
import os
import time
import rospy
import numpy as np
from std_msgs.msg import Int16MultiArray, String, Int16
import sounddevice as sd


class AudioStream:

    def __init__(self, topicname1, topicname2, nodename, dev, recsec):
        self.stream_topicname = topicname1
        self.button_topicname = topicname2
        self.nodename = nodename
        self.channels = 1
        self.rate = 16000
        self.chunksize = 2048
        self.devIndex = dev
        self.msg = Int16MultiArray()
        self.msg.data = []
        self.format = pyaudio.paInt16
        self.audio = pyaudio.PyAudio()
        self.recsec = recsec
        self.frames = []
        self.button = False



    def createAudioStream(self):

        stream = self.audio.open(format=self.format, rate=self.rate, channels=self.channels,
                                 input_device_index=self.devIndex, input=True,
                                 frames_per_buffer=self.chunksize)
        self.frames=[]
        self.frames.append(stream.read(self.chunksize))  # Erstes mal append dauert laenger

        print("start recording...")
        for i in range(0, int(self.rate / self.chunksize) * self.recsec):
            self.frames.append(stream.read(self.chunksize))
        print("recording finished")

        self.frames.pop(0)# erster Frame wird wieder weggenommen
        self.msg.data = np.frombuffer(np.asarray(self.frames), dtype=np.int16)
        stream.stop_stream()
        stream.close()

    def callback(self, msg):
        self.button = msg.data

    def startNode(self):

        pub = rospy.Publisher(self.stream_topicname, Int16MultiArray, queue_size=len(self.msg.data))
        rospy.Subscriber(self.button_topicname, Int16, self.callback)
        rospy.init_node(self.nodename, anonymous=True)
        r = rospy.Rate(0.05)
        while not rospy.is_shutdown():

            try:
                if self.button:
                    rospy.loginfo("Start streaming audio...")
                    self.createAudioStream()
                    pub.publish(self.msg)
                    rospy.loginfo("Finished streaming audio!")


                time.sleep(0.01)

            except KeyboardInterrupt:
                print("KeyBoard interrupt")
            pass


if __name__ == '__main__':

    string = sd.query_devices()
    print(string)

    device = rospy.get_param('/audioStream/deviceID')  # = pulse bzw name, name geht bis zum ersten komma zb Xbox NUI Sensor: USB Audio (hw:1,0)

    for i in range(len(string)):

        if string[i]["name"].count(device):
            print(i)
            dev = i
            break

    s = AudioStream(topicname1=rospy.get_param('pub/stream/topic'), topicname2=rospy.get_param('/audioStream/sub/button/topic'), dev=dev, nodename=rospy.get_param("/audioStream/nodename"), recsec=rospy.get_param('/audioStream/recsec'))
    print("Use device: " + device)
    s.startNode()

