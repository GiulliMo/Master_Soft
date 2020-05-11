% intrinsics2 = cameraIntrinsics([540.6860,479.750],[540.6860,269.7500],[540,960]);
% sensor2 = monoCamera(intrinsics2,1.0,'Yaw',0);
% d2.sensor = sensor2;
% pedWidth = [0.5, 1.5];
% d=d2;
% %detector = peopleDetectorACF('caltech');
% detector = configureDetectorMonoCamera(detector, d2.sensor, pedWidth);
% str = struct(detector)


     load2 = load('allTracksStruct.mat');
     allTracks = load2.allTracks2;
     
     names=fieldnames(allTracks);
     N=length(names);
     
     for k=N:-1:16
         allTracks = rmfield(allTracks,names(k));
     end