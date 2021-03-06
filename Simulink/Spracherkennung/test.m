function out = test(in3) 
var = coder.load('labels.mat','labels');
afe = coder.load('afe.mat','afestr');
ynew = coder.load('y.mat','y');


SpectralDescriptorInput = 'linearSpectrum';
%WINDOW Analysis window
% Specify the analysis window as a numeric vector with more than three
% elements. The default is hamming(1024,"periodic").
%Window = hamming(1024,"periodic");
%OVERLAPLENGTH Number of samples overlapped between windows
% Specify the number of samples overlapped between analysis windows as a
% positive scalar less than the analysis window length. The default is 512.
%OverlapLength = 512;

%SAMPLERATE Sample rate (Hz)
% Specify sample rate as a positive scalar in Hz. The default is 44100 Hz.
%SampleRate = 44.1e3;
%FFTLENGTH FFT length
% Specify the DFT length as a positive scalar integer. The default of this
% property is [], which means that the DFT length is equal to the length
% of the Window property.
FFTLength = 512;
%SPECTRALDESCRIPTORINPUT Input to spectral descriptors
% Specify the input to the low-level spectral shape
% descriptors as "linearSpectrum", "melSpectrum", "barkSpectrum", or
% "erbSpectrum". The default is "linearSpectrum".
%SpectralDescriptorInput (1,:) char {mustBeMember(SpectralDescriptorInput,{'linearSpectrum','melSpectrum','barkSpectrum','erbSpectrum'})} = 'linearSpectrum';
%LINEARSPECTRUM Extract linear spectrum
% Extract the linear spectrum, specified as true or false. If
% linearSpectrum is true, then the object extracts the one-sided linear
% spectrum and appends it to the features returned. The default is false.
linearSpectrum = false;
%MELSPECTRUM Extract mel spectrum
% Extract the mel spectrum, specified as true or false. If melSpectrum is
% true, then the object extracts the mel spectrum and appends it to the
% features returned. The default is false.
%
% The mel filter bank is designed using designAuditoryFilterBank. You can
% configure the mel spectrum extraction using setExtractorParams.
%
% See also designAuditoryFilterBank, melSpectrogram, setExtractorParamel
melSpectrum = false;
%BARKSPECTRUM Extract Bark spectrum
% Extract the Bark spectrum, specified as true or false. If barkSpectrum is
% true, then the object extracts the Bark spectrum and appends it to the
% features returned. The default is false.
%
% The Bark filter bank is designed using designAuditoryFilterBank. You can
% configure the Bark spectrum extraction using setExtractorParams.
%
% See also designAuditoryFilterBank, setExtractorParams
barkSpectrum = true;
%ERBSPECTRUM Extract ERB spectrum
% Extract the ERB spectrum, specified as true or false. If erbSpectrum is
% true, then the object extracts the ERB spectrum and appends it to the
% features returned. The default is false.
%
% You can configure the ERB spectrum extraction using setExtractorParams.
%
% See also designAuditoryFilterBank, setExtractorParams
erbSpectrum = false;
%MFCC Extract MFCC
% Extract the mfcc, specified as true or false. If mfcc is true, then the
% object extracts the mfcc and appends it to the features returned. The
% default is false.
%
% You can configure the MFCC feature extraction using setExtractorParams.
%
% See also setExtractorParams
mfcc = false;
%MFCCDELTA Extract delta mfcc
% Extract the delta mfcc, specified as true or false. If mfccDelta is true,
% then the object extracts the delta mfcc and appends it to the features
% returned. The default is false.
%
% You can configure the MFCC feature extraction using setExtractorParams.
%
% See also setExtractorParams
mfccDelta = false;
%MFCCDELTADELTA Extract delta-delta MFCC
% Extract the delta-delta MFCC, specified as true or false. If
% mfccDeltaDelta is true, then the object extracts the delta-delta mfcc and
% appends it to the features returned. The default is false.
%
% You can configure the MFCC feature extraction using setExtractorParams.
%
% See also setExtractorParams
mfccDeltaDelta = false;
%GTCC Extract GTCC
% Extract the GTCC, specified as true or false. If gtcc is true, then the
% object extracts the GTCC and appends it to the features returned. The
% default is false.
%
% You can configure the GTCC feature extraction using setExtractorParams.
%
% See also setExtractorParams
gtcc = false;
%GTCCDELTA Extract delta GTCC
% Extract the delta GTCC, specified as true or false. If gtccDelta is true,
% then the object extracts the delta GTCC and appends it to the features
% returned. The default is false.
%
% You can configure the GTCC feature extraction using setExtractorParams.
%
% See also setExtractorParams
gtccDelta = false;
%GTCCDELTADELTA Extract delta-delta GTCC
% Extract the delta-delta GTCC, specified as true or false. If
% gtccDeltaDelta is true, then the object extracts the delta-delta gtcc and
% appends it to the features returned. The default is false.
%
% You can configure the GTCC feature extraction using setExtractorParams.
%
% See also setExtractorParams
gtccDeltaDelta = false;
%SPECTRALCENTROID Extract spectral centroid
% Extract the spectral centroid, specified as true or false. If
% spectralCentroid is true, then the object extracts the spectral centroid
% and appends it to the features returned. The default is false.
spectralCentroid = false;

%SPECTRALCREST Extract spectral crest
% Extract the spectral crest, specified as true or false. If spectralCrest
% is true, then the object extracts the spectral crest and appends it to
% the features returned. The default is false.
spectralCrest = false;
%SPECTRALDECREASE Extract spectral decrease
% Extract the spectral decrease, specified as true or false. If
% spectralDecrease is true, then the object extracts the spectral decrease and
% appends it to the features returned. The default is false.
spectralDecrease = false;
%SPECTRALENTROPY Extract spectral entropy
% Extract the spectral entropy, specified as true or false. If
% spectralEntropy is true, then the object extracts the spectral entropy
% and appends it to the features returned. The default is false.
spectralEntropy = false;
%SPECTRALFLATNESS Extract spectral flatness
% Extract the spectral flatness, specified as true or false. If
% spectralFlatness is true, then the object extracts the spectral flatness
% and appends it to the features returned. The default is false.
spectralFlatness = false;
%SPECTRALFLUX Extract spectral flux
% Extract the spectral flux, specified as true or false. If spectralFlux is
% true, then the object extracts the spectral flux and appends it to the
% features returned. The default is false.
%
% You can configure the spectral flux feature extraction using
% setExtractorParams.
%
% See also setExtractorParams
spectralFlux = false;
%SPECTRALKURTOSIS Extract spectral kurtosis
% Extract the spectral kurtosis, specified as true or false. If
% spectralKurtosis is true, then the object extracts the spectral kurtosis
% and appends it to the features returned. The default is false.
spectralKurtosis = false;
%SPECTRALROLLOFFPOINT Extract spectral rolloff point
% Extract the spectral rolloff point, specified as true or false. If
% spectralRolloffPoint is true, then the object extracts the spectral
% rolloff point and appends it to the features returned. The default is
% false.
%
% You can configure the spectral rolloff point feature extraction using
% setExtractorParams.
%
% See also setExtractorParams
spectralRolloffPoint = false;
%SPECTRALSKEWNESS Extract spectral skewness
% Extract the spectral skewness, specified as true or false. If
% spectralSkewness is true, then the object extracts the spectral skewness
% and appends it to the features returned. The default is false.
spectralSkewness = false;
%SPECTRALSLOPE Extract spectral slope
% Extract the spectral slope, specified as true or false. If spectralSlope
% is true, then the object extracts the spectral slope and appends it to
% the features returned. The default is false.
spectralSlope = false;
%SPECTRALSPREAD Extract spectral spread
% Extract the spectral spread, specified as true or false. If
% spectralSpread is true, then the object extracts the spectral spread and
% appends it to the features returned. The default is false.
spectralSpread = false;
%PITCH Extract pitch
% Extract the pitch, specified as true or false. If pitch is true, then the
% object extracts the pitch and appends it to the features returned. The
% default is false.
%
% You can configure the pitch feature extraction using setExtractorParams.
%
% See also setExtractorParams
pitch = false;
%HARMONICRATIO Extract harmonic ratio
% Extract the harmonic ratio, specified as true or false. If harmonicRatio
% is true, then the object extracts the harmonic ratio and appends it to
% the features returned. The default is false.
harmonicRatio = false;



% Flag for setup
pIsInitialized = true;

% Properties to hold user-specified feature extractor parameters
% pmfccUserSpecifiedParams                 = {};
% pgtccUserSpecifiedParams                 = {};
% pspectralFluxUserSpecifiedParams         = {};
% pspectralRolloffPointUserSpecifiedParams = {};
% plinearSpectrumUserSpecifiedParams       = {};
% pmelSpectrumUserSpecifiedParams          = {};
pbarkSpectrumUserSpecifiedParams         = false;
% perbSpectrumUserSpecifiedParams          = {};
% ppitchUserSpecifiedParams                = {};
plinearSpectrumType = "power";
pmelSpectrumType    = "power";
pbarkSpectrumType   = "power";
perbSpectrumType    = "power";

