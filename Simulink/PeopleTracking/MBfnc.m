function y   = MBfnc(msg)
y=1;
frame = msg;
peopleDetector = vision.PeopleDetector('ClassificationModel','UprightPeople_128x64');

persistent currentStep firstrun allTracks confirmedTracks tracker positionSelector detArray

if isempty(currentStep)
    currentStep = 0;
end

currentStep = currentStep + 1;
[detections2,bboxes2,scores2] = detectObjects(peopleDetector, frame, currentStep);

if isempty(firstrun)
    
    firstrun = 1; 
       
    load2 = coder.load('allTracksStruct.mat');
    allTracks = load2.allTracks;
    load = coder.load('detections.mat');
    detections2 = load.detections;
    bboxes2 = load.bboxes;  
    [tracker, positionSelector] = setupTracker();
end



intrinsics2 = cameraIntrinsics([540.6860,540.6860],[479.750,269.7500],[540,960]);
sensor2 = monoCamera(intrinsics2,1.0,'Yaw',0);
d2.sensor = sensor2;
d=d2;

disp(currentStep)

 if isempty(detections2)
      element = struct('a',0,'b',0,'c',0,'d',0)
 elseif numel(detections2)==1         
      element = struct('a',detections2{1,1},'b',0,'c',0,'d',0)       
 elseif numel(detections2)==1         
      element = struct('a',detections2{1,1},'b',detections2{2,1},'c',0,'d',0)       
 elseif numel(detections2)==1         
      element = struct('a',detections2{1,1},'b',detections2{2,1},'c',detections2{3,1},'d',0)       
 elseif numel(detections2)==1         
      element = struct('a',detections2{1,1},'b',detections2{2,1},'c',detections2{3,1},'d',detections2{4,1})       
 end 
% Using the list of objectDetections, return the tracks, updated for
    % 'currentStep' time. After the first frame, a helper function
    % |detectionToTrackCost| is called to compute the customized cost
%     % matrix between all tracks and all detections.

% if isempty(detections2)
%      disp('Keine Detection')
% else
%      disp('Detection')
%     if currentStep == 1
%         disp('erster aufruf')
%          costMatrix = zeros(0, numel(detections2));
%         [confirmedTracks,~,allTracks] = updateTracks(tracker, detections2, currentStep, ...
%             costMatrix);
%         disp('alltracks confirmedtracks und costm')
%         disp(allTracks)
%         disp(confirmedTracks)
%         disp(costMatrix)
%         
%     else
%         disp('Schritt > 2 else Block')
%     [costMatrix] = detectionToTrackCost(allTracks, detections2, ...
%            positionSelector, tracker.AssignmentThreshold,bboxes2);
%         disp(costMatrix)
%          [confirmedTracks,~,allTracks] = updateTracks(tracker, detections2, currentStep, ...
%             costMatrix);
%     end
%     
%       confirmedTracks = removeNoisyTracks(confirmedTracks, positionSelector, d.sensor.Intrinsics.ImageSize);
% end  
    % Remove the tracks for people that are far away.
     
    % Insert tracking annotations.
   

%     
%  if isempty(bboxes)||isempty(scores)
%       disp('keine detection')
%  else
%   I = insertObjectAnnotation(frame,'rectangle',bboxes2,scores2);
%   frameWithAnnotations = insertTrackBoxes(frame, confirmedTracks, positionSelector, d.sensor);
%    % videoPlayer(I);
%    % title('Detected people and detection scores');
%  end
    
 function [tracker, positionSelector] = setupTracker()
 % Create the tracker object.
    tracker = multiObjectTracker('FilterInitializationFcn', @initBboxFilter, ...
        'AssignmentThreshold', 0.999, ...
        'DeletionThreshold', 5, ... 
        'ConfirmationThreshold', [3 5], ...
        'HasCostMatrixInput', true);
   
    % The State vector is: [x; vx; y; vy; w; vw; h; vh]
    % [x;y;w;h] = positionSelector * State
    positionSelector = [1 0 0 0 0 0 0 0; ...
                        0 0 1 0 0 0 0 0; ...
                        0 0 0 0 1 0 0 0; ...
                        0 0 0 0 0 0 1 0]; 
end

function filter = initBboxFilter(Detection)
% Step 1: Define the motion model and state.
%   Use a constant velocity model for a bounding box on the image.
%   The state is [x; vx; y; vy; w; wv; h; hv]
%   The state transition matrix is: 
%       [1 dt 0  0 0  0 0  0;
%        0  1 0  0 0  0 0  0; 
%        0  0 1 dt 0  0 0  0; 
%        0  0 0  1 0  0 0  0; 
%        0  0 0  0 1 dt 0  0; 
%        0  0 0  0 0  1 0  0;
%        0  0 0  0 0  0 1 dt; 
%        0  0 0  0 0  0 0  1]
%   Assume dt = 1. This example does not consider time-variant transition
%   model for linear Kalman filter.
    dt = 2;
    cvel =[1 dt; 0 1];
    A = blkdiag(cvel, cvel, cvel, cvel);
 
% Step 2: Define the process noise. 
%   The process noise represents the parts of the process that the model
%   does not take into account. For example, in a constant velocity model,
%   the acceleration is neglected.
    G1d = [dt^2/2; dt];
    Q1d = G1d*G1d';
    Q = blkdiag(Q1d, Q1d, Q1d, Q1d);
 
% Step 3: Define the measurement model.
%   Only the position ([x;y;w;h]) is measured.
%   The measurement model is
    H = [1 0 0 0 0 0 0 0; ...
         0 0 1 0 0 0 0 0; ...
         0 0 0 0 1 0 0 0; ...
         0 0 0 0 0 0 1 0];
 
