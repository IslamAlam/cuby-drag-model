function [jd RAAN_act] = initialRAAN(init_LOAN)
%initialRAAN Computes the reference Julian Date so that a satellite with
% a specified initial LOAN has a Local Mean Time of the Ascending Node. The
% RAAN must be 330 ° if using this date. 
%   Arguments
%       initLOAN    -- initial longitude of the ascending node [decimal °]
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
%       sid_year    -- sidereal year [seconds]
%       omega_es    -- mean angular velocity of Earth around Sun [deg / s]
%       RAAN_ref    -- reference RAAN one would have if the time of ve was 
%                      10:30 at the LOAN
%       t_act       -- time when RAAN_act is valid (UTC)
%   Returns
%       jd          -- Julian date and time for t_act (20.03.2020)
%       RAAN_act    -- RAAN for jd

ET = - 8;
LAT_AN = 10.5;
LMT_AN = hours(LAT_AN) - minutes(ET);
t_ve_gw = hours(15) + minutes(33);
t_ve_loan = t_ve_gw + hours(init_LOAN / 15);
dt_ve_loan = t_ve_loan - LMT_AN;
 
sid_year = 31558149.54;
omega_es = 360 / sid_year;

RAAN_ref = 337.5;
RAAN_act = RAAN_ref - omega_es * seconds(dt_ve_loan);

t_act = t_ve_gw - dt_ve_loan;

date_time = datetime('20-March-2022') + t_act;
% Convert to Julian date
jd = juliandate(date_time);
end