% Convenience properties to navigate the feature extraction pipeline
%pPipelineParameters= {};
pExtractorParameters= {};
pOutputIndex= {};
pOutputIndexReduced= {};
pUseSpectrum= false;
pUseHalfSpectrum= false;
pUsePowerSpectrum= false;
pUseMagnitudeSpectrum= false;
% pExtractSpectralDescriptor= {};
% pCalculateGTCC= {};
% pCalculateMFCC= {};
pCalculateBarkSpectrum= false;
pCalculateMelSpectrum= false;
pCalculateLinearSpectrum= false;
pCalculateERBSpectrum= false;
pFeaturesToExtract = struct('barkSpectrum',barkSpectrum);
%pFFTLength = getpFFTLength(str);
a = struct('pExtractSpectralDescriptor',false);
b = struct('pUseSpectrum',false);
c = struct('pUseHalfSpectrum',false);
PowerNormalizationFactor = 0;
MagnitudeNormalizationFactor = 0;
MelFilterBank = 0;
fs = 16000;

lb = struct('empty',0);
defaults1 = struct("NumBands",50,"FrequencyRange",[0,fs/2],"Normalization","bandwidth");

classificationRate = 20; % Rate?


%x = zeros(12800,1);


segmentDuration = 1;
frameDuration = 0.025;
hopDuration = 0.010;
numBands = 50;

segmentSamples = round(segmentDuration*fs);
frameSamples = round(frameDuration*fs);
hopSamples = round(hopDuration*fs);
overlapSamples = frameSamples - hopSamples;
pPipelineParameters = struct( ...
        "Window",        hann(frameSamples,'periodic'), ...
        "WindowLength",  numel(hann(frameSamples,'periodic')), ...
        "OverlapLength", overlapSamples, ...
        "HopLength",     numel(hann(frameSamples,'periodic')) - overlapSamples, ...
        "FFTLength",     FFTLength, ...
        "PowerNormalizationFactor",       PowerNormalizationFactor, ...
        "MagnitudeNormalizationFactor",       MagnitudeNormalizationFactor, ...
        'linearSpectrum',      lb, ...
        "SampleRate",    fs);

plinearSpectrumUserSpecifiedParams = struct( ...
        "a",1)

str.SampleRate = fs;
str.FFTLength = FFTLength;
str.Window=hann(frameSamples,'periodic');
str.OverlapLength=overlapSamples;
str.linearSpectrum=linearSpectrum;
str.melSpectrum=melSpectrum;
str.pFeaturesToExtract=pFeaturesToExtract;
str.pFFTLength=FFTLength;
str.spectralCentroid=spectralCentroid;
str.spectralCrest=spectralCrest;
str.spectralDecrease=spectralDecrease;
str.spectralEntropy=spectralEntropy;
str.spectralFlatness=spectralFlatness;
str.spectralFlux=spectralFlux;
str.spectralKurtosis=spectralKurtosis;
str.spectralRolloffPoint=spectralRolloffPoint;
str.spectralSkewness=spectralSkewness;
str.spectralSlope=spectralSlope;
str.spectralSpread=spectralSpread;
str.gtcc=gtcc;
str.gtccDelta=gtccDelta;
str.gtccDeltaDelta=gtccDeltaDelta;
str.mfcc=mfcc;
str.mfccDelta=mfccDelta;
str.mfccDeltaDelta=mfccDeltaDelta;
str.pbarkSpectrumType=pbarkSpectrumType;
str.erbSpectrum=erbSpectrum;
str.pUseHalfSpectrum=pUseHalfSpectrum;
str.pUseMagnitudeSpectrum=pUseMagnitudeSpectrum;
str.SpectralDescriptorInput=SpectralDescriptorInput;
str.pbarkSpectrumUserSpecifiedParams=pbarkSpectrumUserSpecifiedParams;
str.pitch=pitch;
str.harmonicRatio=harmonicRatio;
str.pIsInitialized=pIsInitialized;
str.pPipelineParameters=pPipelineParameters;
str.pUseSpectrum=b.pUseSpectrum;
str.pExtractSpectralDescriptor=a.pExtractSpectralDescriptor;
str.pCalculateGTCC=gtcc;
str.pCalculateMFCC=mfcc;
str.plinearSpectrumType=plinearSpectrumType;
str.pUsePowerSpectrum=pUsePowerSpectrum;
str.barkSpectrum=true;
str.pmelSpectrumType=pmelSpectrumType;
str.perbSpectrumType=perbSpectrumType;
str.pCalculateMelSpectrum=pCalculateMelSpectrum;
str.pCalculateERBSpectrum=pCalculateERBSpectrum;
str.pCalculateLinearSpectrum=pCalculateLinearSpectrum;
str.pCalculateBarkSpectrum=pCalculateBarkSpectrum;
str.plinearSpectrumUserSpecifiedParams=plinearSpectrumUserSpecifiedParams;
%str.params=params;

str.pPipelineParameters
%afe.afestr.pFFTLength = getpFFTLength(afe.afestr);

str = setup(str);
%afe.afestr = setExtractorParams(afe.afestr,'barkSpectrum','NumBands',numBands);

probBuffer = zeros([numel(var.labels),classificationRate/2]);
countThreshold = ceil(classificationRate*0.2);
probThreshold = 0.7;
adr = audioDeviceReader('SampleRate',fs,'SamplesPerFrame',floor(fs/classificationRate));
audioBuffer = dsp.AsyncBuffer(fs);

x1 = adr();
write(audioBuffer,x1);
y = read(audioBuffer,fs,fs-adr.SamplesPerFrame);
trainedNet = coder.loadDeepLearningNetwork('commandNet.mat');

numSamples = size(ynew.y,1);

numToPadFront = floor( (segmentSamples - numSamples)/2 );
numToPadBack = ceil( (segmentSamples - numSamples)/2 );



 % auslesen des Audiobuffers
    %YBuffer(1:classificationRate/2) = categorical({'background'});
    %YBuffer = categorical(1:10,1:10,{'background','background','background','background','background','background','background','background','background','background'})
    %YBuffer = categorical({'background'});
    %out = YBuffer;

%% extract audio features


xPadded = [zeros(numToPadFront,1,'like',ynew.y);ynew.y;zeros(numToPadBack,1,'like',ynew.y)];
% To extract audio features, call |extract|. The output is a Bark spectrum
% with time across rows.

%features = extract(str,xPadded);


% Determine the denormalization factor to apply.
%unNorm = 2/(sum(afe.afestr.Window)^2);
%features = features/unNorm;
epsil = 1e-6;

% Take the log. 
%spec = log10(features + epsil);
%%

%[YPredicted,probs] = classify(trainedNet,spec,'ExecutionEnvironment','cpu');

out =0;









function obj = audioFeatureExtractor(varargin)
    matlabshared.fusionutils.internal.setProperties(obj,length(varargin),varargin{:});
    setup(obj)
