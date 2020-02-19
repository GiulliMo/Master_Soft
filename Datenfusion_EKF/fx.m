function xp = fx(xhat, rates, dt)
%
%
phi   = xhat(1);
theta = xhat(2);

p = rates(1);
q = rates(2);
r = rates(3);

xdot = zeros(3, 1);

xdot(1) = p + q*sin(phi)*tan(theta) + r*cos(phi)*tan(theta);
xdot(2) =     q*cos(phi)            - r*sin(phi);
xdot(3) =     q*sin(phi)/cos(theta) + r*cos(phi)/cos(theta);

xp(1) = xhat(1) + xdot(1)*dt; % Prädiktion des Zustandsvektors
xp(2) = xhat(2) + xdot(2)*dt;
xp(3) = xhat(3) + xdot(3)*dt;

end

