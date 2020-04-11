function out = test(in3) 
    in3 = 0;
    in = coder.load('specmat.mat','spec');
    in2 = imresize(in.spec,[98 50]);
    persistent mynet;
    if isempty(mynet)
        mynet = coder.loadDeepLearningNetwork('commandNet.mat');
    end
    out = predict(mynet,in2);
end