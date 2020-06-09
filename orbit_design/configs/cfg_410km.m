%% Config File
% For every orbit we want to keep create a config file like this. Then you
% simply have to choose the config in orbit_design.m and run the code

%% Define range of orbit height and nodal days and inclination
cfg.hr = [400, 420];    % altitude range in km
cfg.ndr = [1, 2];       % nodal days range 
cfg.i = 's';            % stands for 'sun-synchronous'
cfg.rep = 0;            % Exact orbit repat to False (default)

cfg.num_sats = 23;       % number of satellites
cfg.overlap = 5;        % [%] 

cfg.selector = 1;       % Chooses the corresponding orbit 

%% Simulation time
cfg.sampling_rate = 5; % [s]
cfg.duration = 0.1     % [days] Sets the simulation time 

% Revolution Filter
cfg.rev_filter = false;
cfg.rev = [1 48];

%% Animation
cfg.animation_sampling_rate = 30; % [Hz] sets sampling rate of the animation
cfg.export_movie = false; % Exports the animation. Can take a long time
cfg.dpi = 300;      % Dots-per-inch of exported movie
cfg.movie_name = "Ground_plot_movie";
cfg.plot_dynamic_DTM = false; % if true, much more computational expensive
cfg.plot_ground_track = true; % plot ground track as line
cfg.plot_swath = true; % plot swath above Bavaria

%% Plotting option
cfg.plot3d = false;     % create 3d plot of the orbit around the Earth
cfg.plot2dww = false;   % create 2d ground track plot world wide
cfg.plot2d_bav = true;  % cretae 2d groun track plot over Bavaria
cfg.plot_animation = false;  % create animated plot of Bavaria region
cfg.visualize_bavaria_extent = false; % Plot geographic extent in flight direction
cfg.swath_color = [0, 0, 0.5]; % rgb triplet defining the color of the ground track
cfg.GermanyAustriaSwitzerland = true; % if true, plots the ground swath 
% over Germany, Austrie and Switzerland

%% Initialize temporary parameters
cfg.dLOAN = 0;          % [°] initializing, will be changed in first iteration
cfg.startLOAN = 25;     % [°]



