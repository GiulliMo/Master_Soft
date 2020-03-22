%****************************************************************
%        Hochschule Hamm-Lippstadt / HS Bochum                  *
%****************************************************************
% Modul			  : Masterarbeit                                *
%				                            					*
% Datum           : 14-Maerz-2020                               *
%                                                               *
% Funktion        : Median Filter Depth Image                   *
%                                                               *
% Implementation  : MATLAB R2018b                 			    *
%                                                               *
% Author		  : Hannes Dittmann            				    *
%                                                               *
% Bemerkung       : Skript zum filtern eines Bildes aus der    	*
% ROS Topic /kinect1/hd/depth_image                             *
% Letzte Änderung : März 14 2020                                *
%                                                               *
%***************************************************************/

close all;
clear all;
clear load;

load('FILTER.mat'); % simout = 20 Depth Image Bilder ? 

aFrames_raw = simout; % Raw Data uint8
[nSamples,nIndex] = size(aFrames_raw); % size of frame

x = 1920; % height
y = 1080; % width

aFrames = uint16(zeros(nSamples,x,y)); 
aFrames_medFilt = uint16(zeros(nSamples,x,y));

video1 = VideoWriter('depth.avi'); % ungefiltert
video1.FrameRate = 1;

video2 = VideoWriter('depth_filt.avi'); % gefiltert
video2.FrameRate = 1;

open(video1); %open the file for writing

open(video2); 


%% depth data stream to image and filtering
% 1 x 4147200 to 1920 x 1080 

for i = 1:nSamples
    
    frame = reshape(typecast(aFrames_raw(i,:), 'uint16'),x,y); % reshape uint8 1X 4147200 to uint16 1920 x 1080
    aFrames(i,:,:) = frame;
    
    writeVideo(video1,mat2gray(permute(frame,[2 1])));  %write the image to file
    
    frame_medFilt = medfilt2(frame,[2 2]); % median Filter
    
    aFrames_medFilt(i,:,:) = frame_medFilt; %save
    
    writeVideo(video2,mat2gray(permute(frame_medFilt,[2 1]))); %write the image to file
    
end

close(video1); % video ungefiltert
close(video2); % video gefiltert


data_u16 = uint16(ones(nSamples,x*y));
data_u8 = uint8(zeros(nSamples,x*y*2)); % 2 fuer uint16 auf uint8


%% image height x width to data stream uint8 1 x 4147200

for i = 1:nSamples
    
    for k = 1:x %height
        
        for j = 1:y %widtth
                     
             imgIndexStream = j+(k-1)*y; % index data Stream
             
             data_u16(i,imgIndexStream) = aFrames_medFilt(i,k,j); %20x1920x1080 to 20x2073600
           
        end
       
    end
    
    data_u8(i,:) = typecast(data_u16(i,:), 'uint8'); % Cast to uint8 resize from 1 x 2073600 to 1 x 4147200

end


%% Plot einzelner Bilder

figure(1)
subplot(2,1,1)
imshow(mat2gray(permute(aFrames(1,:,:),[3 2 1]))); 
subplot(2,1,2)
imshow(mat2gray(permute(aFrames_medFilt(1,:,:),[3 2 1]))); % filtered


