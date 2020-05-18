function [jd true_anomaly] = trueAnomaly(init_LOAN, T_sat)
%initialRAAN Computes the reference Julian Date so that a satellite with
% a specified initial LOAN has a Local Mean Time of the Ascending Node. The
% RAAN must be 330 ° if using this date. 
%   Arguments
%       initLOAN    -- initial longitude of the ascending node [decimal °]
%       T_sat       -- orbital period of satellite [s]
%   Variables / Constants
%       ET          -- value of the Equation of time (20.03.2022) [min.]
%       t_ve_gw     -- time at Greenwich at vernal equinox UTC
%       t_ve_loan   -- time at LOAN at vernal equinox
%       dt_ve_loan  -- time difference between 10:30 LAT at LOAN and
%                      t_ve_loan
%       LAT_AN      -- equired Local Apparent Time at ascending node
%                      [decimal hours] 
%       LMT_AN      -- Local Mean Solar Time at ascending node
%                      [decimal hours] (LMT ~ UTC @ 0° longitude)
%       dt_ve_loan  -- time passed since it was 10:30 at LOAN  [hours]
%       t_act       -- time when RAAN_act is valid (UTC)
%   Returns
%       jd          -- Julian date of vernal equinox (20.03.2022) -> T0
%       true_anomaly-- True anomay of satellite at T0
ET = - minutes(8);
LAT_AN = 10.5;
LMT_AN = hours(LAT_AN) - ET ;
t_ve_gw = hours(15) + minutes(33);
t_ve_loan = t_ve_gw + hours(init_LOAN / 15);
dt_ve_loan = t_ve_loan - LMT_AN;
 
omega_sat = 360 / T_sat;
num_rev = seconds(dt_ve_loan) * omega_sat;
true_anomaly = mod(num_rev, 360);

ve_time = datetime('20-March-2022') + t_ve_gw;
jd = juliandate(ve_time);

end


