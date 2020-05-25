function coe = define_coe(rop, cfg, const)
%Defines the constant orbital elements that are shared between several
%satellites
%   :param: rop: Output of RepOrbParam for the selected orbit
%   :param: cfg: Config file
%   :param: const: Struct containing the physical constants
%   :return: coe: constant orbit elements
selector = cfg.selector;
coe.alt = rop(selector,3);         % altitude in km
coe.nod = rop(selector,1);  % number of nodal days
coe.nor = rop(selector,2);  % number of revolutions
coe.num = cfg.sampling_rate;
coe.rep = cfg.rep;          % Excact orbit repeat to False
coe.dur = cfg.duration;   
coe.sma = rop(selector,3)*1000 + const.R0; % semi-major-axis in m
coe.inc = rop(selector,4);  % inclination
coe.man = 0;
coe.ecc = 0;
coe.aop = 0;                % inital argument of perigee
coe.tr = rop(selector,6);   % [s] revolution period for one orbit
coe.gts = 360.*(coe.nor-coe.nod)./coe.nor; %Ground track shift in longitude for 1 rev in degree
end

