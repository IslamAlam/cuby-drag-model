%% Cuby Project - Technical University of Munich
%  Purpose: transforms latitude and lonitude (in degrees) into position vector in an Earthfixed system, extract from from Earth coast.m
%  Author: Yvonne Ip
%  Date:   10.05.2020
%--------------------------------------------------------------------------


function [r] = latlon2efix(lat,lon)
	RE = 6371*1000;
	
	lat = lat*pi/180;
    lon = lon*pi/180;
	
    r = zeros(length(lon(:)),3);
    for k=1:length(lon(:))
        r(k,:)=[cos(lat(k))*cos(lon(k)) cos(lat(k))*sin(lon(k)) sin(lat(k))*(1-0.5*1/298.257223563)]*RE; 
    end
	
end