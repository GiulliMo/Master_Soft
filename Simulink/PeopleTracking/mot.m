classdef (StrictDefaults) mot <  matlabshared.tracking.internal.fusion.GNNTracker
%multiObjectTracker Tracking object using GNN assignment
%   tracker = multiObjectTracker creates a multi-sensor, multi-object
%   tracker that uses a global nearest neighbor (GNN) assignment to
%   maintain a single hypothesis about the objects it tracks. The
%   multiObjectTracker initializes, confirms, corrects, predicts (performs
%   coasting) and deletes tracks.
%   A track is created with a 'Tentative' status, meaning that there is not
%   enough evidence for the multiObjectTracker to determine that the track
%   is of a physical object. If enough additional detections are assigned
%   to the tentative track, its status will change to 'Confirmed' (see
%   ConfirmationThreshold). Alternatively, a track will be confirmed if a
%   detection with a nonzero ObjectClassID value is assigned to it, as it
%   means that the sensor is able to classify the physical object.
%   
%   tracker = multiObjectTracker('Name', value) creates a
%   multiObjectTracker object by specifying its properties as name-value
%   pair arguments. Unspecified properties have default values. See the
%   list of properties below.
%
%   Step method syntax: see the help for <a href="matlab:help multiObjectTracker/updateTracks">updateTracks</a>.
%   The updateTracks method is responsible for managing all the tracks:
%     1. The method attempts to assign the detections to existing tracks.
%     2. New tracks are created based on unassigned detections. 
%     3. Tracks that are assigned to detections are updated and confirmed.
%     4. Tracks that are not assigned to detections are coasted (predicted)
%        and eventually deleted.
%
%   System objects may be called directly like a function instead of using
%   the step method. For example, y = step(obj) and y = obj() are
%   equivalent. 
%
%   multiObjectTracker properties:
%     TrackerIndex               - Unique identifier of the tracker
%     FilterInitializationFcn    - A handle to a function that initializes
%                                  a tracking filter based on a detection
%     AssignmentThreshold        - The threshold that controls the
%                                  assignment of detections to tracks
%     MaxNumTracks               - Define the maximum number of tracks
%     MaxNumSensors              - Define the maximum number of sensors
%     ConfirmationThreshold      - Specify M and N for the M-out-of-N
%                                  confirmation logic
%     DeletionThreshold          - Specify P and Q for the P-out-of-Q
%                                  deletion logic
%     HasCostMatrixInput         - Provide cost matrix as an input
%     HasDetectableTrackIDsInput - Provide detectable track IDs as an input
%     StateParameters            - Parameters defining the track state
%     NumTracks                  - Total number of tracks, (Read-only)
%     NumConfirmedTracks         - Number of confirmed tracks, (Read-only)
%
%   multiObjectTracker methods:
%     <a href="matlab:help multiObjectTracker/updateTracks">step</a>                      - Creates, updates, and deletes the tracks
%     updateTracks              - Can be used instead of step
%     predictTracksToTime       - Predicts the tracks to a time stamp
%     getTrackFilterProperties  - Returns the values of filter properties
%     setTrackFilterProperties  - Sets values to filter properties
%     initializeTrack           - Initialize a new track
%     deleteTrack               - Delete an existing track
%     release                   - Allows property value and input characteristics changes
%     clone                     - Creates a copy of the multiObjectTracker
%     isLocked                  - Locked status (logical)
%     reset                     - Resets states of the multiObjectTracker
%     createBus                 - Create Simulink output bus (Simulink only)
%
%   Class support
%   --------------
%   FilterInitializationFcn must be a function_handle or a character vector
%   AssignmentThreshold must be a positive finite real numeric scalar, or a
%   2-element array [a b], where a is finite and b can be infinite.
%   ConfirmationThreshold and DeletionThreshold must be a two elements
%   vector, [M N]. Both M and N must be real positive integers, and M <= N.
%   MaxNumTracks must be a real positive integer.
%   HasCostMatrixInput must be a Logical scalar.
%
%   Example 1: Construct a tracker and use it to track two objects
%   --------------------------------------------------------------
%   % Construct a multiObjectTracker object with the default constant
%   % velocity Kalman filter initialization function, initcvkf
%   tracker = multiObjectTracker('FilterInitializationFcn', @initcvkf, ...
%       'ConfirmationThreshold', [4 5], ...
%       'DeletionThreshold', 10);
%
%   % Update the tracker with two detections with a nonzero ObjectClassID.
%   % These detections will create confirmed tracks.
%   detections = {objectDetection(1, [10;0], 'SensorIndex', 1, ...
%      'ObjectClassID', 5, 'ObjectAttributes', {struct('ID', 1)}); ...
%      objectDetection(1, [0;10], 'SensorIndex', 1, ...
%      'ObjectClassID', 2, 'ObjectAttributes', {struct('ID', 2)})};
%   time = 2;
%   tracks = updateTracks(tracker, detections, time);
%
%   % In this example, the initcvkf filter initialization function is used.
%   % The function initializes a 2-D constant velocity model, which assumes
%   % that the state is: [x; vx; y; vy].
%   % Because there were two detections, two tracks will be initialized. 
%   % They are confirmed on initialization because their ObjectClassID is
%   % nonzero, indicating that the sensor was able to classify them.
%
%   % To find the position and velocity we use:
%   positionSelector = [1 0 0 0; 0 0 1 0]; % [x, y]
%   velocitySelector = [0 1 0 0; 0 0 0 1]; % [vx, vy]
%
%   positions = getTrackPositions(tracks, positionSelector)
%   velocities = getTrackVelocities(tracks, velocitySelector)
%
%   See also: objectDetection, trackingKF, trackingEKF, trackingUKF,
%   initcaekf, initcakf, initcaukf, initctekf, initctukf, initcvekf,
%   initcvkf, initcvukf, getTrackPositions, getTrackVelocities

