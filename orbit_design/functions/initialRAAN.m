function jd = initialRAAN(initLOAN)
%initialRAAN Computes the reference Julian Date so that a satellite with
% a specified initial LOAN has a Local Mean Time of the Ascending Node. The
% RAAN must be 330 ° if using this date. 
%   Arguments
%       initLOAN    -- initial longitude of the ascending node [decimal °]
%   Returns
%       JD          -- Julian date to use with 337.5 ° RAAN to obtain the
%                      10:30 am pass for the ascending node and the wanted
%                       initial LOAN

% time of vernal equinix @ longitude of initial LOAN
time_ve_loan = hours(initLOAN / 15);
delta_t = hours(10.5) - time_ve_loan;
% add 8 minutes (from the equation of time) to obtain the Local Apparent
% Solar Time (LAT = LMT + ET)
time_gw_raan = delta_t + minutes(8);

ve = datetime('20-March-2020') + time_gw_raan;
% Convert to Julian date
jd = juliandate(ve);
end

