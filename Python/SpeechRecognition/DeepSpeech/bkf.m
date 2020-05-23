clear all;
close all;
clear load;

data = audioread('streamMono2.wav');

beginn = 2.8;
ende =5.5;
fSample = 16000;

tSample= 1/fSample;

t=0:tSample:tSample*(length(data)-1);

%% Filtereinstellungen  

A = [0.5 -0.06;0.06 0.6];
B = [0.5 -0.06;0.06 0.6];
H = [0.5;0.5]';
R = 0.1;
Q = eye(2)*0.5;

% start 
x_pred_start1 = [0;data(1)]; %k-1
x_pred_start2 = [data(2);data(3)]; % k+1

% Start Prio error cov
P_k = 1*eye(2);
P_post0 = 1*eye(2);                  % P(k-1) 
P_post1 = 1*eye(2);                 % P(k+1)
P_post2 = 1*eye(2);                 % P(k-1,k+1) 
P_post3 = 1*eye(2);                 % P(k+1,k-1) 
P_post4 = 1*eye(2);                 % P(k+1,k-1) an -1
P_post5 = P_post3 +Q;               % P(k+1,k-1) an +1
P_post6 = 1*eye(2);                 % P(k-1,k+1) an -1
P_post7 = P_post2 +Q;              % P(k-1,k+1) an +1

x_k_save=zeros(length(data)-1,2)';

%% Bidirectionaler - Kalman-Filter

for k=1:length(t)-1

x_k = A*x_pred_start1 + B*x_pred_start2;

z_k = [data(k);data(k+1)];

%priori error cov

 P_prioK = abs(A*P_post0*A' + B*P_post1*B' + A*P_post2*B' + B*P_post3*A' + Q);

P_prio1 = abs(A*P_post4*A' + A*P_k*B' + B*P_post5*B' + Q);

P_prio2 = abs(A*P_post4*A' + A*P_k*B' + B*P_post7*B' + Q);

 K = P_prioK*H'*(H*P_prioK*H' + R)^-1;

 K_p1 = P_prio1*H'*(H*P_prio1*H' + R)^-1;
 
 K_m1 = P_prio2*H'*(H*P_prio2*H' + R)^-1;
 
 x_k_post = x_k + K*(z_k(1) - H*x_k);
 x_k_post1 = x_pred_start2 + K_p1*(z_k(2) - H*x_pred_start2);  %k+1
% updaten der cov

P_post0 = P_k;             % P(k-1) 
P_k=(eye(2)-K*H)*P_prioK;
P_post4 = P_post2;                % P(k+1,k-1) an -1
P_post6 = P_post3;                 % P(k-1,k+1) an -1
P_post2 = (eye(2)+K_p1*H)*P_prio1*(eye(2)-K_m1*H)'+K_p1+R*K_m1';               
P_post3 = (eye(2)+K_m1*H)*P_prio2*(eye(2)-K_p1*H)'+K_m1+R*K_p1'; 
P_post5 = P_post3 +Q;               % P(k+1,k-1) an +1
P_post7 = P_post2 +Q;              % P(k-1,k+1) an +1
P_post1 = P_k+Q;                 % P(k+1)

x_pred_start1 = x_k_post;
x_pred_start2 = x_k_post1;

x_k_save(:,k) = x_k_post;

end

y = x_k_save(1,:);

%% Darstellung
figure(1)
plot(t(beginn/tSample:ende/tSample),data(beginn/tSample:ende/tSample),'b')
hold on
plot(t(beginn/tSample:ende/tSample),y(beginn/tSample:ende/tSample),'r')
hold off

audiowrite('hd.wav',y,fSample)