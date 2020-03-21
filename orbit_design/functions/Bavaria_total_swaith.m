%% Cuby Project - Technical University of Munich
%  Purpose: compute total swath width needed for Bavaria
%  Author: Yvonne Ip
%  Date:   21.03.2020
%--------------------------------------------------------------------------

function [sw_tot] = Bavaria_total_swaith(sw_start_lat,sw_start_lon,sw_end_lat,sw_end_lon)
% define bavaria bound box (for plotting and choice of points)
lat_min = 46;
lat_max = 52;
long_min = 8;
long_max = 15;

[x_min,y_min] = wgs2utm(lat_min,long_min,32,'N');
[x_max,y_max] = wgs2utm(lat_max,long_max,32,'N');

% Load Bavaria Lat Lon
bavaria_lat = load('bavaria_lat.dat');
bavaria_long = load('bavaria_long.dat');
[bavaria_x,bavaria_y] = wgs2utm(bavaria_lat,bavaria_long,32,'N');


% Coordinate transformation x=// swath direction y=// flight direction
% Assume swath vector tangential to earth surface ~  swath xy diff, the angle
% required for coordinate transformation could be obtain by the dot product
% the swath direction vectr and the x unit vector
ind = find(sw_start_lat > lat_min & sw_start_lat < lat_max & sw_start_lon > long_min & sw_start_lon < long_max);
[sw_start_x,sw_start_y] = wgs2utm(sw_start_lat(median(ind)),sw_start_lon(median(ind)),32,'N');
[sw_end_x,sw_end_y] = wgs2utm(sw_end_lat(median(ind)),sw_end_lon(median(ind)),32,'N');
sw_dir_xy=[sw_end_x-sw_start_x sw_end_y-sw_start_y];
theta=acos(dot(sw_dir_xy,[1 0 ])/vecnorm(sw_dir_xy,2));
[rot_matrix] = coor_rotation(2,theta,3);
bavaria_xy_sw = rot_matrix*[bavaria_x;bavaria_y];
[min_x ind_min] = min(bavaria_xy_sw(1,:));
[max_x ind_max] = max(bavaria_xy_sw(1,:));
sw_tot = max_x-min_x;

% Visuailize result
Bavaria_border('UTM'); hold on;
refline(tan(theta+pi/2),bavaria_y(ind_min)-tan(theta+pi/2)*bavaria_x(ind_min)); hold on;
refline(tan(theta+pi/2),bavaria_y(ind_max)-tan(theta+pi/2)*bavaria_x(ind_max)); hold on;
refline(tan(theta),sw_start_y-tan(theta)*sw_start_x);
text(sw_start_x,sw_start_y,'\leftarrow Needed swath [km]:'+string(sw_tot/1e3));
xlim([x_min x_max])
ylim([y_min y_max])
xlabel('x [m]');
ylabel('y [m]');
title('Total swath width needed for Bavaria (UTM32N)');
pbaspect([1 1 1]) 

% Display information
fprintf('\n------------------------------------------------');
fprintf('\nTotal swath width needed for Bavaria:\nSwathwidth: \t\t\t%.2f [km]\n', sw_tot/1e3);
fprintf('------------------------------------------------\n');
end

