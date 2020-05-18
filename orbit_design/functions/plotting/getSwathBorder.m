function [swlbx, swlby, swrbx, swrby] = getSwathBorder(sw, gtx, gty, inc)
%getSwathBorder Returns the left and right border of the swath in UTM crs
%   sw  - swathwidth in meter
%   gtx - Ground track x-cord in UTM coordindates 
%   gty - Ground track y-cord in UTM coordindates 
%   inc - Inclination of the orbit in degrees
sw2 = sw / 2;
beta = inc - 90;    % degrees

% Create vectors containing the borders of the swaths
swlbx = zeros(length(gtx),1);
swlby = swlbx;
swrbx = swlbx;
swrby = swlbx;

% compute deltas
dx = sw2 * cosd(beta);
dy = sw2 * sind(beta);

% left border
swlbx = gtx - dx;
swlby = gty - dy;

% right border
swrbx = gtx + dx;
swrby = gty + dy;
end

