function dLOAN_deg = dLOAN4dt(delta_t, baseline)
%dLOAN4dt Computes the shift in longitude of the ascending node for a given
%delta t for circular orbits along track
%  Input
%       delta_t     - along-track delta t [s]
%       baseline    - length of the baseline [m]
%  Local
%       d_sid       - length of sidereal day [s]
%       omega_earth - angular velocity of Earth
%  Output
%       dLOAN_def   - delta in the longitude of the ascending node [°]
d_sid = 86164;      % [s]

omega_earth = 2*pi / d_sid;         % [rad / s]
dLOAN_rad = omega_earth * delta_t;  % [rad]
dLOAN_deg = rad2deg(dLOAN_rad);

% Display information
fprintf('\n------------------------------------------------');
fprintf('\nDelta in the longitude of the ascending node for a baseline of \n%.2f km along track: %.2f °', baseline/1e3, dLOAN_deg);
fprintf('\n------------------------------------------------\n');
end