end
function obj1 = setExtractorParams(obj,propname,varargin)
%SETEXTRACTORPARAMS Set nondefault parameter values of feature extractor
% setExtractorParams(aFE,FEATURENAME,PARAMS) specifies parameters used to
% extract FEATURENAME. Specify the feature name as a string or character
% vector. Specify PARAMS as comma-separated name-value pairs or as a
% struct.
%
% setExtractorParams(aFE,FEATURENAME) returns the parameters used to
% extract FEATURENAME to default values.
%
%
% % EXAMPLE 1: 
% % Extract pitch using the LHS method.
%   [audioIn,fs] = audioread("Counting-16-44p1-mono-15secs.wav");
%
%   aFE = audioFeatureExtractor("SampleRate",fs,"pitch",true);
%   setExtractorParams(aFE,"pitch","Method","LHS");
%
%   features = extract(aFE,audioIn);
%
%
% % EXAMPLE 2:
% % Extract the spectral rolloff point with a threshold of 0.8 and a
% % 20-band mel spectrum.
%   [audioIn,fs] = audioread("Counting-16-44p1-mono-15secs.wav");
%
%   aFE = audioFeatureExtractor("SampleRate",fs,"melSpectrum",true, ...
%                               "spectralRolloffPoint",true);
%   [~,params] = info(aFE);
%   params.melSpectrum.NumBands = 20;
%   params.spectralRolloffPoint.Threshold = 0.8;
%   setExtractorParams(aFE,"melSpectrum",params.melSpectrum);
%   setExtractorParams(aFE,"spectralRolloffPoint", ...
%       params.spectralRolloffPoint);
%
%   features = extract(aFE,audioIn);
%
% See also info
    validatestring(propname,["mfcc","gtcc", ...
        "spectralFlux","spectralRolloffPoint", ...
        "melSpectrum","barkSpectrum","linearSpectrum","erbSpectrum", ...
        "pitch", "harmonicRatio"],"setExtractorParams");
    
    winLength = numel(obj.Window);
    x = ones(winLength,1);
    fs = obj.SampleRate;
    
    % If input was a struct, unpack it to a name-value cell
    numin = numel(varargin);
    if isscalar([varargin{:}])
        if isstruct(varargin{:})
            varargin = obj.Struct2NameValueCell(varargin{:});
            numin = numel(varargin);
        end
    end
    
    defaults = getFeatureExtractorDefaultParams(obj,propname);
    params = matlabshared.fusionutils.internal.setProperties(defaults, numin, varargin{:});
    
    switch propname
        case "mfcc"
            nv = obj.Struct2NameValueCell(params);
            mfcc(x,fs,"WindowLength",winLength, ...
                      "OverlapLength",obj.OverlapLength, ...
                      "FFTLength",obj.pFFTLength, ...
                      nv{:});
            
            obj.pmfccUserSpecifiedParams = struct(varargin{:});
            
        case "gtcc"
            nv = obj.Struct2NameValueCell(params);
            gtcc(x,fs,"WindowLength",winLength, ...
                      "OverlapLength",obj.OverlapLength, ...
                      "FFTLength",obj.pFFTLength, ...
                      nv{:});
                  
            obj.pgtccUserSpecifiedParams = struct(varargin{:});
            
        case "spectralFlux"
            nv = obj.Struct2NameValueCell(params);
            spectralFlux(x,fs,"Window",obj.Window, ...
                              "OverlapLength",obj.OverlapLength, ...
                              "FFTLength",obj.pFFTLength, ...
                              nv{:});
                          
            obj.pspectralFluxUserSpecifiedParams = struct(varargin{:});
            
        case "spectralRolloffPoint"
            nv = obj.Struct2NameValueCell(params);
            spectralRolloffPoint(x,fs,"Window",obj.Window, ...
                                      "OverlapLength",obj.OverlapLength, ...
                                      "FFTLength",obj.pFFTLength, ...
                                      nv{:});
                                  
            obj.pspectralRolloffPointUserSpecifiedParams = struct(varargin{:});
            
        case "linearSpectrum"
            validatestring(params.SpectrumType,["power","magnitude"],"setExtractorParams");
            obj.plinearSpectrumType = params.SpectrumType;
            params = rmfield(params,"SpectrumType");
            
            validateattributes(params.FrequencyRange,{'single','double'}, ...
                {"nonempty","increasing","nonnegative","row","ncols",2,"real"}, ...
                "linearSpectrum","FrequencyRange")
            validateattributes(params.FrequencyRange(2),{'single','double'}, ...
                {'<=',obj.SampleRate/2}, ...
                'linearSpectrum','FrequencyRange')
            
            obj.plinearSpectrumUserSpecifiedParams = struct(varargin{:});
            
        case "melSpectrum"
            validatestring(params.SpectrumType,["power","magnitude"],"setExtractorParams");
            obj.pmelSpectrumType = params.SpectrumType;
            params = rmfield(params,"SpectrumType");
            
            nv = obj.Struct2NameValueCell(params);
            designAuditoryFilterBank(fs,"FFTLength",obj.pFFTLength, ...
                                        "FrequencyScale","mel", ...
                                        nv{:});
            
            obj.pmelSpectrumUserSpecifiedParams = struct(varargin{:});
            
        case "barkSpectrum"
            validatestring(params.SpectrumType,["power","magnitude"],"setExtractorParams");
            obj.pbarkSpectrumType = params.SpectrumType;
            params = rmfield(params,"SpectrumType");
            
            nv = Struct2NameValueCell(params);
            obj.params = Struct2NameValueCell(params);
            designAuditoryFilterBank(fs,"FFTLength",obj.pFFTLength, ...
                                        "FrequencyScale","bark", ...
                                        nv{:});
            
            obj.pbarkSpectrumUserSpecifiedParams = struct(varargin{:});
            
        case "erbSpectrum"
            validatestring(params.SpectrumType,["power","magnitude"],"setExtractorParams");
            obj.perbSpectrumType = params.SpectrumType;
            params = rmfield(params,"SpectrumType");
            
            nv = obj.Struct2NameValueCell(params);
            designAuditoryFilterBank(fs,"FFTLength",obj.pFFTLength, ...
                                        "FrequencyScale","erb", ...
                                         nv{:});
            
            obj.perbSpectrumUserSpecifiedParams = struct(varargin{:});
       
        case "pitch"
            nv = obj.Struct2NameValueCell(params);
            pitch(x,fs,"WindowLength",numel(obj.Window), ...
                       "OverlapLength",obj.OverlapLength, ...
                       nv{:});
            
            obj.ppitchUserSpecifiedParams = struct(varargin{:});
    end
    obj.pIsInitialized = false;
    disp('test')
    obj.pOutputIndex
    obj1=obj;
end
function featureVector = extract(obj,x)
%EXTRACT Extract features
% features = extract(aFE,x) returns an array or cell array containing
% features of the audio input, x. The output depends on properties of aFE.
%
% % EXAMPLE: 
% % Extract the spectral centroid, spectral kurtosis, and pitch of an 
% % audio signal. Plot their normalized values over time.
%   [audioIn,fs] = audioread("Counting-16-44p1-mono-15secs.wav");
% 
%    aFE = audioFeatureExtractor("SampleRate",fs, ...
%                                "spectralCentroid",true, ...
%                                "spectralKurtosis",true, ...
%                                "pitch",true);
%
%    features = extract(aFE,audioIn);
%    features = (features - mean(features,1))./std(features,[],1);
%    idx = info(aFE);
%
%    subplot(2,1,1)
%    t = linspace(0,15,size(audioIn,1));
%    plot(t,audioIn)
%
%    subplot(2,1,2)
%    t = linspace(0,15,size(features,1));
%    plot(t,features(:,idx.spectralCentroid), ...
%         t,features(:,idx.spectralKurtosis), ...
%         t,features(:,idx.pitch));
%    legend("Spectral Centroid","Spectral Kurtosis","Pitch");
%

%#ok<*CPROPLC>

validateattributes(x,{'single','double'},{'2d','real'},'extract','audioIn')

if ~obj.pIsInitialized
    setup(obj)
end

config = obj.pPipelineParameters;
outputIndex = obj.pOutputIndexReduced;
[numSamp,numChan] = size(x);

if numSamp < config.WindowLength
    featureVector = zeros(0,'like',x);
else
xb = audio.internal.buffer(x,config.WindowLength,config.HopLength);

numHops = size(xb,2)/numChan;

featureVector = zeros(numHops,config.FeaturesPerHop,numChan,'like',x);

xbw = bsxfun(@times,xb,config.Window);
if obj.pUseSpectrum
    Y = fft(xbw,config.FFTLength,1);
    if isreal(Y)
        Y = complex(Y);
    end
    if obj.pUseHalfSpectrum
        Z = Y(config.OneSidedSpectrumBins,:);
    else
        Z = Y;
    end
    if obj.pUsePowerSpectrum
        Zpower = Z.*conj(Z);
        if obj.pUseMagnitudeSpectrum
            Zmagnitude = sqrt(Zpower);
        end
    elseif obj.pUseMagnitudeSpectrum
        Zmagnitude = abs(Z);
    end
end

if obj.pCalculateLinearSpectrum
    if strcmpi(obj.plinearSpectrumType,"Power")
        linSpec = Zpower(config.linearSpectrum.FrequencyBins,:,:)*config.PowerNormalizationFactor;
    else
        linSpec = Zmagnitude(config.linearSpectrum.FrequencyBins,:,:)*config.MagnitudeNormalizationFactor;
    end
    if config.linearSpectrum.FrequencyBins(1)==1
        linSpec(1,:) = 0.5*linSpec(1,:);
    end
    if config.linearSpectrum.FrequencyBins(end) == floor(config.FFTLength/2+1) && rem(config.FFTLength,2)==0
        linSpec(end,:) = 0.5*linSpec(end,:);
    end
    
    linSpec = reshape(linSpec,[],numHops,numChan);
    if obj.linearSpectrum
        featureVector(:,outputIndex.linearSpectrum,:) = permute(linSpec,[2,1,3]);
    end
end

if obj.pCalculateMelSpectrum
    if strcmpi(obj.pmelSpectrumType,"Power")
        melFilterBankInput = Zpower;
    else
        melFilterBankInput = Zmagnitude;
    end
    melSpecMat = config.melSpectrum.FilterBank*melFilterBankInput;
    melSpec = reshape(melSpecMat,[],numHops,numChan);
    if obj.melSpectrum
        featureVector(:,outputIndex.melSpectrum,:) = permute(melSpec,[2,1,3]);
    end
end

if obj.pCalculateBarkSpectrum
    if strcmpi(obj.pbarkSpectrumType,"Power")
        barkFilterBankInput = Zpower;
    else
        barkFilterBankInput = Zmagnitude;
    end
    barkSpec = config.barkSpectrum.FilterBank*barkFilterBankInput;
    barkSpec = reshape(barkSpec,[],numHops,numChan);
  
    if obj.barkSpectrum
        featureVector(:,outputIndex.barkSpectrum,:) = permute(barkSpec,[2,1,3]);
    end
