%****************************************************************
%        Hochschule Hamm-Lippstadt / HS Bochum                  *
%****************************************************************
% Modul			  : Masterarbeit                                *
%				                            					*
% Datum           : 16-April-2020                               *
%                                                               *
% Funktion        : Compute CNN                                 *
%                                                               *
% Implementation  : MATLAB R2018b                 			    *
%                                                               *
% Author		  : Hannes Dittmann            				    *
%                                                               *
% Bemerkung       : Skript zum haendischen durchrechnen eines CNN
% Letzte Änderung : April 16 2020                                *
%                                                               *
%***************************************************************/

clear load;
clear all;
close all;

load('trained_net_daten.mat');
load('spec.mat');
%load('commandNet.mat');
%load('scope.mat');

Filter = ones(3,3);
%1. layer

A = convolutional(A1,Filter,conv1_weights,conv1_Bias,1,12);

%2.layer

A = batchnormalize(A,batch1_mu,batch1_offset,batch1_scale,batch1_sigma,epsilon);

%3.layer

A = relu(A3);

%4.layer

A = padding(A,[0,1,0,0]);
A = padding(A,[0,0,0,1]);
A = maxPoolingSelf(A,[3,3],2);

% %5.layer

A = convolutional(A,Filter,conv2_weights,conv2_bias,1,24);

%6.layer

A=batchnormalize(A,batch2_mu,batch2_offset,batch2_scale,batch2_sigma,epsilon);

%7.layer

A=relu(A);

%8.layer

A = padding(A,[1,0,0,0]);
A = padding(A,[0,1,0,0]);
A = padding(A,[0,0,1,0]);
A = padding(A,[0,0,0,1]);
A = maxPoolingSelf(A,[3,3],2);

%9.layer

A = convolutional(A,Filter,conv3_weights,conv3_bias,1,48);

%10. layer

A = batchnormalize(A,batch3_mu,batch3_offset,batch3_scale,batch3_sigma,epsilon);

%11. layer

A=relu(A);

%12. layer

A = padding(A,[1,0,0,0]);
A = padding(A,[0,1,0,0]);
A = padding(A,[0,0,1,0]); 
A = padding(A,[0,0,0,1]); 
A = maxPoolingSelf(A,[3,3],2);

% 13. layer

A= convolutional(A,Filter,conv4_weights,conv4_bias,1,48);

% 14. layer

A=batchnormalize(A,batch4_mu,batch4_offset,batch4_scale,batch4_sigma,epsilon);

% 15. layer 

A=relu(A);

%16. layer 

A = convolutional(A,Filter,conv5_weights,conv5_bias,1,48);

%17. layer 

A=batchnormalize(A,batch5_mu,batch5_offset,batch5_scale,batch5_sigma,epsilon);

%18. Layer

A=relu(A);

%19.Layer

A=maxPoolingSelf13x1(A,[13,1],1);

% 20.Layer

A=reshape(A,[1,1,336]);
A=reshape(A,[1,336]);
A=fully_connected(A,fully_connected_weights,fully_connected_bias);
A=softmax(A);


%% Functions Neuronales Netzwerk


function A = relu(A)

[height,width,NumChannels]=size(A);

for k=1:NumChannels

    for i=1:height
   
        for j=1:width
        
       
            if A(i,j,k) >= 0
       
                A(i,j,k)=A(i,j,k);
        
       
             else if A(i,j,k)<0
       
                    A(i,j,k)=0;
             end
                
            end
        end
        
    end
end
end


