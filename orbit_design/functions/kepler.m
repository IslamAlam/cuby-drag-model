function [ee,itr] = kepler(mm,ecc,tol)

% KEPLER returns the eccentric anomaly from mean anomaly and eccentricity
%        by Newton-Raphson iteration of Kepler's equation: M = E - e sinE.
%        Max number of iterations equals 20.
%
% HOW       ee = kepler(mm,ecc)
%     [ee,itr] = kepler(mm,ecc,tol)
%
% IN  mm  - mean anomaly [rad]	- matrix
%     ecc - eccentricity        - matrix
%     tol - tolerance level (def: 1e-10)
% OUT ee  - eccentric anomaly [rad]
%     itr - number of iterations (optional)
%
% Nico Sneeuw                    Munich                   24/05/96

% uses 
% revision history:
%   19/11/96, NS: Newton-Raphson iteration instead of simple one implemented.
%   05/12/96, NS: eccentricity may be matrix now, of size(mm)
%   05/12/96, NS: default tolerance set to 1e-10 instead of 1e-15

% Checks and defaults
if nargin < 3, tol = 1e-10; end			% defaul tolerance level
if ~length(tol), error('TOL should be scalar'), end
if any(ecc(:) >= 1) | any(ecc(:) < 0)
   error('Non-valid eccentricity')
end
maxitr = 20; 					% maximum #iterations

% initiate
mm     = rem(mm,2*pi);
eeold  = mm;
eenew  = eeold + ecc.*sin(eeold);		% first guess
itr    = 0;

% iterate until all elements suffice TOL criterium
while any(any(abs(eenew-eeold) > tol)) & itr < maxitr
   itr   = itr + 1;
   eeold = eenew;
%   eenew = mm + ecc.*sin(eeold);		% previous simple iteration
   fold  = (eeold-ecc.*sin(eeold)-mm);
   fpold   = (1-ecc.*cos(eeold));
   eenew = eeold - fold./fpold; 		% Newton-Raphson
end

if itr == maxitr & any(any(abs(eenew-eeold) > tol))
   error('KEPLER didn''t achieve convergence within 20 iterations')
else
   ee = eenew;
end