end

if obj.pCalculateERBSpectrum
    if strcmpi(obj.perbSpectrumType,"Power")
        erbFilterBankInput = Zpower;
    else
        erbFilterBankInput = Zmagnitude;
    end
    erbSpecMat = config.erbSpectrum.FilterBank*erbFilterBankInput;
    erbSpec = reshape(erbSpecMat,[],numHops,numChan);
    if obj.erbSpectrum
        featureVector(:,outputIndex.erbSpectrum,:) = permute(erbSpec,[2,1,3]);
    end
end

if obj.pCalculateMFCC
    if strcmpi(config.mfcc.Parameters.Rectification,'log')
        melSpecMat(melSpecMat==0) = realmin(class(melSpecMat));
        a = config.mfcc.DCTmatrix * log10(melSpecMat);
    else
        a = config.mfcc.DCTmatrix * melSpecMat.^(1/3) ;
    end
    a = reshape(a,config.mfcc.Parameters.NumCoeffs,[],numChan);
    a = permute(a,[2,1,3]);
    if obj.mfcc
        featureVector(:,outputIndex.mfcc,:) = a;
    end
    if obj.mfccDelta || obj.mfccDeltaDelta
        b = audio.internal.computeDelta(a,config.mfcc.Parameters.DeltaWindowLength);
        if obj.mfccDelta
            featureVector(:,outputIndex.mfccDelta,:) = b;
        end
        if obj.mfccDeltaDelta
            featureVector(:,outputIndex.mfccDeltaDelta,:) = ...
                audio.internal.computeDelta(b,config.mfcc.Parameters.DeltaWindowLength);
        end
    end
end

if obj.pCalculateGTCC
    if strcmpi(config.gtcc.Parameters.Rectification,'log')
        erbSpecMat(erbSpecMat==0) = realmin(class(erbSpecMat));
        a = config.gtcc.DCTmatrix * log10(erbSpecMat);
    else
        a = config.gtcc.DCTmatrix * erbSpecMat.^(1/3);
    end
    a = reshape(a,config.gtcc.Parameters.NumCoeffs,[],numChan);
    a = permute(a,[2,1,3]);
    if obj.gtcc
        featureVector(:,outputIndex.gtcc,:) = a;
    end
    if obj.gtccDelta || obj.gtccDeltaDelta
        b = audio.internal.computeDelta(a,config.gtcc.Parameters.DeltaWindowLength);
        if obj.gtccDelta
            featureVector(:,outputIndex.gtccDelta,:) = b;
        end
        if obj.gtccDeltaDelta
            featureVector(:,outputIndex.gtccDeltaDelta,:) = ...
                audio.internal.computeDelta(b,config.gtcc.Parameters.DeltaWindowLength);
        end
    end
end

if obj.pExtractSpectralDescriptor
    switch obj.SpectralDescriptorInput
        case 'melSpectrum'
            S = melSpec;
        case 'barkSpectrum'
            S = barkSpec;
        case 'erbSpectrum'
            S = erbSpec;
        case 'linearSpectrum'
            S = linSpec;
    end
    if obj.spectralKurtosis
        [kurtosis,spread,centroid] = spectralKurtosis(S,config.SpectralDescriptorInput.FrequencyVector);
        featureVector(:,outputIndex.spectralKurtosis,:) = kurtosis;
    end
    if obj.spectralSkewness
        [skewness,spread,centroid] = spectralSkewness(S,config.SpectralDescriptorInput.FrequencyVector);
        featureVector(:,outputIndex.spectralSkewness,:) = skewness;
    end
    if obj.spectralSpread
        if (obj.spectralKurtosis || obj.spectralSkewness)
            featureVector(:,outputIndex.spectralSpread,:) = spread;
        else
            [spread, centroid] = spectralSpread(S,config.SpectralDescriptorInput.FrequencyVector);
            featureVector(:,outputIndex.spectralSpread,:) = spread;
        end
    end
    if obj.spectralCentroid
        if (obj.spectralKurtosis || obj.spectralSkewness || obj.spectralSpread)
            featureVector(:,outputIndex.spectralCentroid,:) = centroid;
        else
            featureVector(:,outputIndex.spectralCentroid,:) = spectralCentroid(S,config.SpectralDescriptorInput.FrequencyVector);
        end
    end
    if obj.spectralCrest
        featureVector(:,outputIndex.spectralCrest,:) = ...
            spectralCrest(S,config.SpectralDescriptorInput.FrequencyVector);
    end
    if obj.spectralDecrease
        featureVector(:,outputIndex.spectralDecrease,:) = ...
            spectralDecrease(S,config.SpectralDescriptorInput.FrequencyVector);
    end
    if obj.spectralEntropy
        featureVector(:,outputIndex.spectralEntropy,:) = ...
            spectralEntropy(S,config.SpectralDescriptorInput.FrequencyVector);
    end
    if obj.spectralFlatness
        featureVector(:,outputIndex.spectralFlatness,:) = ...
            spectralFlatness(S,config.SpectralDescriptorInput.FrequencyVector);
    end
    if obj.spectralFlux
        featureVector(:,outputIndex.spectralFlux,:) = ...
            spectralFlux(S,config.SpectralDescriptorInput.FrequencyVector,config.spectralFlux.Parameters{:});
    end
    if obj.spectralRolloffPoint
        featureVector(:,outputIndex.spectralRolloffPoint,:) = ...
            spectralRolloffPoint(S,config.SpectralDescriptorInput.FrequencyVector,config.spectralRolloffPoint.Parameters{:});
    end
    if obj.spectralSlope
        featureVector(:,outputIndex.spectralSlope,:) = ...
            spectralSlope(S,config.SpectralDescriptorInput.FrequencyVector);
    end
end

if obj.pitch
    featureVector(:,outputIndex.pitch,:) = ...
        pitch(x,config.SampleRate,'WindowLength',config.WindowLength,'OverlapLength',config.OverlapLength,config.pitch.Parameters{:});
end

if obj.harmonicRatio
    featureVector(:,outputIndex.harmonicRatio,:) = ...
        harmonicRatio(x,config.SampleRate,'Window',config.Window,'OverlapLength',config.OverlapLength);
end
end
end
function [idx,params] = info(obj,varargin)
%INFO Output mapping and individual feature extractor parameters
% IDX = info(aFE) returns a struct with field names corresponding to
% enabled feature extractors. The field values correspond to the column
% indices that the extracted features occupy in the output from extract.
%
% IDX = info(aFE,"all") returns a struct with field names corresponding to
% all available feature extractors. If the feature extractor is disabled,
% the field value is empty.
%
% [IDX, PARAMS] = info(...) returns a second struct, PARAMS. The field
% names of PARAMS correspond to feature extractors with settable
% parameters. You can set parameters using setExtractorParams.
%
%
% % EXAMPLE 1:
% % Extract the mel spectrum, mel spectral centroid, and mel spectral 
% % kurtosis from a random audio signal. Use info to determine which 
% % columns of the output correspond to which feature, and then plot the 
% % features separately.
%
%   aFE = audioFeatureExtractor("melSpectrum",true, ...
%             "SpectralDescriptorInput","melSpectrum", ...
%             "spectralCentroid",true, ...
%             "spectralKurtosis",true);
%
%   features = extract(aFE,2*rand(44.1e3,1)-1);
%   idx = info(aFE);
%   
%   figure
%   surf(features(:,idx.melSpectrum),'EdgeColor','none');
%   title('Mel Spectrum')
%   figure
%   plot(features(:,idx.spectralCentroid))
%   title('Mel Spectral Centroid')
%   figure
%   plot(features(:,idx.spectralKurtosis))
%   title('Mel Spectral Kurtosis')
%
%
% % EXAMPLE 2: 
% % Extract a 20-band magnitude ERB spectrum from a random signal.
%
%   aFE = audioFeatureExtractor('erbSpectrum',true);
%
%   [~,params] = info(aFE);
%   erbParams = params.erbSpectrum;
%   erbParams.SpectrumType = 'magnitude';
%   erbParams.NumBands = 20;
%   setExtractorParams(aFE,'erbSpectrum',erbParams);
%
%   features = extract(aFE,2*rand(1e5,1)-1);
%
%
% See also setExtractorParams

displayAll = false;
if nargin>1
    validatestring(varargin{:},"all","info","flag",2);
    displayAll = true;
end

if ~obj.pIsInitialized
    setup(obj)
end

if displayAll
    idxStruct = obj.pOutputIndex;
else
    idxStruct = obj.pOutputIndexReduced;
end

