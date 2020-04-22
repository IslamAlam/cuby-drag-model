function jd = initialRAAN(init_LOAN)
%initialRAAN Computes the reference Julian Date so that a satellite with
% a specified initial LOAN has a Local Mean Time of the Ascending Node. The
% RAAN must be 330 ° if using this date. 
%   Arguments
%       initLOAN    -- initial longitude of the ascending node [decimal °]
%   Variables / Constants
%       ET          -- value of the Equation of time (20.03.2022) [min.]
%       dt_ve_loan  -- time difference between initial LOAN and Greenwich
%                      [hour angles]
%       LAT_AN      -- equired Local Apparent Time at ascending node
%                      [decimal hours] 
%       LMT_AN      -- Local Mean Solar Time at ascending node
%                      [decimal hours] (LMT ~ UTC @ 0° longitude)
%       dt_ve_loan  -- time difference between LMT_AN and 
%   Returns
%       jd          -- Julian date to use with 337.5 ° RAAN to obtain the
%                      10:30 am pass for the ascending node and the wanted
%                      initial LOAN

ET = -7.5;
LAT_AN = 10.5;
LMT_AN = hours(LAT_AN) - minutes(ET);

dt_gw_loan = hours(init_LOAN / 15);
dt_ve_loan = LMT_AN - dt_gw_loan;

ve = datetime('20-March-2022') + dt_ve_loan;
% Convert to Julian date
jd = juliandate(ve)
end


