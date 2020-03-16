%% Cuby Project - Technical University of Munich
%  Purpose: Extract coordinate information from Bavaria polygon file in JSON format, one-off
%  Author: Yvonne Ip
%  Date:   16.03.2020
%  Output: bavaria_long.dat, bavaria_lat.dat
%  Source: OpenStreetMap(http://nominatim.openstreetmap.org/) 
%  OSM ID: 2145268
%  Reference: https://gis.stackexchange.com/questions/183248/getting-polygon-boundaries-of-city-in-json-from-google-maps-api
%--------------------------------------------------------------------------

fname = 'bavaria.json'; 
bavaria_area = jsondecode(fileread(fname));
coor_1=cell2mat(bavaria_area.geometries.coordinates(1)); 
coor_2=cell2mat(bavaria_area.geometries.coordinates(2)); %main boundary

dlmwrite('bavaria_long.dat',coor_2(1,:,1),'delimiter',' ')
dlmwrite('bavaria_lat.dat',coor_2(1,:,2),'delimiter',' ')