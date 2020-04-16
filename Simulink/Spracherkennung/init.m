fs = 16000;

load('commandNet.mat');
labels = trainedNet.Layers(end).Classes;
classificationRate = 20; % Rate?
adr = audioDeviceReader('SampleRate',fs,'SamplesPerFrame',floor(fs/classificationRate));
audioBuffer = dsp.AsyncBuffer(fs);
x = adr();
write(audioBuffer,x);
y = read(audioBuffer,fs,fs-adr.SamplesPerFrame);

%%  AFE
segmentDuration = 1;
frameDuration = 0.025;
hopDuration = 0.010;
numBands = 50;


segmentSamples = round(segmentDuration*fs);
frameSamples = round(frameDuration*fs);
hopSamples = round(hopDuration*fs);
overlapSamples = frameSamples - hopSamples;

FFTLength = 512;

   
afe = audioFeatureExtractor( ...
        'SampleRate',fs, ...
        'FFTLength',FFTLength, ...
        'Window',hann(frameSamples,'periodic'), ...
        'OverlapLength',overlapSamples, ...
        'barkSpectrum',true);
    
setExtractorParams(afe,'barkSpectrum','NumBands',numBands)

numSamples = size(x,1);

numToPadFront = floor( (segmentSamples - numSamples)/2 );
numToPadBack = ceil( (segmentSamples - numSamples)/2 );

xPadded = [zeros(numToPadFront,1,'like',y);y;zeros(numToPadBack,1,'like',y)];

% To extract audio features, call |extract|. The output is a Bark spectrum
% with time across rows.
features = extract(afe,xPadded);


% Determine the denormalization factor to apply.
unNorm = 2/(sum(afe.Window)^2);
features = features/unNorm;
epsil = 1e-6;

% Take the log. 
features = log10(features + epsil);










%%
afestr.Window = afe.Window;
afestr.OverlapLength = afe.OverlapLength;
afestr.SampleRate = afe.SampleRate;
afestr.FFTLength = afe.FFTLength;
afestr.SpectralDescriptorInput = afe.SpectralDescriptorInput;
afestr.barkSpectrum = afe.barkSpectrum;





save labels.mat labels 
save afe.mat afestr
save afecorr.mat afe





