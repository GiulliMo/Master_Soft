function A = Ajacob(xhat, rates, dt,I)
%
%
A = zeros(3, 3);

phi   = xhat(1);
theta = xhat(2);

p = rates(1);
q = rates(2);
r = rates(3);

A(1,1) = q*cos(phi)*tan(theta)   - r*sin(phi)*tan(theta);
A(1,2) = q*sin(phi)/cos(theta)^2 + r*cos(phi)/cos(theta)^2;
A(1,3) = 0;

A(2,1) = -q*sin(phi) - r*cos(phi);
A(2,2) = 0;
A(2,3) = 0;

A(3,1) = q*cos(phi)/cos(theta) - r*sin(phi)/cos(theta);
A(3,2) = q*sin(phi)*sin(theta)/2*cos(theta)^2 + r*cos(phi)*sin(theta)/2*cos(theta);
A(3,3) = 0;

A = I + A*dt; % Linearisierung im AP
end