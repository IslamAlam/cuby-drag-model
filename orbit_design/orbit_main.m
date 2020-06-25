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

%% Orbit Decay Investigation
% Load decayed orbit profile, update orbit parameters
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

% cfg= cfg_decay;
% coe = coe_decay;
% dLOAN = dLOAN_decay;

%% Compute Groundtrack difference
lan = cfg.startLOAN - (cfg.num_sats-1)*dLOAN;
[efp,tim,iop]=reporbgen_noderot2(coe.nod, coe.nor, ...
    coe.rep, coe.num, coe.dur, coe.sma, coe.inc, lan, ...
    coe.man, coe.ecc, coe.aop);

if cfg.rev_filter == true
    [efp,tim,iop] = RevFilter(efp,tim,iop,coe.tr,cfg.rev);
end

lan = cfg_decay.startLOAN - (cfg_decay.num_sats-1)*dLOAN_decay;
[efp_decay,tim_decay,iop_decay]=reporbgen_noderot2(coe_decay.nod, coe_decay.nor, ...
    coe_decay.rep, coe_decay.num, coe_decay.dur, coe_decay.sma, coe_decay.inc, lan, ...
    coe_decay.man, coe_decay.ecc, coe_decay.aop);

if cfg_decay.rev_filter == true
    [efp_decay,tim_decay,iop_decay] = RevFilter(efp_decay,tim_decay,iop_decay,coe_decay.tr,cfg_decay.rev);
end

[x_disp acs_discp] = GroundTrackDisplacement(efp,efp_decay);

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
coe_decay.groundtrackshift_info = GroundTrackShiftOverTime(coe_decay.nod,coe_decay.nor,coe_decay.gts);

%% Downlink
[roi.acr_track_tot_exd,roi.alo_track_tot_exd,roi.obs_tim,sensor.GSD_alongtrack] = Bavaria_total_extend(satellites.s1.efp,satellites.s1.tim,MultiScape100.line_rate, cfg);
dl_bit = MultiScape100.DownlinkDataVolume(roi.obs_tim);

fname = 'cuby_ground_segment.csv';
mask_angle = 5;
bps_S=10e6;
bps_X=50e6;

stations = ground_stations(satellites.s1.efp,satellites.s1.tim,mask_angle,bps_S,bps_X);




