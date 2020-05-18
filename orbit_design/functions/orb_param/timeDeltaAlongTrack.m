function dt = timeDeltaAlongTrack(inc, swathwidth, overlap)
%% Cuby Project - Technical University of Munich
%  Purpose: Computes the time delta an along orbital track necessary so that a
%   trailing satellite covers the next swath 
%  Author: Max Helleis
%  Date:   19.03.2020
%  Input: 
%       inc         - inclination in degrees
%       swathwidth  - swathwidth in meters
%       overlap     - required overlap in percent
%  Output:
%       dt          - required time delta
lat_Bavaria = 47.270108;    % southermost point in Bavaria
swathwidth_ol = swathwidth * (1 - (overlap / 100));

beta = inc - 90;                    % angle between swath and equator
s_perp = swathwidth_ol / cosd(beta);   % swathlength parallel to equator
v_rot = RotationalVelocity(lat_Bavaria); %  Rotational velocity of Earth 
dt = s_perp / v_rot;

% Display information
fprintf('\n------------------------------------------------');
fprintf('\nRequired dt between two satellites on same orbital track for overlap:\nSwathwidth: \t\t\t%.2f [km]\nOverlap: \t\t\t\t%.2f [%%] \ndt: \t\t\t\t\t%.2f [s]\n', swathwidth, overlap, dt);
fprintf('------------------------------------------------\n');
end

