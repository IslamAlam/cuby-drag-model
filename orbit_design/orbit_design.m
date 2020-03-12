%% Cuby Project - Technical University of Munich
%  Purpose: Orbit design
%  Author: Max Helleis
%  Date:   12.03.2020
%--------------------------------------------------------------------------

%% Add subdirectories to path
addpath("classes");
addpath("functions");

%% Define range of orbit height and nodal days and inclination
hr = [350, 450];                            % altitude range in km
ndr = [1, 3];                               % nodal days range 
i = "s";                                    % stands for "sun-synchronous"

% Compute repeat orbit parameters
rop = RepOrbParam(hr,ndr,i);

% Compute orbit positions and velocities from the orbit parameters
nod = rop(1,1);         % number of nodal days
nor = rop(1,2);         % number of revolutions
rep = 0;                % set exact repeat orbit to False
num = 10;               % Sampling rate in seconds
dur = 5;                % Length of the dataset in days
sma = rop(1,3) + 6378;  % semi-major-axis in km
inc = rop(1,4);         % inclination angle in degrees
lan = 0;                % initial RAAN in degrees
man = 0;                % initial mean anomaly 
ecc = 0;                % eccentricity

%[efp,tim,iop]=reporbgen_noderot2(nod,nor,rep,num,dur,sma,inc,lan,man,ecc)

%% Compute sensor GSD and swath width for given orbits

% define sensor objects
MultiScape100 = CubySensor("MultiScape100", 580e-3, 5.4e-6, 4096);
MultiScape100.getSwathwidthGSD(500e3);