function v_rot = RotationalVelocity(latitude)
%% Cuby Project - Technical University of Munich
%  Purpose: Computes the rotation velocity of Earth at a given
%  latitude 
%  Author: Max Helleis
%  Date:   19.03.2020
%  Input: 
%       latitude    - latitute of POI in decimal degrees
%  Output:
%       v_rot       - rotational velocity of Earth surface in [m / s]

Re = 6378.135e3;            % Earth's radius at equator WGS84 [m] 
f = 1 / 298.247;            % Ellipticity of Earth (Source: Fowler, The Solid Earth)


r_lat = Re * (1 - f * sind(latitude)^2);    % Compute Earth's radius at the given latitude
r_perp = cosd(latitude) * r_lat;    % Radius Earth N-S axis to POI
omega_Earth = (2*pi) / 86164;       % Angular velocity Earth [rad / s]

v_rot = omega_Earth * r_perp;       
end

