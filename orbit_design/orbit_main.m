%% Cuby Project - Technical University of Munich
%  Purpose: Orbit design
%  Author: Max Helleis
%  Date:   12.03.2020
%--------------------------------------------------------------------------
close all, clear all, clc;
%% Add subdirectories to path
addpath('configs');
addpath('classes');
addpath('data');
addpath('functions');
addpath('functions/wgs2utm');
addpath('functions/orb_param');
addpath('functions/plotting');
addpath('functions/plotting/autoArrangeFigures');
addpath('functions/utils');
%% Select config and initialize parameters and physical constants
run cfg_410km.m
run physical_constants

% Compute repeat orbit parameters
rop = RepOrbParam(cfg.hr,cfg.ndr,cfg.i);

% define constant orbit elements (coe) for selected orbit
coe = define_coe(rop, cfg, const);

%% Compute sensor GSD and swath width for given orbits
% define sensor objects and compute swathwidth and GSD at a given altitude
MultiScape100 = CubySensor('MultiScape100', 580e-3, 5.4e-6, 4096, 10, 2600, 7);
[sensor.sw sensor.GSD_acrosstrack] = MultiScape100.getSwathwidthGSD(coe.alt*1000);

% Compute dRAAN for the given swathwidth and the wanted overlap
dLOAN = dLOAN4swath(sensor.sw, cfg.overlap);

%% Load decayed orbit profile, update orbit parameters
run cfg_410km_decay.m
% Compute repeat orbit parameters
rop_decay = RepOrbParam(cfg_decay.hr,cfg_decay.ndr,cfg_decay.i);

% define constant orbit elements (coe) for selected orbit
coe_decay = define_coe(rop_decay, cfg_decay, const);

% replace 
coe_decay.inc = coe.inc; %optional
[sensor.sw sensor.GSD_acrosstrack] = MultiScape100.getSwathwidthGSD(coe_decay.alt*1000);

dTrue_anom= seconds(hours(dLOAN/15))*(360/coe.tr);
dLOAN_decay=dTrue_anom*(coe_decay.tr/360)*15/3600;

coe = coe_decay;
dLOAN = dLOAN_decay;



%% Compute orbit positions and velocities for every satellite
for num_sat = 1:cfg.num_sats
    lan = cfg.startLOAN - (num_sat-1)*dLOAN;   % initial LOAN in degrees
    [efp,tim,iop]=reporbgen_noderot2(coe.nod, coe.nor, ...
        coe.rep, coe.num, coe.dur, coe.sma, coe.inc, lan, ...
        coe.man, coe.ecc, coe.aop);
    
    if cfg.rev_filter == true
        [efp,tim,iop] = RevFilter(efp,tim,iop,coe.tr,cfg.rev);
    end
    
    satellites.('s'+string(num_sat)).lan = lan;
    satellites.('s'+string(num_sat)).efp = efp;
    satellites.('s'+string(num_sat)).tim = tim;
    satellites.('s'+string(num_sat)).iop = iop;
    [~,satellites.('s'+string(num_sat)).True_anom] = trueAnomaly(lan, coe.tr);
end

%% Compute eclipse time for the orbit in minutes
Theta = 0; % Angle between Vernal Equinox and direction to sun. 0° is March 21.
coe.te = eclipse_time(cfg.startLOAN, coe.inc, coe.tr, coe.sma, Theta) /60; % eclipse time in minutes
coe.to = coe.tr / 60; % orbital period in minutes 

%% Compute initial RAAN for orbit
[coe.JD coe.True_anom] = trueAnomaly(cfg.startLOAN, coe.tr);

%% Plot orbits of all satellites
make_plots(satellites, cfg, coe, const, sensor);

%% Compute the required delta t between the satellites to get overlap
coe.dt = timeDeltaAlongTrack(coe.inc, sensor.sw, cfg.overlap);

%% 3D-Stereo vision
% Compute delta RAAN for the additional satellites for a given baseline
% along-track
stereo.baseline  = 60e3; % [m]
stereo.dt_base = delta_t_baseline(rop(cfg.selector,3), stereo.baseline);
stereo.dLOAN_base = dLOAN4dt(stereo.dt_base, stereo.baseline);

%% ground track over time
coe.groundtrackshift_info = GroundTrackShiftOverTime(coe.nod,coe.nor,coe.gts);

%% Downlink
[roi.acr_track_tot_exd,roi.alo_track_tot_exd,roi.obs_tim,sensor.GSD_alongtrack] = Bavaria_total_extend(satellites.s1.efp,satellites.s1.tim,MultiScape100.line_rate, cfg);
dl_bit = MultiScape100.DownlinkDataVolume(roi.obs_tim);

fname = 'cuby_ground_segment.csv';
mask_angle = 5;
bps_S=10e6;
bps_X=50e6;

stations = ground_stations(satellites.s1.efp,satellites.s1.tim,mask_angle,bps_S,bps_X);

%% Orbit Decay Investigation
%% Define range of orbit height and nodal days and inclination
hr = [400, 420];                            % altitude range in km
ndr = [2,100];                               % nodal days range 
i = 's';                                    % stands for 'sun-synchronous'

% Compute repeat orbit parameters
rop = RepOrbParam(hr,ndr,i);

map = jet(range(ndr)+1);

figure;
for i = 1:length(rop(:,4))
    plot(rop(i,4),rop(i,3),'.','color',map(rop(i,1)-rop(1,1)+1,:));
    hold on;
end

xlabel('Inclination [degree]');
ylabel('Orbit Height [km]');
%Set the current Colormap
colormap(map);
%Display Colorbar
h = colorbar('Ticks',0:0.1:1,...
    'TickLabels',num2cell(round(linspace(ndr(1),ndr(2),11))));
ylabel(h, 'Nodal Day')
title('Sun-synchronous Orbits');
