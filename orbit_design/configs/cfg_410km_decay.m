%% Config File
% For every orbit we want to keep create a config file like this. Then you
% simply have to choose the config in orbit_design.m and run the code

%% Define range of orbit height and nodal days and inclination
cfg_decay.hr = [409, 410];    % altitude range in km
cfg_decay.ndr = [2, 100];       % nodal days range 
cfg_decay.i = 97.068857314915150;            % inc for 410km orbit
cfg_decay.rep = 0;            % Exact orbit repat to False (default)

cfg_decay.num_sats = 23;       % number of satellites
cfg_decay.overlap = 5;        % [%] 

cfg_decay.selector = 1;       % Chooses the corresponding orbit 

%% Simulation time
cfg_decay.sampling_rate = 5; % [s]
cfg_decay.duration = 60      % [days] Sets the simulation time 

% Revolution Filter
cfg_decay.rev_filter = true;
cfg_decay.rev = [1 32 63 94 125 156 187 218 249 280 311 342 373 404 435 466 497 528 559 590 621];

%% Animation
cfg_decay.animation_sampling_rate = 30; % [Hz] sets sampling rate of the animation
cfg_decay.export_movie = false; % Exports the animation. Can take a long time
cfg_decay.dpi = 300;      % Dots-per-inch of exported movie
cfg_decay.movie_name = "Ground_plot_movie";
cfg_decay.plot_dynamic_DTM = false; % if true, much more computational expensive
cfg_decay.plot_ground_track = true; % plot ground track as line
cfg_decay.plot_swath = true; % plot swath above Bavaria

%% Plotting option
cfg_decay.plot3d = false;     % create 3d plot of the orbit around the Earth
cfg_decay.plot2dww = false;   % create 2d ground track plot world wide
cfg_decay.plot2d_bav = true;  % cretae 2d groun track plot over Bavaria
cfg_decay.plot_animation = false;  % create animated plot of Bavaria region
cfg_decay.visualize_bavaria_extent = false; % Plot geographic extent in flight direction
cfg_decay.swath_color = [0, 0, 0]; % rgb triplet defining the color of the ground track

%% Initialize temporary parameters
cfg_decay.dLOAN = 0;          % [°] initializing, will be changed in first iteration
cfg_decay.startLOAN = 25;     % [°]



