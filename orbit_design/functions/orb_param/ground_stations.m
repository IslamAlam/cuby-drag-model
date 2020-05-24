%% Cuby Project - Technical University of Munich
%  Purpose: Batch run computation of downlink window for multiple ground stations
%  Author: Yvonne Ip
%  Date:   15.05.2020
%  Input:  fname (csv file contains ground station information)
%          efp (Position and Velocity vector in earth-fixed coordinate [x,y,z])
%          tim (time vector, starting with zero [s])
%          mask_angle (mask_angle of downlink window [degrees])
%          bps_S (downlink data rate for S-band [bit/s])
%          bps_X (downlink data rate for S-band [bit/s])
%  Output: stations (table contains downlink related information)
%  Note: For meaningful result, efp, tim should have the length of one orbit repeat cycle
%--------------------------------------------------------------------------


function [stations] = ground_stations(efp,tim,mask_angle,bps_S,bps_X)

	stations = readtable('cuby_ground_segment.csv');
	
	total_win = zeros(size(stations.lat_degree));
	max_win = zeros(size(stations.lat_degree));
	min_win = zeros(size(stations.lat_degree));
	pass_no = zeros(size(stations.lat_degree));
	lat_gs = zeros(size(stations.lat_degree));
	lon_gs = zeros(size(stations.lat_degree));
	for n = 1:length(stations.lat_degree)
		lat_gs(n) = sign(stations.lat_degree(n))*(abs(stations.lat_degree(n))+abs(stations.lat_minute(n))/60+abs(stations.lat_second(n))/3600);
		lon_gs(n) = sign(stations.lon_degree(n))*(abs(stations.lon_degree(n))+abs(stations.lon_minute(n))/60+abs(stations.lon_second(n))/3600);
		[dl_win,pass_no(n)] = downlink(efp,tim,lat_gs(n),lon_gs(n),mask_angle);
		total_win(n) = sum(dl_win);
		max_win(n) = max(dl_win);
		min_win(n) = min(dl_win);
	end
	stations.lat_gs = lat_gs;
	stations.lon_gs = lon_gs;
	stations.total_window_min = total_win/60;
	stations.max_window_min = max_win/60;
	stations.pass_no = pass_no;
	stations.dl_S_GB_total = total_win*bps_S/8/1024/1024/1024;
	stations.dl_S_GB_max = max_win*bps_S/8/1024/1024/1024;
	stations.dl_X_GB_total = total_win*bps_X/8/1024/1024/1024;
	stations.dl_X_GB_max = max_win*bps_X/8/1024/1024/1024;

end

