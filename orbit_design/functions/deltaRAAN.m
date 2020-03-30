function dRAAN = deltaRAAN(swathwidth, overlap)
%Computes necessary shift of RAAN to achieve shift in swath at bavaria
%heigth
%   swathwidth  - in meter
%   overlap     - in percent
swathwidth_ol = swathwidth * (1 - (overlap / 100));

deg_meter_eq = 111.31949077920639e3;    % 1 degree delta lat @ Equator in meters
deg_meter_bav = 74.23943551115921e3;    % 1 degree delta lat @ Bavaria in meters

scale_m = deg_meter_eq / deg_meter_bav;
distance_eq = swathwidth_ol * scale_m;

dRAAN = distance_eq / deg_meter_eq;
end

