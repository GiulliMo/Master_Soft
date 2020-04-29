clear load;
clear all;
close all;


load('commandNet.mat') % beinhaltet trainedNet und wird hier in das Workspace geladen 
load('left_test.mat')
%y=audio_data(:,1);
classificationRate = 20; % Rate?
fs=16000;
[filterBank2,CF2] = designAuditoryFilterBank(fs,'FFTLength',512,'NumBands',50,"FrequencyScale","bark",'Normalization','none');
win = hann(400,'periodic');  

h = figure('Units','normalized','Position',[0.2 0.1 0.6 0.8]);

  
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








