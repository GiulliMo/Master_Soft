clear load;
clear all;
close all;

load('trained_net_daten.mat');
load('spec.mat');
load('commandNet.mat');

Filter = ones(3,3);
%1. layer
A = spec;
A = convolutional(A,Filter,conv1_weights,conv1_Bias,12);
%2.layer
A = batchnormalize(A,batch1_mu,batch1_offset,batch1_scale,batch1_sigma,epsilon);
%3.layer
A = relu(A);
%4.layer
A = padding(A,[0,1,0,0]);
A = padding(A,[0,0,0,1]);
A = maxPoolingSelf(A,[3,3],2);
% %5.layer
A = convolutional(A,Filter,conv2_weights,conv2_bias,24);
% % %6.layer
A=batchnormalize(A,batch2_mu,batch2_offset,batch2_scale,batch2_sigma,epsilon);
% %7.layer
A=relu(A);
% % %8.layer
A = padding(A,[1,0,0,0]);
A = padding(A,[0,1,0,0]);
A = padding(A,[0,0,1,0]);
A = padding(A,[0,0,0,1]);
A = maxPoolingSelf(A,[3,3],2);
%9.layer
A = convolutional(A,Filter,conv3_weights,conv3_bias,48);
% % %10. layer
A = batchnormalize(A,batch3_mu,batch3_offset,batch3_scale,batch3_sigma,epsilon);
% %11. layer
A=relu(A);
% % %12. layer
A = padding(A,[1,0,0,0]);
A = padding(A,[0,1,0,0]);
A = padding(A,[0,0,1,0]); 
A = padding(A,[0,0,0,1]); 
A = maxPoolingSelf(A,[3,3],2);
% % % 13. layer
A= convolutional(A,Filter,conv4_weights,conv4_bias,48);
% 14. layer
A=batchnormalize(A,batch4_mu,batch4_offset,batch4_scale,batch4_sigma,epsilon);
% % %15. layer 
A=relu(A);
%16. layer 
A = convolutional(A,Filter,conv5_weights,conv5_bias,48);
% % % %17. layer 
A=batchnormalize(A,batch5_mu,batch5_offset,batch5_scale,batch5_sigma,epsilon);
% % %18. Layer
A=relu(A);
% % % %19.Layer
A=maxPoolingSelf13x1(A,[13,1],1);
% % % 20.Layer
A=reshape(A,[1,1,336]);
A=reshape(A,[1,336]);
A=fully_connected(A,fully_connected_weights,fully_connected_bias);
A=softmaxHD(A);
% % 


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

function B = convolutional(A,filter,weights,bias,NumFilters)

   C = conv2(A(:,:,1),(filter.*weights(:,:,1,1)),'same');
   
   [height,width]=size(C);
   
   [a,b,NumChannelsWeights,NumChannelsOutput]=size(weights);
   [c,d,NumChannelsInput]=size(A);
 
    B = zeros(height,width,NumChannelsOutput);
    
            for i=1:NumFilters % numFilter ==> numChannels bei Ausgabe
             
                     for l=1:NumChannelsWeights
             
                                      
                         B(:,:,i) = B(:,:,i)+conv2(A(:,:,l),filter.*weights(:,:,l,i),'same');
      
                                   
                     end
               
                B(:,:,i) = B(:,:,i) + bias(:,:,i);
            end
             
end


function A = batchnormalize(A,mu,offset,scale,sigma,epsilon)
    
  [height,width,NumChannels]=size(A);
  
         for k=1:NumChannels
             
            for i=1:height
                
                for j=1:width
                    
                            x_dach = (A(i,j,k) - mu(:,:,k)) / (sqrt(sigma(:,:,k)^2+epsilon));
                            A(i,j,k)=scale(:,:,k)*x_dach + offset(:,:,k);
                            
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
        
        B(i,:)=B(i,:) + A(k)*weights(i,k);
        
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

% EIngangsmatrix muss durch kernel teilbar sein
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