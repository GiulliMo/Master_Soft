function [phi,theta,psi] = EulerAccel(ax, ay, magnet)
%
%
g = 9.81; % Erdbeschleunigung in m/(s^2)


% Rückgabewerte sind die Eulerwinkel
theta = asin(  ax / g  );
phi   = asin( -ay /(g*cos(theta)));

xm=magnet(1);
ym=magnet(2);
zm=magnet(3);

xh = xm*cos(theta)+zm*sin(theta);
yh = xm*sin(phi)*sin(theta)+ym*cos(phi)-zm*sin(phi)*cos(theta);


psi = atan(yh/xh);

end
