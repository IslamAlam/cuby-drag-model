%% Config File
% For every orbit we want to keep create a config file like this. Then you
% simply have to choose the config in orbit_design.m and run the code

%% Define range of orbit height and nodal days and inclination
cfg.hr = [450, 465];    % altitude range in km
cfg.ndr = [2, 3];       % nodal days range 
cfg.i = 's';            % stands for 'sun-synchronous'
cfg.rep = 0;            % Exact orbit repat to False (default)

cfg.num_sats = 10;       % number of satellites
cfg.overlap = 5;        % [%] 

cfg.selector = 1;       % Chooses the corresponding orbit 

%% Simulation time
cfg.sampling_rate = 10; % [s]
cfg.duration = 1      % [days] Sets the simulation time 


%% Initialize temporary parameters
cfg.dLOAN = 0;          % [°] initializing, will be changed in first iteration
cfg.startLOAN = 25;     % [°]