% Copyright 2016-2019 The MathWorks, Inc.

%#codegen
%#function matchpairs

%% Properties
    % Public, non-tunable properties
    properties(Nontunable, PositiveInteger)
        %MaxNumTracks   Maximum number of tracks
        %   Set the maximum number of tracks the tracker can maintain as a
        %   positive real integer.
        %
        %   Default: 200
        MaxNumTracks = 200
    end
    
    properties(Nontunable)
        %FilterInitializationFcn  Filter initialization function name
        %   Specify the function for initializing the tracking filter used
        %   by a new track. The function must have the following syntax:
        %
        %       filter = filterInitializationFcn(detection)
        %
        %   filter    - a valid tracking filter that implements the motion
        %               and measurement models required for tracking
        %   detection - an objectDetection that initiates the track
        %
        %   See also: trackingKF, trackingEKF, trackingUKF,
        %   objectDetection, initcaekf, initcakf, initcaukf, initctekf,
        %   initctukf, initcvekf, initcvkf, initcvukf
        %
        %   Default: @initcvkf
        %   <a href="matlab:edit('initcvkf')">Open initcvkf for more details.</a>
        FilterInitializationFcn = 'initcvkf'
    end
    
    properties (Hidden, Nontunable)
        %ConfirmationParameters  M and N for the M-out-of-N confirmation
        %   Specify the confirmation logic parameters M and N as [M, N].
        %   A track is confirmed if at least M detections are assigned to
        %   it in the first N updates since the track initialization, where
        %   M <= N. If less than M detections are assigned to the track in
        %   N updates, the track is deleted. 
        %   To determine the value of N, consider the number of times the
        %   tracker may update before a confirmation decision must be made.
        %   For example, if a tracker updates every .05 seconds, and you
        %   allow .5 seconds to make a confirmation decision, use N = 10.
        %   To determine the value of M, consider the probability that the
        %   sensors will detect objects, accounting for interferences,
        %   e.g., occlusion or clutter. Consider reducing the value of M if
        %   tracks fail to be confirmed or increasing it if there are many
        %   tracks based on false detections that get confirmed.
        %
        %   Default: [2, 3]
        ConfirmationParameters = [2, 3]
    
        %NumCoastingUpdates   Number of times a confirmed track is coasted
        %(predicted without a detection) before deletion
        %   Specify the number of steps a confirmed track will be updated
        %   without an assigned detection before it is deleted. The number
        %   must be a positive integer. Decrease this parameter if tracks
        %   should be deleted earlier and increase it if they should be
        %   kept for a longer time before deletion. Consider the rate at
        %   which the tracker is updated and the amount of time a track
        %   should be coasted without an update before deletion.
        %   For example, if you want to predict a track for 0.75 second
        %   before deletion while the tracker updates every 0.05 second,
        %   use NumCoastingUpdates = 15.
        %
        %   Default: 5
        NumCoastingUpdates = 5
        
        %TrackLogic  Choice of track logic.
        % Only 'History' multiObjectTracker supports only 'History'.
        TrackLogic = 'History'
    end
    
