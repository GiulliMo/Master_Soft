function out = SECodegen(y)

persistent firstrun
classificationRate = 20; % Rate?
fs=16000;
win = hann(400,'periodic'); 



trainedNet = coder.loadDeepLearningNetwork('commandNet.mat'); % beinhaltet trainedNet und wird hier in das Workspace geladen 
%load('left_test.mat')



[filterBank2,CF2] = designAuditoryFilterBank(fs,'FFTLength',512,'NumBands',50,"FrequencyScale","bark",'Normalization','none');



  
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
  [YPredicted,probs] = classify(trainedNet,features);
  
  out = probs;
  

  
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



end



