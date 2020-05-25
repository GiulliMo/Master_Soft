import pyaudio
import rospy
import numpy as np
from std_msgs.msg import Int32MultiArray
from rospy.numpy_msg import numpy_msg
import pyaudio

channels = 1
rate = 16000
chunksize = 2048
recsec = 10
devIndex = 0  # 0=Boltune, 1= boltune, 2 = builtin
audio = pyaudio.PyAudio()
format = pyaudio.paInt16


def talker():
        pub = rospy.Publisher('audio_stream', Int32MultiArray, queue_size=159743)
        rospy.init_node('audio', anonymous=True)
        rate = rospy.Rate(0.1) # 10hz
        while not rospy.is_shutdown():
                stream = audio.open(format=format, rate=rate, channels=channels,
                                     input_device_index=devIndex, input=True,
                                     frames_per_buffer=chunksize)
                print("recording...")
                frames = []

                for i in range(0, int(rate / chunksize * recsec)):
                    data = stream.read(chunksize)
                    frames.append(data)

                print("finished recording!")

                stream.stop_stream()
                stream.close()
                audio.terminate()
                data16 = np.frombuffer(frames, dtype=np.int16)
                rospy.loginfo(data16)
                pub.publish(data16)
                rate.sleep()
if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass

