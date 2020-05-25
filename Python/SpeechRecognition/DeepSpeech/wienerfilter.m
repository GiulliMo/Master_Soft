clear all;
close all;
clear load;

dataiS = audioread('noSound.wav');
dataNS= audioread('StreamMono2.wav');

fSample = 16000;
tSample= 1/fSample;

t=0:tSample:tSample*(length(dataNS)-1);

y=WienerScalart96(dataNS,fSample,0.1);

figure(4)
plot(t,dataNS,'r')
hold on
plot(t(1:length(y)),y,'b')

audiowrite('mono2filt.wav',y,fSample)