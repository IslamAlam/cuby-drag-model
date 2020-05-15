%% Cuby Project - Technical University of Munich
%  Purpose: transforms position vector in an Earthfixed system into position in a topocentric system centered at the specified ground station 
%  Author: Yvonne Ip
%  Date:   09.05.2020
%  Input:  r_efix (Position vector in earth-fixed coordinate [x,y,z])
%          lat_gs  (Latitiude of ground station [degress])
%          lon_gs  (Longitude of ground station [degrees])
%  Output:  r_efix (Position vector in topocentric system [x,y,z])
%           azimuth (azimuth angle [degrees])
%           elevation (elevation angle [degrees])
%--------------------------------------------------------------------------


function [r_topo,azimuth,elevation] = efix2topo(r_efix,lat_gs,lon_gs)
	r_gs=latlon2efix(lat_gs,lon_gs);
	q1=eye(3);
	q1(1,1)=-1;
	rot_lat=coor_rotation(3,deg2rad(lat_gs-90),2);
	rot_lon=coor_rotation(3,deg2rad(lon_gs),3);
	r_topo=q1*rot_lat*rot_lon*(r_efix-r_gs)';
	azimuth=atan2(r_topo(2,:),r_topo(1,:));
	elevation=atan2(r_topo(3,:),(r_topo(1,:).^2+r_topo(2,:).^2).^0.5);
	azimuth=rad2deg(azimuth);
	elevation=rad2deg(elevation);
end