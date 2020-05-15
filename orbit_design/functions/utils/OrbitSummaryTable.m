%% Cuby Project - Technical University of Munich
%  Purpose: Generation Orbit Summary Table
%  Author: Yvonne Ip
%  Date:   07.04.2020
%  Input:  rop,sw_tot
%  Output:  orbit_info
%  Note:  For simplification, sw_tot is alway assume to be the same (assume all pass through the ascending node)
%--------------------------------------------------------------------------

function [orbit_info] = OrbitSummaryTable(rop,sw_tot)

% Define variable
MultiScape100 = CubySensor('MultiScape100', 580e-3, 5.4e-6, 4096);
N_tracks = rop(:,2);
K_days = rop(:,1);

% Create empty array
swath_km = zeros(size(rop,1),1);
GSD_m = zeros(size(rop,1),1);
sat_num_needed = zeros(size(rop,1),1);

% Compute variable
for n = 1:size(rop,1)
    [sw GSD] = MultiScape100.getSwathwidthGSD(rop(n,3)*1000);
    GSD_m(n) = GSD;
    swath_km(n) = sw/1e3;
    sat_num_needed(n)=ceil(sw_tot*1.1/sw);
end

%% Deviation of ground track every 1 days
del_lambda= 360./N_tracks; % spatial interval between ground track
del_lambdarev=360.*(N_tracks-K_days)./N_tracks; % ground track shift ater 1 rev
del_lambda1day = del_lambdarev .* (N_tracks./K_days); % ground track shift ater 2day
del_lambda1day = rem(del_lambda1day,360);

orbit_no = (1:size(rop,1))';
height_km = rop(:,3);
incl_degree = rop(:,4);

orbit_info=table(orbit_no,K_days,N_tracks,height_km,incl_degree,GSD_m,swath_km,sat_num_needed,del_lambda,del_lambdarev,del_lambda1day);

end