if nargout == 0
    % no output variable, display the output mappings
    featureNames = fieldnames(idxStruct);
    if numel(featureNames) > 0
        fprintf('   %s\n\n',getString(message('audio:audioFeatureExtractor:OutputMapping')));
        rightJustified = cellstr(strjust(char(featureNames),'right'));
        for kdx = 1:numel(featureNames)
            val = idxStruct.(featureNames{kdx});
            if isempty(val)
                fprintf('      %s: <missing>\n',rightJustified{kdx});
            elseif isscalar(val)
                fprintf('      %s: %d\n',rightJustified{kdx},val);
            else
                fprintf('      %s: %d:%d\n',rightJustified{kdx},val(1),val(end));
            end
        end
    end
elseif nargout == 1
    idx = idxStruct;
elseif nargout == 2
    idx = idxStruct;
    params = struct( ...
        "linearSpectrum",       getFeatureExtractorParams(obj,"linearSpectrum","struct"), ...
        "melSpectrum",          getFeatureExtractorParams(obj,"melSpectrum","struct"), ...
        "barkSpectrum",         getFeatureExtractorParams(obj,"barkSpectrum","struct"), ...
        "erbSpectrum",          getFeatureExtractorParams(obj,"erbSpectrum","struct"), ...
        "mfcc",                 getFeatureExtractorParams(obj,"mfcc","struct"), ...
        "gtcc",                 getFeatureExtractorParams(obj,"gtcc","struct"), ...
        "spectralFlux",         getFeatureExtractorParams(obj,"spectralFlux","struct"), ...
        "spectralRolloffPoint", getFeatureExtractorParams(obj,"spectralRolloffPoint","struct"), ...
        "pitch",                getFeatureExtractorParams(obj,"pitch","struct") ...
        );
    
    if ~displayAll
        if ~obj.pCalculateLinearSpectrum
            params = rmfield(params,'linearSpectrum');
        end
        if ~obj.pCalculateMelSpectrum
            params = rmfield(params,'melSpectrum');
        end
        if ~obj.pCalculateBarkSpectrum
            params = rmfield(params,'barkSpectrum');
        end
        if ~obj.pCalculateERBSpectrum
            params = rmfield(params,'erbSpectrum');
        end
        if ~obj.pCalculateMFCC
            params = rmfield(params,'mfcc');
        end
        if ~obj.pCalculateGTCC
            params = rmfield(params,'gtcc');
        end
        if ~obj.pitch
            params = rmfield(params,'pitch');
        end
        if ~obj.spectralFlux
            params = rmfield(params,'spectralFlux');
        end
        if ~obj.spectralRolloffPoint
            params = rmfield(params,'spectralRolloffPoint');
        end
    end
end
end

function obj1 = setup(obj)
    % Validate FFT length

    coder.internal.errorIf(obj.pFFTLength < numel(obj.Window), ...
        'dsp:system:STFT:FFTLengthTooShort')
    
    % Validate overlap length
    coder.internal.errorIf(obj.OverlapLength >= numel(obj.Window), ...
        'audio:audioFeatureExtractor:OverlapTooLong')
    
    % Save parameters in the extract loop to struct
    obj.pPipelineParameters = struct( ...
        "Window",        obj.Window, ...
        "WindowLength",  numel(obj.Window), ...
        "OverlapLength", obj.OverlapLength, ...
        "HopLength",     numel(obj.Window) - obj.OverlapLength, ...
        "FFTLength",     obj.pFFTLength, ...
        "PowerNormalizationFactor",       PowerNormalizationFactor, ...
        "MagnitudeNormalizationFactor",       MagnitudeNormalizationFactor, ...
        'linearSpectrum',      lb, ...
        "SampleRate",    obj.SampleRate);

     obj.pExtractSpectralDescriptor = obj.spectralCentroid || obj.spectralCrest || ...
         obj.spectralDecrease || obj.spectralEntropy || obj.spectralFlatness || ...
         obj.spectralFlux || obj.spectralKurtosis || obj.spectralRolloffPoint || ...
         obj.spectralSkewness || obj.spectralSlope || obj.spectralSpread;
     
     obj.pUseSpectrum = obj.pExtractSpectralDescriptor || ...
         obj.melSpectrum || obj.barkSpectrum || obj.erbSpectrum || obj.linearSpectrum || ...
         obj.mfcc || obj.mfccDelta || obj.mfccDeltaDelta || ...
         obj.gtcc || obj.gtccDelta || obj.gtccDeltaDelta;
     
     obj.pUseHalfSpectrum = obj.pExtractSpectralDescriptor;

     obj.pCalculateGTCC = obj.gtcc || obj.gtccDelta || obj.gtccDeltaDelta;
     obj.pCalculateMFCC = obj.mfcc || obj.mfccDelta || obj.mfccDeltaDelta;
     
     if obj.linearSpectrum || (obj.pExtractSpectralDescriptor && isequal('linearSpectrum',obj.SpectralDescriptorInput))
         if strcmpi(obj.plinearSpectrumType,"Magnitude")
             obj.pUseMagnitudeSpectrum = true;
             else
             obj.pUsePowerSpectrum = true;
         end
     end

     if obj.melSpectrum || obj.pCalculateMFCC || (obj.pExtractSpectralDescriptor && isequal('melSpectrum',obj.SpectralDescriptorInput))
         if strcmpi(obj.pmelSpectrumType,"Magnitude")
             obj.pUseMagnitudeSpectrum = true;
         else
             obj.pUsePowerSpectrum = true;
         end
     end
     if obj.barkSpectrum || (obj.pExtractSpectralDescriptor && isequal('barkSpectrum',obj.SpectralDescriptorInput))
         if strcmpi(obj.pbarkSpectrumType,"Magnitude")
             obj.pUseMagnitudeSpectrum = true;
         else
             obj.pUsePowerSpectrum = true;
         end
     end
     if obj.erbSpectrum || obj.pCalculateGTCC || (obj.pExtractSpectralDescriptor && isequal('erbSpectrum',obj.SpectralDescriptorInput))
         if strcmpi(obj.perbSpectrumType,"Magnitude")
             obj.pUseMagnitudeSpectrum = true;
         else
             obj.pUsePowerSpectrum = true;
         end
     end
     if obj.pUsePowerSpectrum
         obj.pPipelineParameters.PowerNormalizationFactor = 2/(sum(obj.Window)^2);
     end
     if obj.pUseMagnitudeSpectrum
         obj.pPipelineParameters.MagnitudeNormalizationFactor = 2/sum(obj.Window);
     end
     
     obj.pCalculateGTCC = obj.gtcc || obj.gtccDelta || obj.gtccDeltaDelta;
     obj.pCalculateMFCC = obj.mfcc || obj.mfccDelta || obj.mfccDeltaDelta;
     
     obj.pCalculateBarkSpectrum   = obj.barkSpectrum   || (strcmpi(obj.SpectralDescriptorInput,"barkSpectrum")   && obj.pExtractSpectralDescriptor);
     obj.pCalculateMelSpectrum    = obj.melSpectrum    || (strcmpi(obj.SpectralDescriptorInput,"melSpectrum")    && obj.pExtractSpectralDescriptor) || obj.pCalculateMFCC;
     obj.pCalculateLinearSpectrum = obj.linearSpectrum || (strcmpi(obj.SpectralDescriptorInput,"linearSpectrum") && obj.pExtractSpectralDescriptor);
     obj.pCalculateERBSpectrum    = obj.erbSpectrum    || (strcmpi(obj.SpectralDescriptorInput,"erbSpectrum")    && obj.pExtractSpectralDescriptor) || obj.pCalculateGTCC;
     
