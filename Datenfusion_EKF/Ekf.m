clear all;
close all;
clear load;

load('sensorlog3.mat')

fSample = 100;
tSample= 1/fSample;

t=0:tSample:tSample*(length(Orientation1)-tSample);

I=eye(3);

x=zeros(length(t),3);

%% Filtereinstellungen  

I=eye(3);
P = 100*I;

R=[100 0 0;
   0 100 0;
   0 0 100];

Q=[0.01 0 0;
   0 0.01 0;
   0 0 1];

x_dach = [0 0 0]'; % Startwerte phi theta psi

%% Filter
  
C=I;

for k=1:length(t)

A_d = Ajacob(x_dach,AngularVelocity1(k,:),tSample,I);

a = Acceleration1(k,:);
 
[phi,theta,psi] = EulerAccel(a(1),a(2),MagneticField1(k,:));

xp = fx(x_dach,AngularVelocity1(k,:),tSample);

Pp = A_d*P*A_d' + Q;    

K = Pp*C'*inv(C*Pp*C' + R);

x_dach = xp' + K*([phi theta psi]' - C*xp');
P = Pp - K*C*Pp;
 
x(k,:)=x_dach*180/pi;

end


acc = Acceleration1;
gyro = AngularVelocity1;
mag = Orientation1;


ifilt = ahrsfilter('SampleRate', 100);
for ii=1:size(acc,1)
    qahrs = ifilt(acc(ii,:), gyro(ii,:), mag(ii,:));
    euler2(ii,:)=quat2eul(qahrs)*180/pi;
  %  viewer(qahrs);
   % pause(0.01);
end

%% Darstellung

figure(1)
subplot(2,2,1);
plot(t,x(:,2),'b');
hold on
plot(t,Orientation1(:,3),'r')
hold off
subplot(2,2,2);
plot(t,-x(:,1),'b');
hold on
plot(t,Orientation1(:,2),'r')
hold off
subplot(2,2,3);
plot(t,x(:,3),'b');
hold on
plot(t,Orientation1(:,1),'r')
hold on
plot(t,-1*euler2(:,1)+50,'g')
hold off








