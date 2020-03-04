%Initialisierungs Skript fuer sdf_pi_test 

clear all;
close all;
clear load;
load('kalibrierIV.mat')

fSample = 100;
tSample= 1/fSample;

t=0:tSample:tSample*(length(acceleration)-tSample);

for i=1:length(acceleration)
    accel(i,:)=acceleration(:,:,i);
    angvel(i,:)=angVel(:,:,i);
    magnet(i,:)=magneticField(i,:);
end

acc = timeseries(accel,t');
angVel = timeseries(angvel,t(1:length(angvel))');
magField = timeseries(magnet/10,t(1:length(magnet))');
%orientation = timeseries(Orientation1,t(1:length(Orientation1))');