clear load;
clear all;
close all;

[y,fs] = audioread('dad.wav');

load('audio.mat')

y=audio_data(:,:,1);


%soundsc(y,fs);
t=0:length(y)-1;
t=t/fs; % time scale
fs = 16000;
figure(1)
plot(t,y)
hold off

%curtail signal
M=400; %%fft-length
%y=y(1:fs);
window = hamming(M);
ol=240;
over_length = ol/M;
NY = floor(length(y)/(M*(1-over_length)));
MY = M/8;
Y=zeros(NY,MY);
start = 1;
stop = start + M-1;
k=0;

while stop <= length(y)
    
    k =k+1;
    YY = fft(window.*y(start:stop))';
    Y(k,:) = abs(YY(1:MY));
    start = start + M*(1-over_length);
    stop = start + M-1;
    
end


Y = Y/max(max(Y));
t = 1:NY;
t = t*(M*(1-over_length))/fs;
f = 0:1:M/8-1;
f = fs*f/M;

z=ftoBarks(f)';

% 
% figure(2)
% waterfall(z,t,Y);
% hold off

figure(3)
[s,f,t]=spectrogram(y,hamming(M),ol,z,fs,'yaxis');
spectrogram(y,hamming(M),ol,z,fs,'yaxis')
hold off

s=abs(s);

s = s/max(max(s));

s2 = ptoPperfreq(s,f);

s2=permute(s2,[2,1]);

function s = ptoPperfreq(s,f)

[height,width]=size(s);

for i=1:height
    
    for k=1:width
        
        s(i,k)=20*log(s(i,k))/f(i);
        
    end
end

end

function z = ftoBarks(f)

nFreq = length(f);
z=zeros(nFreq,1);

for i=1:nFreq
    
    z(i)=13*atan(0.00076*f(i))+3.5*atan((f(i)/7500)^2);
    
end


end