%      if obj.pCalculateLinearSpectrum
%          params  = getFeatureExtractorParams(obj,"linearSpectrum","struct");
%          range   = params.FrequencyRange;
%          binHigh = floor(range(2)*obj.pFFTLength/obj.SampleRate + 1);
%          binLow  = ceil(range(1)*obj.pFFTLength/obj.SampleRate + 1);
%          bins    = binLow:binHigh;
%          obj.pPipelineParameters.linearSpectrum.FrequencyBins = bins;
%          
%          w = (obj.SampleRate/obj.pFFTLength)*(bins-1);
%          if rem(obj.pFFTLength,2) && binHigh == floor(obj.pFFTLength/2 + 1)
%              w(end) = obj.SampleRate*(obj.pFFTLength-1)/(2*obj.pFFTLength);
%          end
%          LinearFc = w(:);
%      end
%      if obj.pCalculateMelSpectrum
%          params = getFeatureExtractorParams(obj,"melSpectrum","struct");
%          params = obj.Struct2NameValueCell(rmfield(params,"SpectrumType"));
%          [fb,MelFilterBankFc] = designAuditoryFilterBank(obj.SampleRate, ...
%                                   "FrequencyScale","mel", ...
%                                   "FFTLength",obj.pFFTLength, ...
%                                   params{:});
%          if strcmpi(obj.pmelSpectrumType,"Power")
%              fb = fb*obj.pPipelineParameters.PowerNormalizationFactor;
%          else
%              fb = fb*obj.pPipelineParameters.MagnitudeNormalizationFactor;
%          end
%          fb(:,1) = 0.5*fb(:,1);
%          if rem(obj.pFFTLength,2) == 0
%              fb(:,end) = 0.5*fb(:,end);
%          end
%          if ~obj.pUseHalfSpectrum
%              fb = [fb,zeros(size(fb,1),ceil(obj.pFFTLength/2)-1)];
%          end
%          obj.pPipelineParameters.melSpectrum.FilterBank = fb;
%      end
     if obj.pCalculateBarkSpectrum
         params = MergeStructs(defaults1,obj.pbarkSpectrumUserSpecifiedParams);
         params
         params = Struct2NameValueCell(params);
         params
         %obj.params = params;
         [fb,BarkFilterBankFc] = designAuditoryFilterBank(obj.SampleRate, ...
                                   "FrequencyScale","bark", ...
                                   "FFTLength",obj.pFFTLength, ...
                                   params{:});
         if strcmpi(obj.pbarkSpectrumType,"Power")
             fb = fb*obj.pPipelineParameters.PowerNormalizationFactor;
         else
             fb = fb*obj.pPipelineParameters.MagnitudeNormalizationFactor;
         end
         fb(:,1) = 0.5*fb(:,1);
         if rem(obj.pFFTLength,2) == 0
             fb(:,end) = 0.5*fb(:,end);
         end
         if ~obj.pUseHalfSpectrum
             fb = [fb,zeros(size(fb,1),ceil(obj.pFFTLength/2)-1)];
         end
         obj.pPipelineParameters.barkSpectrum.FilterBank = fb;
     end
     if obj.pCalculateERBSpectrum
         params = getFeatureExtractorParams(obj,"erbSpectrum","struct");
         params = obj.Struct2NameValueCell(rmfield(params,"SpectrumType"));
         [fb,ERBFilterBankFc] = designAuditoryFilterBank(obj.SampleRate, ...
                                  "FrequencyScale","erb", ...
                                  "FFTLength",obj.pFFTLength, ...
                                  params{:});
         if strcmpi(obj.perbSpectrumType,"Power")
             fb = fb*obj.pPipelineParameters.PowerNormalizationFactor;
         else
             fb = fb*obj.pPipelineParameters.MagnitudeNormalizationFactor;
         end
         fb(:,1) = 0.5*fb(:,1);
         if rem(obj.pFFTLength,2) == 0
             fb(:,end) = 0.5*fb(:,end);
         end
         if ~obj.pUseHalfSpectrum
             fb = [fb,zeros(size(fb,1),ceil(obj.pFFTLength/2)-1)];
         end
         obj.pPipelineParameters.erbSpectrum.FilterBank = fb;
     end
     
     if obj.pExtractSpectralDescriptor
         switch obj.SpectralDescriptorInput
             case "linearSpectrum"
                 obj.pPipelineParameters.SpectralDescriptorInput.FrequencyVector = LinearFc;
             case "melSpectrum"
                 obj.pPipelineParameters.SpectralDescriptorInput.FrequencyVector = MelFilterBankFc;
             case "barkSpectrum"
                 obj.pPipelineParameters.SpectralDescriptorInput.FrequencyVector = BarkFilterBankFc;
             case "erbSpectrum"
                 obj.pPipelineParameters.SpectralDescriptorInput.FrequencyVector = ERBFilterBankFc;
         end
     end
     
     if obj.pCalculateMFCC
         obj.pPipelineParameters.mfcc.Parameters = getFeatureExtractorParams(obj,"mfcc","struct");
         melSpectrumParams = getFeatureExtractorParams(obj,"melSpectrum","struct");
         obj.pPipelineParameters.mfcc.DCTmatrix = audio.internal.createDCTmatrix( ...
             obj.pPipelineParameters.mfcc.Parameters.NumCoeffs, ...
             melSpectrumParams.NumBands,'double');
     end
     if obj.pCalculateGTCC
         obj.pPipelineParameters.gtcc.Parameters = getFeatureExtractorParams(obj,"gtcc","struct");
         erbSpectrumParams = getFeatureExtractorParams(obj,"erbSpectrum","struct");
         obj.pPipelineParameters.gtcc.DCTmatrix = audio.internal.createDCTmatrix( ...
             obj.pPipelineParameters.gtcc.Parameters.NumCoeffs, ...
             erbSpectrumParams.NumBands,'double');
     end
     if obj.spectralFlux
         obj.pPipelineParameters.spectralFlux.Parameters = getFeatureExtractorParams(obj,"spectralFlux","cell");
     end
     if obj.spectralRolloffPoint
         obj.pPipelineParameters.spectralRolloffPoint.Parameters = getFeatureExtractorParams(obj,"spectralRolloffPoint","cell");
     end
     if obj.pitch
         obj.pPipelineParameters.pitch.Parameters = getFeatureExtractorParams(obj,"pitch","cell");
     end
     
     if rem(obj.pFFTLength,2)
         obj.pPipelineParameters.OneSidedSpectrumBins = 1:ceil(obj.pFFTLength/2);
     else
         obj.pPipelineParameters.OneSidedSpectrumBins = 1:((obj.pFFTLength/2) + 1);
     end

     fte = obj.pFeaturesToExtract;
     numFeaturesPerExtractor = updateNumFeaturePerExtractor(obj,fte);
     
     totalFeatures = struct2cell(numFeaturesPerExtractor);
     obj.pPipelineParameters.FeaturesPerHop = sum([totalFeatures{:}],'all');
     
     % Update the Output Index
     idx = 1;
     fn = fieldnames(fte);
     numFeatureExtractors = numel(fn);
     obj.pOutputIndex = fte;
     
     for i = 1:numFeatureExtractors
         obj.pOutputIndex.(fn{i}) = idx:(idx+numFeaturesPerExtractor.(fn{i})-1);
         idx = idx + numFeaturesPerExtractor.(fn{i});
     end
     
     obj.pOutputIndexReduced  = reduceStruct(obj.pOutputIndex);
     obj.pIsInitialized = true;
     obj1 = obj;
end
function numFeatures = updateNumFeaturePerExtractor(obj,fte)
%updateNumFeaturePerExtractor mirrors the extract method. This method is
%called by setup to determine the number of features returned by each
%feature extractor, and to ensure the configuration won't error once
%deployed on a database.

config = obj.pPipelineParameters;
numFeatures = fte;
x = ones(numel(obj.Window),1);

xb = audio.internal.buffer(x,config.WindowLength,config.HopLength);
numChan = size(x,2);
numHops = size(xb,2)/numChan;

xbw = bsxfun(@times,xb,obj.Window);
if obj.pUseSpectrum
    Y = fft(xbw,config.FFTLength,1);
    if isreal(Y)
        Y = complex(Y);
    end
    if obj.pUseHalfSpectrum
        Z = Y(config.OneSidedSpectrumBins,:);
    else
        Z = Y;
    end
    if obj.pUsePowerSpectrum
        Zpower = Z.*conj(Z);
        if obj.pUseMagnitudeSpectrum
            Zmagnitude = sqrt(Zpower);
        end
    elseif obj.pUseMagnitudeSpectrum
        Zmagnitude = abs(Z);
    end
end

if obj.pCalculateLinearSpectrum
    if strcmpi(obj.plinearSpectrumType,"Power")
        linSpec = Zpower(config.linearSpectrum.FrequencyBins,:,:)*config.PowerNormalizationFactor;
    else
        linSpec = Zmagnitude(config.linearSpectrum.FrequencyBins,:,:)*config.MagnitudeNormalizationFactor;
    end
    if config.linearSpectrum.FrequencyBins(1)==1
        linSpec(1,:) = 0.5*linSpec(1,:);
    end
    if config.linearSpectrum.FrequencyBins(end) == floor(config.FFTLength/2+1) && rem(config.FFTLength,2)==0
        linSpec(end,:) = 0.5*linSpec(end,:);
    end
    
    linSpec = reshape(linSpec,[],numHops,numChan);
    if obj.linearSpectrum
        temp = permute(linSpec,[2,1,3]);
        numFeatures.linearSpectrum = size(temp,2);
    end
end

if obj.pCalculateMelSpectrum
    if strcmpi(obj.pmelSpectrumType,"Power")
        melFilterBankInput = Zpower;
    else
        melFilterBankInput = Zmagnitude;
    end
    melSpec = config.melSpectrum.FilterBank*melFilterBankInput;
    melSpec = reshape(melSpec,[],numHops,numChan);
    if obj.melSpectrum
        temp = permute(melSpec,[2,1,3]);
        numFeatures.melSpectrum = size(temp,2);
    end
end

if obj.pCalculateBarkSpectrum
    if strcmpi(obj.pbarkSpectrumType,"Power")
        barkFilterBankInput = Zpower;
    else
        barkFilterBankInput = Zmagnitude;
    end
    barkSpec = config.barkSpectrum.FilterBank*barkFilterBankInput;
    barkSpec = reshape(barkSpec,[],numHops,numChan);
    if obj.barkSpectrum
        temp = permute(barkSpec,[2,1,3]);
        numFeatures.barkSpectrum = size(temp,2);
    end
end