function A = padding(A,padding) % eingabe padding: [1 1 1 1] top bottom left right
% fuer 1 1 1 1 padarray(A,[1,1])
% nicht alle faelle des Paddings abgedeckt

    [height,width,NumChannels]=size(A);
     
    checksum = padding(1)*2^3+padding(2)*2^2+padding(3)*2^1+padding(4)*2^0; % 1 1 1 1 = 2^3+2^2+2^1+2^0
    
    if checksum == 8 || checksum ==4
        A_dach=zeros(height+1,width,NumChannels);
        
    else if checksum == 2 || checksum ==1
        A_dach=zeros(height,width+1,NumChannels);
        
        else 
    A_dach=zeros(height+1,width+1,NumChannels);
        end
    end
    
    
    for k=1:NumChannels
        
        switch checksum
        
            case 5
                 A_dach(:,:,k) = [ [A(:,:,k);zeros(1,width)] zeros(height+1,1)]; % bottom right padding
            case 10
                 A_dach(:,:,k) = [ zeros(height+1,1) [zeros(1,width);A(:,:,k)] ]; % Top Left Padding
            case 9
                 A_dach(:,:,k) = [[zeros(1,width);A(:,:,k)] zeros(height+1,1)]; % Top Right
            case 6
                  A_dach(:,:,k) = [ zeros(height+1,1) [A(:,:,k);zeros(1,width)] ]; % bottom left
            case 8
                 A_dach(:,:,k) = [zeros(1,width);A(:,:,k)] ; % Top
            case 4
                 A_dach(:,:,k) = [A(:,:,k);zeros(1,width)] ; % Bottom
            case 2
                 A_dach(:,:,k) = [zeros(height,1) A(:,:,k)]; % left
            case 1
                 A_dach(:,:,k) = [A(:,:,k) zeros(height,1)]; % right
        end
        
    end 
    
    A=A_dach;
end


function C = convolutional(A,filter,weights,bias,stride,NumFilters)
   
   % Funktion fuer Faltung mit 3x3 Filter und Stride 1
   % Padding wird in der Funktion durchgefuehrt, nicht vorher!

   [a,b,NumChannelsWeights,NumChannelsOutput]=size(weights);
  
   [heightInput,widthInput,NumChannelsInput]=size(A);
   
   C = zeros(heightInput,widthInput,NumChannelsOutput);
   
   A = padarray(A,[1,1]); % Auffüllen mit Nullen um groesse zu behalten ==> Input = Output
  
            for i=1:NumFilters % numFilter ==> numChannels bei Ausgabe
             
                C(:,:,i)=C(:,:,i)+bias(:,:,i);
                
                 for l=1:NumChannelsInput % Channels =0 Anzahl der GEwichtugns Channel
                         
                         D = A(:,:,l);
                         B = zeros(heightInput,widthInput,NumChannelsWeights);
                         [heightComputing,widthComputing,NumChannelsInput] = size(A);
                         
                         for k=1:stride:heightComputing-2 %-2 also Abzug fuer vorheriges padding ==> Modus Same
           
                                                          
                                 for j=1:stride:widthComputing-2
             
                                     % region of interest fur dot produkt
                                     roi = [D((j-1)*heightComputing+k) D((j)*heightComputing+k) D((j+1)*heightComputing+k) ; D((j-1)*heightComputing+k+1) D((j)*heightComputing+k+1) D((j+1)*heightComputing+k+1) ; D((j-1)*heightComputing+k+2) D((j)*heightComputing+k+2) D((j+1)*heightComputing+k+2)];
                                     kernel = filter.*weights(:,:,l,i); % Kernel
                                     B(k,j,l) = sum(dot(roi,kernel,2)); % Faltung
                                    
                                
                                 end
                                 
                         end
                         
                         C(:,:,i) = C(:,:,i)+B(:,:,l); %% Addition der gefalteten Inputs
                                                       
                 end
                 
            end
                        
end


function A = batchnormalize(A,mu,offset,batch_scale,sigma,epsilon)
    
  % Funktion fuer Batchnorm


  [height,width,NumChannels]=size(A);
  
  
         for k=1:NumChannels

           for i=1:height
                
               for j=1:width
                            
                            x_dach = (A(i,j,k) - mu(:,:,k)) / (sqrt(sigma(:,:,k)+epsilon)); % Varainz = trained Mean ==> nicht mehr quadrieren!!!
                            A(i,j,k)= batch_scale(:,:,k).*x_dach + offset(:,:,k); 
                            
               end
                
           end
            
         end
        
 end
    
    
