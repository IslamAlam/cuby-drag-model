%% Cuby Project - Technical University of Munich
%  Purpose: Orbit design
%  Author: Max Helleis
%  Date:   12.03.2020
%--------------------------------------------------------------------------
close all, clear all, clc;
%% Add subdirectories to path
addpath('classes');
addpath('functions');
addpath('functions/wgs2utm');
%% Define range of orbit height and nodal days and inclination
hr = [300, 501];                            % altitude range in km
ndr = [2, 30];                               % nodal days range 
i = 's';                                    % stands for 'sun-synchronous'

% Compute repeat orbit parameters
rop = RepOrbParam(hr,ndr,i);

% required delta in longitude
dLOAN = 0; % initializing, will be changed in first iteration

num_sats = 1; 
% 25 for 410 km altitude with 10 % overlap / ascending
% 23-24 for 410 km altitude with 5 % overlap / ascending
% 27 for 410 km altitude with 5 % overlap / descending

overlap = 5; % percent

% define a vector containing as many random colors as we have satellites
rand_color = round(rand(num_sats,3), 4);
selector = 2; % selects which output of the RepOrbParam function to plot
start_LOAN = 25.3 % 22.45;
% start_LOAN = [25.1, 5];
% 25.1 works with ascending node coverage
% -166 works with descending node coverage

for num_sat = [1 num_sats]
    % Compute orbit positions and velocities from the orbit parameters
    nod = rop(selector,1);                  % number of nodal days
    nor = rop(selector,2);                  % number of revolutions
    rep = 0;                                % set exact repeat orbit to False
    num = 10;                               % sampling rate in seconds
    dur = 0.1 %rop(selector,1);                  % length of the dataset in days
    sma = (rop(selector,3) + 6378)*1000;    % semi-major-axis in km
    inc = rop(selector,4);                  % inclination angle in degrees
    % lan = start_LOAN(1) - (num_sat-1)*dLOAN;   % initial LOAN in degrees
    lan = start_LOAN - (num_sat-1)*dLOAN;   % initial LOAN in degrees
    man = 0;                                % initial mean anomaly 
    ecc = 0;                                % eccentricity
    aop = 0;                                % initial Argument of Perifee in degrees
    tr  = rop(selector,6);                  % revolution period for one orbit i s
    [efp,tim,iop]=reporbgen_noderot2(nod,nor,rep,num,dur,sma,inc,lan,man,ecc,aop);
	
	% Filter according specified revolutions
	%rev_no = [1 48];
	%[efp,tim,iop] = RevFilter(efp,tim,iop,tr,rev_no);


%% Compute sensor GSD and swath width for given orbits
% define sensor objects and compute swathwidth and GSD at a given altitude
MultiScape100 = CubySensor('MultiScape100', 580e-3, 5.4e-6, 4096, 10, 2600, 7);
[sw GSD] = MultiScape100.getSwathwidthGSD(rop(selector,3)*1000);

% Compute dRAAN for the given swathwidth and the wanted overlap
dLOAN = dLOAN4swath(sw, overlap);

%% Compute eclipse time for the orbit in minutes
Theta = 0; % Angle between Vernal Equinox and direction to sun. 0° is March 21.
te = eclipse_time(lan, inc, tr, sma, Theta) /60; % eclipse time in minutes
to = tr / 60; % orbital period in minutes 

%% Plot the orbits (updated 200319) with swath
parameters = [sma, lan, inc, ecc, aop, sw/1000, GSD, rop(selector,3), te, to];
% plot_orbits3D(efp, parameters), hold on;
% [sw_dir,sw_start,sw_end,sw_start_lon,sw_start_lat,sw_end_lon,sw_end_lat] = swath(efp,sw);
[sw_dir,sw_start,sw_end] = swath(efp,sw);
plot_orbits3D(efp, parameters,sw_start,sw_end, sw, rand_color(num_sat,:));

%% Plot Bavaria area on top of earth coast
Earth_coast(2)
hold on;
Bavaria_border(2)


%% Swath width of the whole bavaria area
% [sw_tot pass_ind] = Bavaria_total_swath(sw_start_lat,sw_start_lon,sw_end_lat,sw_end_lon, sw, inc);
[acr_track_tot_exd,alo_track_tot_exd,obs_tim,alongtrack_GSD] = Bavaria_total_extend(efp,tim,MultiScape100.line_rate);
end
%% Assuming satellites are on same orbital track
% compute the required delta t between the satellites so that they the
% swaths overlap with the specified amount
dt = timeDeltaAlongTrack(inc, sw, overlap);

%% 3D-Stereo vision
% Compute delta RAAN for the additional satellites for a given baseline
% along-track
baseline  = 60e3; % [m]
delta_t_base = delta_t_baseline(rop(selector,3), baseline);
dLOAN_base = dLOAN4dt(delta_t_base, baseline);

%% Create Data table
%orbit_info = OrbitSummaryTable(rop,sw_tot);
% filename = 'orbit_info.xlsx';
% writetable(orbit_info,filename);

%% table (Generate orbit_groundtrackshift_summary.txt)
% for n_orbit = 24
%     fprintf('\nOrbit No:%.0f\nRepeat Cycle:%.0f \nHeight: %.2f\n', n_orbit, orbit_info.K_days(n_orbit),orbit_info.height_km(n_orbit) );
%     [groundtrackshift_info] = GroundTrackShiftOverTime(orbit_info.K_days(n_orbit),orbit_info.N_tracks(n_orbit),orbit_info.del_lambdarev(n_orbit));
% end

%% Compute initial RAAN for orbit
[JD True_anom] = trueAnomaly(start_LOAN, tr);
%% Compute true anomaly difference
true_anom_sat = zeros(num_sats,1);
JD_sat = zeros(num_sats,1);
sat_LOAN = zeros(num_sats,1);
for num_sat = 1:num_sats
    sat_LOAN(num_sat) = start_LOAN - (num_sat-1)*dLOAN;
    [JD True_anom] = trueAnomaly(sat_LOAN(num_sat), tr);
    JD_sat(num_sat) = JD;
    true_anom_sat(num_sat) = True_anom;
end


%% Estimate downlink data volume
dl_bit = MultiScape100.DownlinkDataVolume(obs_tim);

%% load ground station data
fname = 'cuby_ground_segment.csv';
mask_angle = 5;

bps_S=10e6;
bps_X=50e6;

stations = ground_stations(efp,tim,mask_angle,bps_S,bps_X);