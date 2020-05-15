%% Cuby Project - Technical University of Munich
%  Purpose: compute swath related information for NADIR view observation
%  Author: Yvonne Ip
%  Date:   16.03.2020
%  Input:  efp (Position and Velocity vector in earth-fixed coordinate [x,y,z])
%          sw  (Swath width [m])
%  Output:  sw_dir       (Swath direction in earth-fixed coordinate [x,y,z])
%           sw_start     (Swath start position in earth-fixed coordinate [x,y,z])
%           sw_end       (Swath end position in earth-fixed coordinate [x,y,z])
%           sw_start_lon (Swath start position longtitude)
%           sw_start_lat (Swath start position latitude)
%           sw_end_lon   (Swath end position longtitude)
%           sw_end_lat   (Swath end position latitude)
%--------------------------------------------------------------------------


% function [sw_dir,sw_start,sw_end,sw_start_lon,sw_start_lat,sw_end_lon,sw_end_lat] = swath(efp,sw)
function [sw_dir,sw_start,sw_end] = swath(efp,sw)

sw_dir = cross(efp(:,1:3),efp(:,4:6));
sw_dir = sw_dir./vecnorm(sw_dir,2);
sw_start = efp(:,1:3)+(sw/2).*sw_dir;
sw_end = efp(:,1:3)-(sw/2).*sw_dir;

% sw_start_lon=rad2deg(atan2(sw_start(:,2),sw_start(:,1)));
% sw_start_lat=rad2deg(atan(sw_start(:,3)./(sw_start(:,1).^2+sw_start(:,2).^2).^0.5));
% [sw_start_lat,sw_start_lon] = efix2latlon(sw_start);

% sw_end_lon=rad2deg(atan2(sw_end(:,2),sw_end(:,1)));
% sw_end_lat=rad2deg(atan(sw_end(:,3)./(sw_end(:,1).^2+sw_end(:,2).^2).^0.5));
% [sw_end_lat,sw_end_lon] = efix2latlon(sw_end);

end

