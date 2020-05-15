function delta_t = delta_t_baseline(altitude, baseline)
% delta_t_baseline Computes the along-track time difference between two
% satellites for a given along-track baseline length for circular orbits
%   Input
%       altitude    - height of the satellite [m]
%       baseline    - length of the baseline [m]
%   Local       
%       mu          - gravity parameter of Earth
%       l_arc       - length of of arc spanned by the baseline [m]
%       alpha       - angle spanned by l_arc
%       v           - velocity of the satellite [m / s]
%   Output
%       delta_t     - required delta t for the given baseline

mu = 3.98600e14;    % [m^3 / s^2]
Re = 6378.135e3;    % Earth's radius at equator WGS84 [m] 

r = Re + altitude; 
alpha = 2 * asind( baseline / (2*r));
l_arc = (pi * r) / (180) * alpha;
v = sqrt(mu / r);
delta_t = l_arc / v;

% Display information
fprintf('\n------------------------------------------------');
fprintf('\nRequired dt for a baseline of %.2f km along track: %.2f s', baseline/1e3, delta_t);
fprintf('\n------------------------------------------------\n');
end

