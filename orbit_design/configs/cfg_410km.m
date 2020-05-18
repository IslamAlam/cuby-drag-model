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
cfg.sampling_rate = 1; % [s]
cfg.duration = 1      % [days] Sets the simulation time 

%% Animation
cfg.animation_sampling_rate = 30; % [Hz] sets sampling rate of the animation
cfg.export_movie = false; % Exports the animation. Can take a long time
cfg.dpi = 300;      % Dots-per-inch of exported movie
cfg.movie_name = "Ground_plot_movie";


%% Plotting option
cfg.plot3d = true;     % create 3d plot of the orbit around the Earth
cfg.plot2dww = true;   % create 2d ground track plot world wide
cfg.plot2d_bav = true;  % cretae 2d groun track plot over Bavaria
cfg.plot_animation = true;  % create animated plot of Bavaria region


%% Initialize temporary parameters
cfg.dLOAN = 0;          % [°] initializing, will be changed in first iteration
cfg.startLOAN = 25;     % [°]



