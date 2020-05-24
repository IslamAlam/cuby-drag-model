%% Cuby Project - Technical University of Munich
%  Purpose: compute swath related information for NADIR view observation
%  Author: Yvonne Ip
%  Date:   16.03.2020
%  Input:  efp (Position and Velocity vector in earth-fixed coordinate [x,y,z])
%          sw  (Swath width [m])
%  Output:  sw_dir       (Swath direction in earth-fixed coordinate [x,y,z])
%           sw_start     (Swath start position in earth-fixed coordinate [x,y,z])
%           sw_end       (Swath end position in earth-fixed coordinate [x,y,z])
%--------------------------------------------------------------------------


function [sw_dir,sw_start,sw_end] = swath(efp,sw)

sw_dir = cross(efp(:,1:3),efp(:,4:6));
sw_dir = sw_dir./vecnorm(sw_dir,2);
sw_start = efp(:,1:3)+(sw/2).*sw_dir;
sw_end = efp(:,1:3)-(sw/2).*sw_dir;

end