%% Methods
    methods
        % Constructor
        function obj = multiObjectTracker(varargin)
            % Support name-value pair arguments when constructing object
            setProperties(obj,nargin,varargin{:})
            obj.pLastTimeStamp = -eps;
        end
        %------------------------------------------------------------------
        
        function set.ConfirmationParameters(obj, value)
            % No need to warn yet
%             coder.internal.warning('shared_tracking:internal:GNNTracker:obsoleteProperty', 'ConfirmationParameters', 'ConfirmationThreshold')
            setConfThreshold(obj,value)
        end
        %------------------------------------------------------------------
        
        function set.NumCoastingUpdates(obj, value)
            % No need to warn yet
%             coder.internal.warning('shared_tracking:internal:GNNTracker:obsoleteProperty', 'NumCoastingUpdates', 'DeletionThreshold')
            setDelThreshold(obj,value)
        end
        %------------------------------------------------------------------
        
        function varargout = updateTracks(obj, varargin)
            %updateTracks Update the tracker 
            % The updateTracks method provides a convenience method to step
            % the tracker in MATLAB even if detections input is empty on
            % the first step.
            %
            % In code generation, this method is the same as calling step.
            % If you are not sure whether the detections input is empty on
            % the first call to step, use:
            %
            %   if isLocked(tracker) || ~isempty(detections)
            %      [...] = step(tracker, detections, time, ...);
            %   end
            % 
            %updateTracks  Creates, updates, and deletes the tracks
            %   The updateTracks method is responsible for managing all the
            %   tracks:
            %   1. The method attempts to assign the detections to existing
            %      tracks.
            %   2. New tracks are created based on unassigned detections.
            %   3. Tracks that are assigned to detections are updated and
            %      confirmed.
            %   4. Tracks that are not assigned to detections are coasted
            %      (predicted but not corrected) and eventually deleted.
            %
            %   confirmedTracks = updateTracks(tracker, detections, time)
            %   Update the tracker with a list of detections to the time
            %   instance specified by time. It returns an array of
            %   confirmed tracks corrected and predicted to the time
            %   instance. See the track output below for description of
            %   confirmedTracks.
            %
            %   ... = updateTracks(..., costMatrix)
            %   HasCostMatrixInput must be true to use this syntax. The
            %   cost matrix must have rows in the same order as the list of
            %   tracks and columns in the same order as the list of
            %   detections. Use the third output of step to get the correct
            %   order of the tracks list. If this is the first call to step
            %   or if there are no previous tracks, the cost matrix should
            %   have a size of [0,numDetections]. Note that the cost must
            %   be calculated so that lower costs indicate a higher
            %   likelihood of assigning a detection to a track. You may use
            %   inf to indicate that certain detections must not be
            %   assigned to certain tracks.
            %
            %   ... = updateTracks(..., detectableTrackIDs)
            %   HasDetectableTrackIDsInput must be true to use this syntax.
            %   The detectableTrackIDs must be an M-by-1 or M-by-2 matrix.
            %   The first column is a list of track IDs that the sensors
            %   report as detectable. The optional second column is the
            %   corresponding probability of detection, if reported by the
            %   sensors. If not reported, the DetectionProbability property
            %   is used. Tracks, whose IDs are not part of
            %   detectableTrackIDs input, are considered as undetectable,
            %   meaning no 'miss' is counted against them if they are not
            %   assigned a detection.
            %
            %   [confirmedTracks, tentativeTracks, allTracks] = updateTracks(...)
            %   in addition, returns a list of the tentative tracks and all
            %   the tracks. Use allTracks if you want to provide a cost
            %   matrix as it preserves the order of the tracks as required
            %   for the cost matrix input.
            %
            %   Inputs:
            %     tracker            - a multi-object tracker
            %     detections         - a cell array of objectDetection objects
            %     time               - the time to which all the tracks will be
            %                          updated and predicted. A real numeric
            %                          scalar, must be greater than the value
            %                          in the previous call.
            %     costMatrix         - the cost of assigning detections to
            %                          tracks. A real T-by-D matrix, where T is
            %                          the number of allTracks in the previous
            %                          call to step and D is the number of
            %                          detections in the current call. Higher
            %                          cost values mean lower likelihood of
            %                          assignment.
            %     detectableTrackIDs - the IDs of tracks that sensors expect to
            %                          detect, reported as an M-by-1 or M-by-2
            %                          matrix. The first column is of track
            %                          IDs, as reported by the TrackID field of
            %                          the tracks output (see Output below).
            %                          The second column is optional and allows
            %                          you to add the detection probability for
            %                          each track.
            %   Output:
            %     tracks - the output depends on the environment:
            %       MATLAB           - An array of <a href="matlab:help objectTrack">objectTrack</a> objects.
            %       Code generation  - An array of struct with the same 
            %                          fields as objectTrack properties.
            %       Simulink         - A 1x1 bus that contains MaxNumTracks
            %                          track buses, each with elements 
            %                          similar to objectTrack.
            %
            %   See also: objectDetection, objectTrack
            % See also: multiObjectTracker
            narginchk(2, nargin)
            if isempty(varargin{1}) && coder.target('MATLAB')% && ~coder.internal.is_defined(obj.pSampleDetection)
                tracksOutput = objectTrack.empty(1,0);
                [varargout{1:3}] = deal(tracksOutput);
                if nargout == 4
                    coder.internal.error('MATLAB:system:maxNumOutputs',4,3)
                end
            else
                [varargout{1:nargout}] = step(obj, varargin{:});
            end
        end
    end
    
    methods(Hidden)
        function [assignments, unassignedTracks, unassignedDetections] = getAssignmentResults(obj)
            % getAssignmentResults      Returns the last assignment results
            %   [assignments, unassignedTracks, unassignedDetections] =
            %   getAssignmentResults(tracker) returns the results of the
            %   last assignment of detections to tracks. It must be called
            %   after a call to updateTracks. 
            %   The method is used for internal testing purposes.
            
            % Take care of the case in which getAssignmentResults is called
            % before the first actual update has happened
            if ~coder.internal.is_defined(obj.cAssigner)
                assignments = zeros(0,2,'uint32');
                unassignedTracks = zeros(0,1,'uint32');
                unassignedDetections = zeros(0,1,'uint32');
                return
            end
            [assignments, unassignedTracks, unassignedDetections] = getAssignmentResults(obj.cAssigner);
            
            % Convert track indices to track IDs
            if ~isempty(assignments)
                assignments = sortrows(assignments,1);
            else
                assignments = zeros(0,2,'uint32');
            end
            
            if ~isempty(unassignedTracks)
                unassignedTracks = sortrows(unassignedTracks);
            else
                unassignedTracks = zeros(0,1,'uint32');
            end
        end
    end
    
    methods (Access = protected)
        function validateFilterOnSetup(~, f)
            cond = isa(f,'trackingKF') || isa(f,'trackingEKF') || isa(f,'trackingUKF') || isa(f,'matlabshared.tracking.internal.AbstractAlphaBetaFilter');
            if ~cond
                coder.internal.error('shared_tracking:internal:GNNTracker:InvalidFilter', class(f), mfilename);
            end
        end
        %------------------------------------------------------------------
        
        function varargout = formatSimulinkOutputs(obj,nargout,~)
            [varargout{1:nargout}] = formatTrackOutputs(obj,nargout);
        end
        %------------------------------------------------------------------
        
        function num = getNumOutputsImpl(obj)
            % Define total number of outputs for system
            if isSimulinkBlock(obj)
                num = 1;
                if obj.TentativeTracksOutputPort
                    num = 2;
                end
                if obj.AllTracksOutputPort
                    num = num + 1;
                end
            else
                num = 3;
            end
        end
    end
    
    methods(Static, Access = protected)
        %% Simulink customization functions
        function header = getHeaderImpl
            % Define header panel for System block dialog
            header = matlab.system.display.Header(...
                'Title', 'driving:block:MultiObjectTrackerTitle', ...
                'Text',	 'driving:block:MultiObjectTrackerDesc');
        end

        function groups = getPropertyGroupsImpl
            % Define property section(s) for System block dialog, only in
            % Simulink
            absTrkrSection = getPropertyGroupsImpl@matlabshared.tracking.internal.fusion.AbstractTracker;

            propNames = {'TrackerIndex','FilterInitializationFcn','AssignmentThreshold',...
                'ConfirmationThreshold','DeletionThreshold','MaxNumTracks',...
                'MaxNumSensors','StateParams'};
            trackerGroup = matlabshared.tracking.internal.getDisplaySection('driving',...
                'multiObjectTracker','TrackerManagement',propNames);
            
            busList = absTrkrSection.PropertyList;
            redirectList = {4, 'SimulinkBusUtilities'; 5, 'SimulinkBusUtilities'};
            
            propNames = {'TimeInputSource','HasCostMatrixInput','HasDetectableTrackIDsInput',...
                busList{:}, ...
                'TentativeTracksOutputPort','AllTracksOutputPort'};
            portsGroup = matlabshared.tracking.internal.getDisplaySection('driving',...
                'multiObjectTracker','InputsOutputs',propNames,redirectList);
            groups = [trackerGroup, portsGroup];
        end
    end
end