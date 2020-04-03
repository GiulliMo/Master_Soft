#! /bin/sh

#Author: G.Montorio
#Title: CAN-Bus settings for initialization
#Comment: Use CANopen protocol

sudo ip link set down can0			#Close socket
sudo ip link set can0 type can restart-ms 0	#Restart socket
sudo ip link set can0 type can bitrate 500000	#Set bitrate
sudo ip link set up can0			#Open socket
sudo cansend can0 420#01			#Reset Errorregister Motorcontroller
sudo cansend can0 000#8100			#Set mode "Reset Node"
sudo cansend can0 080#				#Send SYNC-Message
sleep 0.5					#Important rule: Dont't do NMT-Bursts
sudo cansend can0 000#8200			#Set mode "Reset Communication"
sudo cansend can0 080#				#SYNC
sleep 0.5			
sudo cansend can0 000#8000			#Set mode "Pre-Operational"
sudo cansend can0 080#				#SYNC
sleep 0.5
sudo cansend can0 000#0100			#Set mode "Operational"
sudo cansend can0 080#				#SYNC
sleep 0.5
sudo cansend can0 201#06			#First computerheartbeat "0" + deactivate brakes + "reset MCM" (CAN-id 201 has to be checked)
sleep 0.001	
sudo cansend can0 401#0000000000000000		#Reset errorregister of SICK module
while true					#Sending sync forever
do 
  sudo cansend can0 201#03
  sudo cansend can0 080#			#SYNC
  sleep 0.001
  sudo cansend can0 201#02
  sudo cansend can0 080#			#SYNC
  sleep 0.001
done