function A = maxPooling2D(A,XY,stride)
    


[heightInput,widthInput,NumChannels]=size(A);
C = sepblockfun(A(:,:,1),[XY(1),XY(2)],'max');
[height,width]=size(C);
B = zeros(height,width,NumChannels);

    for i=NumChannels
    	B(:,:,i)=sepblockfun(A(:,:,i),[XY(1),XY(2)],'max');
    end

if stride == 2
    
    for i=1:(ceil(heightInput/stride)-height)/2
    
        B= padding(B,[0,1,0,0]);
   
        B= padding(B,[0,1,0,0]);
    end

    for i=1:(ceil(widthInput/stride)-width)/2
   
        B= padding(B,[0,0,1,0]);
   
        B= padding(B,[0,0,0,1]);
    end
    
    else A=B;
    
end

A=B;
classify()

end 


function A = dropout(A,prob)

% Dropout wird fuer trainiertes Netz nicht verwendet

[height,width,NumChannels]=size(A);

        for k=1:NumChannels
            for i=1:height
                for j=1:width
                          zufallszahl = rand;
                          if zufallszahl>= prob
                              A(i,j,k)=A(i,j,k)*1/(1-prob);
                          else if zufallszahl < prob
                              A(i,j,k)=0;
                              
                              end
                              
                          end
                          
                end
                
            end
            
         end
    
end    


function A = fully_connected(A,weights,bias)

[height,width]=size(weights);

B=zeros(height,1);

for i=1:height
    
    for k=1:width
        
        B(i,:)=B(i,:)+A(k)*weights(i,k);
        
    end
    
    B(i,:)=B(i,:)+bias(i);
end

A=B;

end


function A = softmaxHD(A)

[height,width]=size(A);

summe = sum(exp(A));
B=zeros(height,width);

for i=1:height
    
    B(i)=exp(A(i))/summe;
    
end
A=B;
end



function [A] = maxPoolingSelf(A,kernel,stride)

% Eingangsmatrix muss durch kernel teilbar sein
% hier fuer 3 x 3 kernel
% region of interest beachten
 
[height,width,NumChannels]=size(A);

C=zeros(height/kernel(1),width/kernel(2),NumChannels); % Array mit groesse nach pooling

for i=1:NumChannels
    
    B=A(:,:,i);
  zaehlerk = 1;
  
    
        for k=1:stride:height-2
           
            zaehlerj = 1;
            
             for j=1:stride:width-2
                    
                 roi = [B((j-1)*height+k) B((j-1)*height+k+1) B((j-1)*height+k+2) B((j)*height+k) B((j)*height+k+1) B((j)*height+k+2) B((j+1)*height+k) B((j+1)*height+k+1) B((j+1)*height+k+2)];
                 C(zaehlerk,zaehlerj,i)=max(roi); 
                 zaehlerj = zaehlerj+1;
             end
             
             zaehlerk = zaehlerk+1;
        end

end






B=C;

[heightOutput,widthOutput,NumChannels]=size(B);

if stride == 2
    
    for i=1:(ceil(height/stride)-heightOutput)/2
    
        B= padding(B,[0,1,0,0]);
   
        B= padding(B,[1,0,0,0]);
    end

    for i=1:(ceil(width/stride)-widthOutput)/2
   
        B= padding(B,[0,0,1,0]);
   
        B= padding(B,[0,0,0,1]);
    end
    
    else A = B;
    
end

A = B;

end





function C = maxPoolingSelf13x1(A,kernel,stride)

% Eingangsmatrix muss durch kernel teilbar sein
% hier fuer 13 x 1 kernel
% region of interest beachten
 
[height,width,NumChannels]=size(A);

C=zeros(height/kernel(1),width,NumChannels); % Array mit groesse nach pooling

 for i=1:NumChannels
    
        B=A(:,:,i);
     
  for q=1:height/kernel(1)

           for p=1:stride:width
           
                 C(q,p,i)=max(B(:,p)); 

           end
  end
    
end
end