%x = zeros(12800,1);
fs = 16000; % Samplerate des ursprünglichen Audios (vorgefertigte Audios)
load('commandNet.mat') % beinhaltet trainedNet und wird hier in das Workspace geladen 

classificationRate = 20; % Rate?
adr = audioDeviceReader('SampleRate',fs,'SamplesPerFrame',floor(fs/classificationRate)); % stelt das Standartaudiogerät auf die entsprechenden Werte
audioBuffer = dsp.AsyncBuffer(fs); % auslesen des Audibuffers

labels = trainedNet.Layers(end).Classes; % auslesen der Kategorien aus dem trainedNet 
YBuffer(1:classificationRate/2) = categorical("background"); % ??

probBuffer = zeros([numel(labels),classificationRate/2]); % erstellt eine Nullmatrix mit der entsprechenden Dimension

countThreshold = ceil(classificationRate*0.2);
probThreshold = 0.7;

h = figure('Units','normalized','Position',[0.2 0.1 0.6 0.8]);

timeLimit = inf; % Zeit der Ausführung

tic;
rosinit;
pub = rospublisher('/ypred','std_msgs/String');
msg = rosmessage(pub);
while ishandle(h) && toc < timeLimit

    % Extract audio samples from the audio device and add the samples to
    % the buffer.
    x = adr();
    write(audioBuffer,x);
    y = read(audioBuffer,fs,fs-adr.SamplesPerFrame);

    [spec,Z] = helperExtractAuditoryFeatures(y,fs);

    % Classify the current spectrogram, save the label to the label buffer,
    % and save the predicted probabilities to the probability buffer.
    [YPredicted,probs] = classify(trainedNet,spec,'ExecutionEnvironment','cpu');

    
    YBuffer = [YBuffer(2:end),YPredicted];
    probBuffer = [probBuffer(:,2:end),probs(:)];

    % Plot the current waveform and spectrogram.
    subplot(2,1,1)
    plot(y)
    axis tight
    ylim([-1,1])

    subplot(2,1,2)
    pcolor(spec')
    caxis([-4 2.6445])
    shading flat

    % Now do the actual command detection by performing a very simple
    % thresholding operation. Declare a detection and display it in the
    % figure title if all of the following hold: 1) The most common label
    % is not background. 2) At least countThreshold of the latest frame
    % labels agree. 3) The maximum probability of the predicted label is at
    % least probThreshold. Otherwise, do not declare a detection.
    [YMode,count] = mode(YBuffer);
    YModeStr = timeseries(string(YMode));
    maxProb = max(probBuffer(labels == YMode,:));
    subplot(2,1,1)
    if YMode == "background" || count < countThreshold || maxProb < probThreshold
        title(" ")
    else
        title(string(YMode),'FontSize',20)
    end
    YPstr = char(YMode);
    msg.Data = YPstr;
    send(pub,msg);
    drawnow
end