if obj.pCalculateERBSpectrum
    if strcmpi(obj.perbSpectrumType,"Power")
        erbFilterBankInput = Zpower;
    else
        erbFilterBankInput = Zmagnitude;
    end
    erbSpec = config.erbSpectrum.FilterBank*erbFilterBankInput;
    erbSpec = reshape(erbSpec,[],numHops,numChan);
    if obj.erbSpectrum
        temp =  permute(erbSpec,[2,1,3]);
        numFeatures.erbSpectrum = size(temp,2);
    end
end

if obj.pCalculateMFCC
    melSpec(melSpec==0) = realmin(class(melSpec));
    a = config.mfcc.DCTmatrix * log10(melSpec);
    a = reshape(a,config.mfcc.Parameters.NumCoeffs,[],numChan);
    a = permute(a,[2,1,3]);
    if obj.mfcc
        numFeatures.mfcc = size(a,2);
    end
    if obj.mfccDelta || obj.mfccDeltaDelta
        b = audio.internal.computeDelta(a,config.mfcc.Parameters.DeltaWindowLength);
        if obj.mfccDelta
            numFeatures.mfccDelta = size(b,2);
        end
        if obj.mfccDeltaDelta
            c = audio.internal.computeDelta(b,config.mfcc.Parameters.DeltaWindowLength);
            numFeatures.mfccDeltaDelta = size(c,2);
        end
    end
end

if obj.pCalculateGTCC
    erbSpec(erbSpec==0) = realmin(class(erbSpec));
    a = config.gtcc.DCTmatrix * log10(erbSpec);
    a = reshape(a,config.gtcc.Parameters.NumCoeffs,[],numChan);
    a = permute(a,[2,1,3]);
    if obj.gtcc
        numFeatures.gtcc = size(a,2);
    end
    if obj.gtccDelta || obj.gtccDeltaDelta
        b = audio.internal.computeDelta(a,config.gtcc.Parameters.DeltaWindowLength);
        if obj.gtccDelta
            numFeatures.gtccDelta = size(b,2);
        end
        if obj.gtccDeltaDelta
            c = audio.internal.computeDelta(b,config.gtcc.Parameters.DeltaWindowLength);
            numFeatures.gtccDeltaDelta = size(c,2);
        end
    end
end

if obj.pExtractSpectralDescriptor
    switch obj.SpectralDescriptorInput
        case 'melSpectrum'
            S = melSpec;
        case 'barkSpectrum'
            S = barkSpec;
        case 'erbSpectrum'
            S = erbSpec;
        case 'linearSpectrum'
            S = linSpec;
    end
    if obj.spectralKurtosis
        [kurtosis,spread,centroid] = spectralKurtosis(S,config.SpectralDescriptorInput.FrequencyVector);
        numFeatures.spectralKurtosis = size(kurtosis,2);
    end
    if obj.spectralSkewness
        [skewness,spread,centroid] = spectralSkewness(S,config.SpectralDescriptorInput.FrequencyVector);
        numFeatures.spectralSkewness = size(skewness,2);
    end
    if obj.spectralSpread
        if (obj.spectralKurtosis || obj.spectralSkewness)
            numFeatures.spectralSpread = size(spread,2);
        else
            [spread, centroid] = spectralSpread(S,config.SpectralDescriptorInput.FrequencyVector);
            numFeatures.spectralSpread = size(spread,2);
        end
    end
    if obj.spectralCentroid
        if (obj.spectralKurtosis || obj.spectralSkewness || obj.spectralSpread)
            numFeatures.spectralCentroid = size(centroid,2);
        else
            centroid = spectralCentroid(S,config.SpectralDescriptorInput.FrequencyVector);
            numFeatures.spectralCentroid = size(centroid,2);
        end
    end
    if obj.spectralCrest
        temp = spectralCrest(S,config.SpectralDescriptorInput.FrequencyVector);
        numFeatures.spectralCrest = size(temp,2);
    end
    if obj.spectralDecrease
        temp = spectralDecrease(S,config.SpectralDescriptorInput.FrequencyVector);
        numFeatures.spectralDecrease = size(temp,2);
    end
    if obj.spectralEntropy
        temp = spectralEntropy(S,config.SpectralDescriptorInput.FrequencyVector);
        numFeatures.spectralEntropy = size(temp,2);
    end
    if obj.spectralFlatness
        temp = spectralFlatness(S,config.SpectralDescriptorInput.FrequencyVector);
        numFeatures.spectralFlatness = size(temp,2);
    end
    if obj.spectralFlux
        temp = spectralFlux(S,config.SpectralDescriptorInput.FrequencyVector,config.spectralFlux.Parameters{:});
        numFeatures.spectralFlux = size(temp,2);
    end
    if obj.spectralRolloffPoint
        temp = spectralRolloffPoint(S,config.SpectralDescriptorInput.FrequencyVector,config.spectralRolloffPoint.Parameters{:});
        numFeatures.spectralRolloffPoint = size(temp,2);
    end
    if obj.spectralSlope
        temp = spectralSlope(S,config.SpectralDescriptorInput.FrequencyVector);
        numFeatures.spectralSlope = size(temp,2);
    end
end

if obj.pitch
    temp = pitch(x,config.SampleRate,'WindowLength',config.WindowLength,'OverlapLength',config.OverlapLength,config.pitch.Parameters{:});
    numFeatures.pitch = size(temp,2);
end

if obj.harmonicRatio
    temp = harmonicRatio(x,config.SampleRate,'Window',config.Window,'OverlapLength',config.OverlapLength);
    numFeatures.harmonicRatio = size(temp,2);
end
end
function featureExtractorParams = getFeatureExtractorParams(obj,featurename,outputType)
    defaults = getFeatureExtractorDefaultParams(obj,featurename);
    switch featurename
        case 'mfcc'
            featureExtractorParams = MergeStructs(defaults,obj.pmfccUserSpecifiedParams);
        case 'gtcc'
            featureExtractorParams = MergeStructs(defaults,obj.pgtccUserSpecifiedParams);
        case 'spectralFlux'
            featureExtractorParams = MergeStructs(defaults,obj.pspectralFluxUserSpecifiedParams);
        case 'spectralRolloffPoint'
            featureExtractorParams = MergeStructs(defaults,obj.pspectralRolloffPointUserSpecifiedParams);
        case 'linearSpectrum'
            featureExtractorParams = MergeStructs(defaults,obj.plinearSpectrumUserSpecifiedParams);
        case 'melSpectrum'
            featureExtractorParams = MergeStructs(defaults,obj.pmelSpectrumUserSpecifiedParams);
        case 'barkSpectrum'
            featureExtractorParams = MergeStructs(defaults,obj.pbarkSpectrumUserSpecifiedParams);
        case 'erbSpectrum'
            % erbSpectrum has interdependent properties. If the user
            % specified FrequencyRange but not NumBands, change the default
            % of NumBands.
            if isfield(obj.perbSpectrumUserSpecifiedParams,"FrequencyRange") && ...
                    ~isfield(obj.perbSpectrumUserSpecifiedParams,"NumBands")
                FR = obj.perbSpectrumUserSpecifiedParams.FrequencyRange;
                defaults.NumBands = ceil(hz2erb(FR(2)) - hz2erb(FR(1)));
            end
            featureExtractorParams = obj.MergeStructs(defaults,obj.perbSpectrumUserSpecifiedParams);
        case 'pitch'
            defaults = struct("Method","NCF","Range",[50,400],"MedianFilterLength",1);
            featureExtractorParams = obj.MergeStructs(defaults,obj.ppitchUserSpecifiedParams);
    end
    if strcmpi(outputType,"cell")
        featureExtractorParams = obj.Struct2NameValueCell(featureExtractorParams);
    end    
end

function defaults = getFeatureExtractorDefaultParams(obj,featurename)
    switch featurename
        case 'mfcc'
            defaults = struct("NumCoeffs",13,"DeltaWindowLength",2,"Rectification","log");
        case 'gtcc'
            defaults = struct("NumCoeffs",13,"DeltaWindowLength",2,"Rectification","log");
        case 'spectralFlux'
            defaults = struct("NormType",2);
        case 'spectralRolloffPoint'
            defaults = struct("Threshold",0.95);
        case 'linearSpectrum'
            defaults = struct("FrequencyRange",[0,obj.SampleRate/2],"SpectrumType","power");
        case 'melSpectrum'
            defaults = struct("NumBands",32,"FrequencyRange",[0,obj.SampleRate/2],"Normalization","bandwidth","SpectrumType","power");
        case 'barkSpectrum'
            defaults = struct("NumBands",50,"FrequencyRange",[0,obj.SampleRate/2],"Normalization","bandwidth","SpectrumType","power");
        case 'erbSpectrum'
            FR = [0,obj.SampleRate/2];
            defaults = struct("NumBands",ceil(hz2erb(FR(2)) - hz2erb(FR(1))),"FrequencyRange",FR,"Normalization","bandwidth","SpectrumType","power");
        case 'pitch'
            defaults = struct("Method","NCF","Range",[50,400],"MedianFilterLength",1);
    end
