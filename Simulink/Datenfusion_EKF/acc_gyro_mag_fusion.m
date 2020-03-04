clear all;
close all;
clear load;

load('sensorlog3.mat');


acc = Acceleration1;
gyro = AngularVelocity1;
mag = Orientation1;


ifilt = ahrsfilter('SampleRate', 100);
for ii=1:size(acc,1)
    qahrs = ifilt(acc(ii,:), gyro(ii,:), mag(ii,:));
    euler2(ii,:)=quat2eul(qahrs)*180/pi;
  %  viewer(qahrs);
   % pause(0.01);
end