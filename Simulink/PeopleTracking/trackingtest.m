sub = rossubscriber('/kinect1/qhd/image_color/compressed')
cont = 1;

while cont
    
    MBfnc(readImage(receive(sub)));
    
end