end

function aStruct = reduceStruct(aStruct)
    fn = fieldnames(aStruct);
    for i = 1:numel(fn)
        if isempty(aStruct.(fn{i}))
            aStruct = rmfield(aStruct,fn{i});
        end
    end
end
function namevalue = Struct2NameValueCell(inputStruct)
    name      = permute(fieldnames(inputStruct),[2 1]);
    value     = (struct2cell(inputStruct))';
    namevalue = [name;value];
    namevalue = namevalue(:)';
end
function outputStruct = MergeStructs(defaults,userSpecified)
    outputStruct = defaults;
    fn = fieldnames(defaults);
    for i = 1:numel(fn)
        if isfield(userSpecified,fn{i})
            outputStruct.(fn{i}) = userSpecified.(fn{i});
        end
    end
end

function groups = getPropertyGroups(~)
    mainProps = { ...
        'Window',...
        'OverlapLength', ...
        'SampleRate', ...
        'FFTLength', ...
        'SpectralDescriptorInput'};
    groups = matlab.mixin.util.PropertyGroup(mainProps,'Properties');
end
function footer = getFooter(obj)
    featureNames = string(fieldnames(obj.pFeaturesToExtract));
    isEnabled    = structfun(@(x)(x),obj.pFeaturesToExtract);
    
    featureNamesEnabled = featureNames(isEnabled);
    featureNamesDisabled = featureNames(~isEnabled);
    
    FPL = 6; % Features displayed per line
    if ~isempty(featureNamesEnabled)
        numToPad = FPL*ceil(numel(featureNamesEnabled)/FPL) - numel(featureNamesEnabled);
        featureNamesEnabled = [featureNamesEnabled;strings(numToPad,1)];
        featureNamesEnabled = reshape(featureNamesEnabled,FPL,[])';
        temp = cell(size(featureNamesEnabled,1),1);
        for i = 1:size(featureNamesEnabled,1)
            if i == size(featureNamesEnabled,1)
                a = strjoin(featureNamesEnabled(i,1:end-numToPad),', ');
            else
                a = strjoin(featureNamesEnabled(i,:),', ');
            end
            b = ["    ",a];
            c = strjoin(b);
            temp{i} = c;
        end
        featureNamesEnabled = strjoin([temp{:}],'\n');
    else
        featureNamesEnabled = "     none";
    end
    
    if ~isempty(featureNamesDisabled)
        numToPad = FPL*ceil(numel(featureNamesDisabled)/FPL) - numel(featureNamesDisabled);
        featureNamesDisabled = [featureNamesDisabled;strings(numToPad,1)];
        featureNamesDisabled = reshape(featureNamesDisabled,FPL,[])';
        temp = cell(size(featureNamesDisabled,1),1);
        for i = 1:size(featureNamesDisabled,1)
            if i == size(featureNamesDisabled,1)
                a = strjoin(featureNamesDisabled(i,1:end-numToPad),', ');
            else
                a = strjoin(featureNamesDisabled(i,:),', ');
            end
            b = ["    ",a];
            c = strjoin(b);
            temp{i} = c;
        end
        featureNamesDisabled = strjoin(cat(1,temp{:}),'\n');
    else
        featureNamesDisabled = "     none";
    end
 
    formatSpec = ['   ',getString(message('audio:audioFeatureExtractor:EnabledFeatures')),'\n%s\n\n   ', ...
                        getString(message('audio:audioFeatureExtractor:DisabledFeatures')),'\n%s\n\n\n   ', ...
                        getString(message('audio:audioFeatureExtractor:DisplayExampleIntro')),'\n   ', ...
                        getString(message('audio:audioFeatureExtractor:DisplayExample')),'\n'];
    text = sprintf(formatSpec,featureNamesEnabled,featureNamesDisabled);
    
    footer = text;
end

function setlinearSpectrum(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.linearSpectrum','linearSpectrum')
    obj.linearSpectrum = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setmelSpectrum(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.melSpectrum','melSpectrum')
    obj.melSpectrum = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setbarkSpectrum(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.barkSpectrum','barkSpectrum')
    obj.barkSpectrum = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function seterbSpectrum(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.erbSpectrum','erbSpectrum')
    obj.erbSpectrum = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setmfcc(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.mfcc','mfcc')
    obj.mfcc = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setmfccDelta(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.mfccDelta','mfccDelta')
    obj.mfccDelta = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setmfccDeltaDelta(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.mfccDeltaDelta','mfccDeltaDelta')
    obj.mfccDeltaDelta = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setgtcc(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.gtcc','gtcc')
    obj.gtcc = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setgtccDelta(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.gtccDelta','gtccDelta')
    obj.gtccDelta = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setgtccDeltaDelta(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.gtccDeltaDelta','gtccDeltaDelta')
    obj.gtccDeltaDelta = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setspectralCentroid(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.spectralCentroid','spectralCentroid')
    obj.spectralCentroid = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setspectralCrest(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.spectralCrest','spectralCrest')
    obj.spectralCrest = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setspectralDecrease(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.spectralDecrease','spectralDecrease')
    obj.spectralDecrease = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setspectralEntropy(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.spectralEntropy','spectralEntropy')
    obj.spectralEntropy = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setspectralFlatness(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.spectralFlatness','spectralFlatness')
    obj.spectralFlatness = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setspectralFlux(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.spectralFlux','spectralFlux')
    obj.spectralFlux = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setspectralKurtosis(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.spectralKurtosis','spectralKurtosis')
    obj.spectralKurtosis = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setspectralRolloffPoint(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.spectralRolloffPoint','spectralRolloffPoint')
    obj.spectralRolloffPoint = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setspectralSlope(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.spectralSlope','spectralSlope')
    obj.spectralSlope = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setspectralSpread(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.spectralSpread','spectralSpread')
    obj.spectralSpread = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setspectralSkewness(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.spectralSkewness','spectralSkewness')
    obj.spectralSkewness = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setpitch(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.pitch','pitch')
    obj.pitch = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setharmonicRatio(obj,val)
    validateattributes(val,{'logical','numeric'}, ...
        {'scalar','nonnan','real'},'set.harmonicRatio','harmonicRatio')
    obj.harmonicRatio = logical(val);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setWindow(obj,val)
    validateattributes(val,{'single','double'}, ...
        {'vector','real','finite'},'set.Window','Window')
    obj.Window = val(:);
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setOverlapLength(obj,val)
    validateattributes(val,{'single','double'}, ...
        {'nonnegative','scalar','integer'},'set.OverlapLength','OverlapLength')
    obj.OverlapLength = val;
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setSampleRate(obj,val)
    validateattributes(val,{'single','double'}, ...
        {'positive','scalar','real','finite'},'set.SampleRate','SampleRate')
    obj.SampleRate = val;
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setFFTLength(obj,val)
    if isempty(val)
        validateattributes(val, {'numeric'},{}, ...
            'set.FFTLength','FFTLength');
    else
        validateattributes(val, {'numeric'}, ...
            {'finite','real','scalar','integer','positive'}, ...
            'set.FFTLength','FFTLength');
    end
    obj.FFTLength = val;
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function setSpectralDescriptorInput(obj,val)
    obj.SpectralDescriptorInput = val;
    obj.pIsInitialized = false; %#ok<MCSUP>
end
function out = getpFeaturesToExtract(obj)
    out = struct( ...
        'linearSpectrum',      obj.linearSpectrum, ...
        'melSpectrum',         obj.melSpectrum, ...
        'barkSpectrum',        obj.barkSpectrum, ...
        'erbSpectrum',         obj.erbSpectrum, ...
        'mfcc',                obj.mfcc, ...
        'mfccDelta',           obj.mfccDelta, ...
        'mfccDeltaDelta',      obj.mfccDeltaDelta, ...
        'gtcc',                obj.gtcc, ...
        'gtccDelta',           obj.gtccDelta, ...
        'gtccDeltaDelta',      obj.gtccDeltaDelta, ...
        'spectralCentroid',    obj.spectralCentroid, ...
        'spectralCrest',       obj.spectralCrest, ...
        'spectralDecrease',    obj.spectralDecrease, ...
        'spectralEntropy',     obj.spectralEntropy, ...
        'spectralFlatness',    obj.spectralFlatness, ...
        'spectralFlux',        obj.spectralFlux, ...
        'spectralKurtosis',    obj.spectralKurtosis, ...
        'spectralRolloffPoint',obj.spectralRolloffPoint, ...
        'spectralSkewness',    obj.spectralSkewness, ...
        'spectralSlope',       obj.spectralSlope, ...
        'spectralSpread',      obj.spectralSpread, ...
        'pitch',               obj.pitch, ...
        'harmonicRatio',       obj.harmonicRatio);
end
function out = getpFFTLength(obj)
    if isempty(obj.FFTLength)
       out =  numel(obj.Window);
    else
       out =  obj.FFTLength;
    end
end
end
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%






