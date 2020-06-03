import pyaudio
import rospy
import numpy as np
from std_msgs.msg import Int16MultiArray, String
import argparse
import sounddevice as sd

print sd.query_devices()

parser = argparse.ArgumentParser()
parser.add_argument("-tp", "--topicname", help="Name der veroeffentlichten Topic")
parser.add_argument("-nn", "--nodename", help="Name des Knotens")
parser.add_argument("-di", "--device", help="Device ID/n",type=int)
args = parser.parse_args()

class AudioStream:
    def __init__(self, topicname, nodename, dev):
        self.topicname = topicname
        self.nodename = nodename
        self.channels = 1
        self.rate = 16000
        self.chunksize = 2048
        self.devIndex = dev
        self.msg = Int16MultiArray()
        self.msg.data = []
        self.format = pyaudio.paInt16
        self.audio = pyaudio.PyAudio()


    def createAudioStream(self):

        stream = self.audio.open(format=self.format, rate=self.rate, channels=self.channels,
                                 input_device_index=self.devIndex, input=True,
                                 frames_per_buffer=self.chunksize)
        self.msg.data = []
        self.msg.data = np.frombuffer(np.asarray(stream.read(self.chunksize)), dtype=np.int16)

        stream.stop_stream()
        stream.close()

    def startNode(self):
        pub = rospy.Publisher(self.topicname, Int16MultiArray, queue_size=self.chunksize)
        rospy.init_node(self.nodename, anonymous=True)
        r = rospy.Rate(0.2)
        rospy.loginfo("Streaming Audio...")
        while not rospy.is_shutdown():
            try:
               self.createAudioStream()
               pub.publish(self.msg)
            except KeyboardInterrupt:
                print("KeyBoard interrupt")
            pass


if __name__ == '__main__':

    s = AudioStream(args.topicname, args.nodename, args.device)
    s.startNode()

