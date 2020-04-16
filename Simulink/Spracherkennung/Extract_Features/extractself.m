
function featureVector = extractself(obj,x)
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