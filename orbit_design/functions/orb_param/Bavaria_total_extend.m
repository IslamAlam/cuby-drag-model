%% Cuby Project - Technical University of Munich
%  Purpose: compute total extend in across/along track direction for Bavaria, estimate along track GSD
%  Author: Yvonne Ip
%  Date:   21.03.2020
%--------------------------------------------------------------------------

% function [sw_tot ind] = Bavaria_total_swath(lat,lon,sw_end_lat,sw_end_lon, sw, inc)
function [acr_track_tot_exd,alo_track_tot_exd,obs_tim,alongtrack_GSD] = Bavaria_total_extend(efp,tim,line_rate)
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

%Convert efp to latlon
[lat,lon] = efix2latlon(efp);


% Coordinate transformation x=// flight direction y=// swath direction
% Assume flight vector tangential to earth surface ~  swath xy diff, the angle
% required for coordinate transformation could be obtain by the dot product
% the flight direction vectr and the x unit vector
ind = find(lat > lat_min & lat < lat_max & lon > long_min & lon < long_max);
di = diff(ind);
next_pass = find(di > 1);
if ~isempty(next_pass)
    ind=ind(1:next_pass(1)); %only the first pass is used
end


[start_x,start_y] = wgs2utm(lat(ind(1)),lon(ind(1)),32,'N');
[end_x,end_y] = wgs2utm(lat(ind(end)),lon(ind(end)),32,'N');


flight_dir_xy=[end_x,end_y] - [start_x,start_y];
theta=acos(dot(flight_dir_xy,[1 0])/vecnorm(flight_dir_xy,2));
[rot_matrix] = coor_rotation(2,theta,3);
bavaria_xy_sw = rot_matrix*[bavaria_x;bavaria_y];
[min_x ind_min_x] = min(bavaria_xy_sw(1,:));
[max_x ind_max_x] = max(bavaria_xy_sw(1,:));
[min_y ind_min_y] = min(bavaria_xy_sw(2,:));
[max_y ind_max_y] = max(bavaria_xy_sw(2,:));
acr_track_tot_exd = max_y-min_y;
alo_track_tot_exd = max_x-min_x;

%observation Time and alongtrack GSD
obs_tim = range(tim(ind));
alongtrack_GSD=norm(flight_dir_xy)/(line_rate*obs_tim);
obs_tim=obs_tim*alo_track_tot_exd/norm(flight_dir_xy);



% Visuailize result
Bavaria_border('UTM'); hold on;
refline(tan(theta),bavaria_y(ind_min_y)-tan(theta)*bavaria_x(ind_min_y)); hold on;
refline(tan(theta),bavaria_y(ind_max_y)-tan(theta)*bavaria_x(ind_max_y)); hold on;
refline(tan(theta+pi/2),bavaria_y(ind_min_x)-tan(theta+pi/2)*bavaria_x(ind_min_x)); hold on;
refline(tan(theta+pi/2),bavaria_y(ind_max_x)-tan(theta+pi/2)*bavaria_x(ind_max_x)); hold on;


xlim([x_min x_max])
ylim([y_min y_max])
xlabel('x [m]');
ylabel('y [m]');
title('Bavaria total extend (UTM32N)');
pbaspect([1 1 1]) 

% 

% Display information
fprintf('\n------------------------------------------------');
fprintf('\nTotal extend for Bavaria:\n\tAcross-track: \t\t\t%.2f [km]\n\tAlong-track: \t\t\t%.2f [km]\nAlong-track GSD: \t\t\t%.2f [m]\nObservation Time: \t\t\t%.2f [s]\n', acr_track_tot_exd/1e3,alo_track_tot_exd/1e3,alongtrack_GSD,obs_tim);
fprintf('------------------------------------------------\n');
end

