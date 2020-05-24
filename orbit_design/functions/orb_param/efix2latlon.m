%% Cuby Project - Technical University of Munich
%  Purpose: transforms position vector in an Earthfixed system into latitude and longitude 
%  Author: Yvonne Ip
%  Date:   10.05.2020
%--------------------------------------------------------------------------


function [lat,lon] = efix2latlon(efp)
	% get position components
	posx = efp(:,1);
	posy = efp(:,2);
	posz = efp(:,3);
	
	%%Convert to lat lon
	lon=rad2deg(atan2(posy,posx));
	lat=rad2deg(atan(posz./(posx.^2+posy.^2).^0.5));
end