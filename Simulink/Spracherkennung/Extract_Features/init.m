clear load;
clear all;
close all;


load('commandNet.mat') % beinhaltet trainedNet und wird hier in das Workspace geladen 
%load('left_test.mat')

classificationRate = 20; % Rate?
fs=16000;
adr = audioDeviceReader('SampleRate',fs,'SamplesPerFrame',floor(fs/classificationRate)); % stelt das Standartaudiogerät auf die entsprechenden Werte
audioBuffer = dsp.AsyncBuffer(fs); % auslesen des Audibuffers
[filterBank2,CF2] = designAuditoryFilterBank(fs,'FFTLength',512,'NumBands',50,"FrequencyScale","bark",'Normalization','none');
win = hann(400,'periodic');  
%[y,fs] = audioread('left.wav');

  %y2=audio_data(:,:,1);
  
h = figure('Units','normalized','Position',[0.2 0.1 0.6 0.8]);

timeLimit = inf; % Zeit der Ausführung

tic;

    
  while ishandle(h) && toc < timeLimit

    % Extract audio samples from the audio device and add the samples to
    % the buffer.
    x = adr();
    write(audioBuffer,x);
    y = read(audioBuffer,fs,fs-adr.SamplesPerFrame);

  
  %% Compute spectrogram
   
  [~,F,T,S] = spectrogram(y,win,240,512,fs,'onesided');

  % Design auditory filter bank
  %   [filterBank,CF] = designAuditoryFilterBank(fs,'FFTLength',512,...
  %                       'NumBands',16,'Normalization','none');
   
  % Visualize filter bank
%   plot(F , filterBank2.')
%   grid on
%   title('Bark Filter Bank')
%   xlabel('Frequency (Hz)')
     
  % Compute mel spectrogram
  SBark = filterBank2 * S;
    
  unNorm = 2/(sum(win)^2);
  features = SBark/unNorm;
  epsil = 1e-6;

% Take the log. 
  features = log10(features + epsil)';
 
  [YPredicted,probs] = classify(trainedNet,features,'ExecutionEnvironment','cpu');
  
  YPredicted
  
 end
  
  SBark2 = ptoPperfreq(SBark,ftoBarks(F));


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








