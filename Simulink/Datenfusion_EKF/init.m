clear all;
close all;
clear load;
load('sensorlog4.mat')

fSample = 10;
tSample= 1/fSample;

t=0:tSample:tSample*(length(Acceleration1)-tSample);

data.time=t';
data.signals.values.acc=Acceleration1;
% data.signals.values.angVel=AngularVelocity1;
% data.signals.values.magFie=MagneticField1;
% data.signals.values.orientation=Orientation1;
data.signals.dimension=[3 531];


acc = timeseries(Acceleration1,t');
angVel = timeseries(AngularVelocity1,t(1:length(AngularVelocity1))');
magField = timeseries(MagneticField1,t(1:length(MagneticField1))');
orientation = timeseries(Orientation1,t(1:length(Orientation1))');