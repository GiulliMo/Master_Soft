clear;

%% Elektronic

Battery_Voltage = 24;                                                      % Nenn-Spannung des Akkus in V
Power_Supply_Voltage = 24;                                                 % Spannung hinter dem 230V-Netzteil in V

motor.number = 4;                                                          % Anzahl der Motoren
motor.nominal_torque = 0.88;                                               % Nenndrehmoment des Motors in Nm
motor.nominal_speed = 4000;                                                % Nenndrehzahl des Motors in 1/min

%% Mechanic

wheel.number = 1;                                                          % Anzahl der angetriebenen Reifen pro Motor
wheel.diameter_zoll = 8;                                                   % Raddurchmesser in ''
wheel.diameter_m = wheel.diameter_zoll*0.0254;                             % Raddurchmesser in m
wheel.front.right.distance = [1 1];                                        % Abstand des Rades vorne rechts zum Mittelpunkt [nachRechts nachVorne]
wheel.front.right.angle = 135;                                             % Winkel der Drehachsedes Rades vorne rechts in deg
wheel.front.left.distance = [-1 1];                                        % Abstand des Rades vorne links zum Mittelpunkt [nachRechts nachVorne]
wheel.front.left.angle = 45;                                               % Winkel der Drehachsedes Rades vorne rechts in deg
wheel.back.right.distance = [1 -1];                                        % Abstand des Rades hinten rechts zum Mittelpunkt [nachRechts nachVorne]
wheel.back.right.angle = 45;                                               % Winkel der Drehachsedes Rades vorne rechts in deg
wheel.back.left.distance = [-1 -1];                                        % Abstand des Rades hinten links zum Mittelpunkt [nachRechts nachVorne]
wheel.back.left.angle = 135;                                               % Winkel der Drehachsedes Rades vorne rechts in deg

gear_ratio1 = 9;                                                           % Getriebeübersetzung 1
gear_ratio2 = 3;                                                           % Getriebeübersetzung 2
gear_ratio = gear_ratio1*gear_ratio2;                                      % Getriebeübersetzung gesamt
car.weight = 100;                                                          % Eigengewicht in kg
load.weight = 700;                                                         % Lastgewicht in kg

J_middle = 1.2e-3;                                                         % Trägheitsmoment der mittleren Welle in kg*m²
J_wheel = 30e-3;                                                           % Trägheitsmoment der Reifenwelle in kg*m²
%J_wheel_motor = J_wheel*gear_ratio2;

M_brake_max = 1;                                                           % maximales Bremsdrehmoment der mechanischen Bremse 
Break_Resistance = 0.001;                                                  % Bremswiderstände in Ohm
friction_losses = 10;                                                      % Reibungsverluste in %

%% PMSM parameters 
PM = 40.3e-3;                                                              % Permanent magnet flux linkage
Ld = 0.00025;                                                              % d-axis inductance
Lq = 0.00025;                                                              % q-axis inductance
L0 = 0.00022;                                                              % 0-axis inductance
Rs = 0.08 / 2;                                                             % Statorwiderstand
N = 1;                                                                     % Polpaarzahl
J_motor = 38e-6;                                                           % Trägheitsmoment der Motorwelle in kg*m²
KV = 130;                                                                  % Motordrehzahlkonstante rpm/V

%% General

g=9.81;                                                                    % Erdbescheunigung in m/s²
gradient.percent = 0;                                                      % Steigung in %
gradient.degree = atan(gradient.percent/100)*360/(2*pi);                   % Steigung in °
%v_start = 1.67;                                                           % Startgeschwindigkeit in m/s


%% Control parameters

Ts = 2e-6;                                                                 % Fundamentale sample time in s
fsw = 2e3;                                                                 % Umschaltfrequenz (switching frequency) in Hz
fc = fsw*10;                                                               % Fequenz des Regelkreises (control loop frequency) in Hz
Tsc = 1/fc;                                                                % Regelkreis (Control loop) sample time in s


%% Operating and derived limits
Imax = 14;                                                                 % maximaler Stator-Strom in A

%% ROS-Operations
rosshutdown;                                                               %ROS wird heruntergfahren
rosinit;                                                                   %ROS wird gestartet

r=rosdevice('alf-desktop','alf','lucky123')                                %Definition des ROS-Master   

runNode(r,'joy');                                                          %joy_node wird gestartet
runNode(r,'RALFCANsend');                                                  %RALFCANsend_node wird gestartet
runNode(r,'RALFJoystick');                                                 %RALFJoystick_node wird gestartet

%% Reglerauslegung

kp=1;
kph=0.1;%kph=0.1
kih=0.005; %kih=0.005
kpv=0.1; %kpv=0.1                                                                   
kiv=0.005; %khv=0.005

t1=1.728/0.7022;
t2=1/1.728;
ks=48.2890;
D=0.6366;
T=0.4729;
tn=6*D*T;%t1;
te=t2;
kr=2*tn/ks;%tn/(2*ks*te);
gpi=tf([kr*tn kr],[tn 0])
c1=clock;

gpv=tf([0 kpv],[0 1]);
giv=tf([0 kiv],[1 0]);
gph=tf([0 kph],[0 1]);
gih=tf([0 kih],[1 0]);

gpidv=gpi%(gpv+giv);
gpidh=gpi%(gph+gih);

pwinkel=-1/20
pwinkel_R=0;                                                                %P-Faktor Winkel Rueckkopplung
pdrehzahl_R=40;
nmax=1500;