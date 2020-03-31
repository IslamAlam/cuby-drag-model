function te = eclipse_time(Omega, inc, T, r, Theta)
% eclipse_time Computes the eclipse time te for a circular orbit
%   Omega   Right ascension of the ascending node [degrees]
%   inc     Inclination [degrees]
%   ie      Inclination of Ecliptic w.r.t. Equator (23.5°)
%   T       Orbital period [s]
%   Theta   Angle between vernal equinox and Sun (0° vernal equinox)
%   R0      Mean radius of Earth @ Equator
%   r       Radius of orbit

ie = 23.5;
R0 = 6378.135e3;            % Earth's radius at equator WGS84 [m] ;

% Compute half-shadow angle alpha
arg =   cosd(Theta)*sind(Omega)*sind(inc)-...
        sind(Theta)*cosd(ie)*cosd(Omega)*sind(inc)+...
        sind(Theta)*sind(ie)*cosd(inc);
beta = asind(arg);
alpha = abs(asind((sqrt(R0/r)^2 - sind(beta)^2) / (cosd(beta))));

% Eclipse time te for circular orbit
te = ((2*alpha) / (360)) * T; 

end

