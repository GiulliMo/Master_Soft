function out = loadNet()
    global net ;
    net = coder.loadDeepLearningNetwork('commandNet.mat');
    out = 0;
end