% Step 4: Map the sensor measurements to an initial state vector.
%   Because there is no measurement of the velocity, the v components are
%   initialized to 0:
    state = [Detection.Measurement(1); ...
             0; ...
             Detection.Measurement(2); ...
             0; ...
             Detection.Measurement(3); ...
             0; ...
             Detection.Measurement(4); ...
             0];
 
% Step 5: Map the sensor measurement noise to a state covariance.
%   For the parts of the state that the sensor measured directly, use the
%   corresponding measurement noise components. For the parts that the
%   sensor does not measure, assume a large initial state covariance. That way,
%   future detections can be assigned to the track.
    L = 100; % Large value
    stateCov = diag([Detection.MeasurementNoise(1,1), ...
                     L, ...
                     Detection.MeasurementNoise(2,2), ...
                     L, ...
                     Detection.MeasurementNoise(3,3), ...
                     L, ...
                     Detection.MeasurementNoise(4,4), ...
                     L]);
 
% Step 6: Create the correct filter.
%   In this example, all the models are linear, so use trackingKF as the
%   tracking filter.
    filter = trackingKF(...
        'StateTransitionModel', A, ...
        'MeasurementModel', H, ...
        'State', state, ...
        'StateCovariance', stateCov, ... 
        'MeasurementNoise', Detection.MeasurementNoise, ...
        'ProcessNoise', Q);
end


function [detections,bboxes,scores] = detectObjects(detector, frame, frameCount)
    % Run the detector and return a list of bounding boxes: [x, y, w, h]
   
    [bboxes, scores] = detector(frame);
    
   
   % bboxes = detect(detector, frame);
    
    % Define the measurement noise.
    L = 100;
    measurementNoise = [L 0  0  0; ...
                        0 L  0  0; ...
                        0 0 L/2 0; ...
                        0 0  0 L/2];
                    
    % Formulate the detections as a list of objectDetection reports.
    numDetections = size(bboxes, 1);
    detections = cell(numDetections, 1);                      
    for i = 1:numDetections
        detections{i} = objectDetection(frameCount, bboxes(i, :), ...
            'MeasurementNoise', measurementNoise, 'ObjectAttributes',{struct()});
    end
end

function tracks = removeNoisyTracks(tracks, positionSelector, imageSize)

    if isempty(tracks)
        return
    end
    
    % Extract the positions from all the tracks.
    positions = getTrackPositions(tracks, positionSelector);
    % The track is 'invalid' if the predicted position is about to move out
    % of the image, or the bounding box is too small.
    invalid = ( positions(:, 1) < 1 | ...
                positions(:, 1) + positions(:, 3) > imageSize(2) | ...
                positions(:, 3) <= 5 | ...
                positions(:, 4) <= 10 );
    tracks(invalid) = [];
end

function I = insertTrackBoxes(I, tracks, positionSelector, sensor)

    if isempty(tracks)
        return
    end

    % Allocate memory.
    labels = cell(numel(tracks), 1);
    % Retrieve positions of bounding boxes.
    bboxes = getTrackPositions(tracks, positionSelector);

    for i = 1:numel(tracks)
        box = bboxes(i, :);
        
        xyImageLoc = [box(1)+box(3)/2, box(2)+box(4)];
        % Constrain the image point to be within the image boarder.
        xyImageLoc(1) = min(max(xyImageLoc(1), 1), size(I, 2));
        xyImageLoc(2) = min(xyImageLoc(2), size(I, 1));
        
        % Convert to vehicle coordinates using monoCamera object
        xyVehicle = imageToVehicle(sensor, xyImageLoc)
        tracks(i,1).TrackID
        
        
        labels{i} = sprintf('x=%.1f,y=%.1f',xyVehicle(1),xyVehicle(2));
    end
    
    I = insertObjectAnnotation(I, 'rectangle', bboxes, labels, 'Color', 'yellow', ...
        'FontSize', 10, 'TextBoxOpacity', .8, 'LineWidth', 2);
end
function [costMatrix] = detectionToTrackCost(tracks, detections, ...
                                positionSelector, threshold,bboxes)

    if isempty(tracks) || isempty(detections)
        costMatrix = zeros(length(tracks), length(detections));
       % costMatrix2 = zeros(length(tracks), length(detections));
        return
    end
    
    % Compute the overlap ratio between the predicted boxes and the
    % detected boxes, and compute the cost of assigning each detection
    % to each track. The cost is minimum when the predicted bbox is
    % perfectly aligned with the detected bbox (overlap ratio is one).
    
    % Retrieve positions of bounding boxes.
    trackBboxes = getTrackPositions(tracks, positionSelector);
    % Check that the width and height are positive before computing the box
    % overlap ratio.
    trackBboxes(:, 3) = max(eps, trackBboxes(:, 3));
    trackBboxes(:, 4) = max(eps, trackBboxes(:, 4));
    
    % Extract the detected bounding box from all the detections.
   %  allDetections = [detections{:}];
     
   % bboxes2 = reshape([allDetections(:).Measurement], 4, length(detections))';
     
    costMatrix = 1 - bboxOverlapRatio(trackBboxes, bboxes);
    
    %costMatrix2 = 1 - bboxOverlapRatio(trackBboxes, bboxes2);
    % Compute all pairwise assignment costs.
   % costMatrix2(costMatrix2(:) > threshold) = Inf
    % Set unrealistic assignment cost to Inf if there is little box
    % overlap.
    disp('height width')
    [height,width] = size(costMatrix)
    
    for i=1:height
        for j=1:width
            
            if costMatrix(i,j) > threshold(1)
            
                
                costMatrix(i,j) = inf;
                
            else
                disp('1')
               % costMatrix(i,j) = costMatrix(i,j);
            end
        end
    end
end 

end