function [efp,tim,iop]=reporbgen_noderot2(nod,nor,rep,num,dur,sma,inc,lan,man,ecc,aop)
% REPORBGEN_NODEROT2 Repeat orbit generation with rotation of the ascending
%           node, a_E, GM, J2 and om_E from WGS84
%
% [efp,tim,iop]=reporbgen_noderot2(nod,nor,rep,num,dur,sma,inc,lan,man,ecc,aop)
%
% Repeat orbit parameters
%   nod     number of nodal days
%   nor     number of revolutions
%   rep     rep=1 (def.) for exact repeat
%   num     number of data per cycle for rep=1
%           sampling in s for rep~=1 (no exact repeat)
%   dur     number of cycles for rep=1, def: dur=1
%           number of solar days for rep~=1, def: dur=nod29600
% Keplerian elements
%   sma     semi-major axis of the keplerian ellipse [m]
%   inc     inclination [deg], def: inc=90
%   lan     longitude of the ascending node [deg], def: lan=0
%   man     initial mean anomaly [deg], def: man=0
%   ecc     eccentricity, def: ecc=0
%   aop     argument of the perigee [deg], def: aop=0
%
% Output
%   efp     Earth fixed orbit positions and velocities, (num,6)-matrix,
%           [r_x,r_y,r_z,v_x,v_y,v_z] in [m] and [m/s]
%   tim     time vector, starting with zero [s]
%   iop     inertial orbit positions and velocities, (num,6)-matrix

if nargin<11 || isempty(aop); aop=0; end
if nargin<10 || isempty(ecc); ecc=0; end
if nargin<9 || isempty(man); man=0; end
if nargin<8 || isempty(lan); lan=0; end
if nargin<7 || isempty(inc); inc=90; end
if max([numel(aop),numel(ecc),numel(man),numel(lan),numel(inc),numel(sma),...
        numel(dur),numel(num),numel(rep),numel(nor),numel(nod)])>1
    error('all input arguments must be scalars')
end
if isempty(dur)
    if rep==1, dur=1;
    else dur=nod; end
end

% constants
% a_E=6378136.3;      % GOCO02S
% GM0=3.9860044150e14;% GOCO02S

a_E=6378137;        % semi-major axis of ellipsoid [m]
GM0=3986005e8;      % geocentric grav. constant [m^3 / s^2]
J2=1.08263e-3;      % earth's dyn. form factor (= -C20 unnormalized)
om_E=7.292115e-5;   % mean ang. velocity [rad/s]

disp('------------------------------------------------')
disp('REPORBGEN NODEROT')
disp('------------------------------------------------')
disp('INPUT DATA')
disp(['nodal days                       ',num2str(nod)])
disp(['revolutions                      ',num2str(nor)])
if rep==1
    disp(['#data per cycle                  ',num2str(num)])
    disp(['#cycles                          ',num2str(dur)])
else
    disp(['sampling [s]                     ',num2str(num)])
    disp(['# solar days                     ',num2str(dur)])
end
disp(['altitude [km]                    ',num2str((sma-a_E)/1e3)])
disp(['inclination [deg]                ',num2str(inc)])
disp(['long. o.t. asc. node [deg]       ',num2str(lan)])
disp(['initial mean anomaly [deg]       ',num2str(man)])
disp(['eccentricity [-]                 ',num2str(ecc)])
disp(['argument of perigee [deg]        ',num2str(aop)])
disp('------------------------------------------------')

inc=inc*pi/180;
lan=lan*pi/180;
aop=aop*pi/180;
man=man*pi/180;

n0=sqrt(GM0/sma^3);
lan_dot=-J2*3*n0*(a_E/sma)^2*cos(inc)/2/(1-ecc^2)^2;
% n1=nor*om_E/nod+(nor/nod-cos(inc))*lan_dot;
n1=nor*om_E/nod-nor/nod*lan_dot;

% aop_dot=J2*3*n1*(a_E/sma)^2*(5*(cos(inc))^2-1)/4/(1-ecc^2)^2;
aop_dot=0;
% m_dot=n1-J2*3*n1*(a_E/sma)^2*(3*(cos(inc))^2-1)/4/(1-ecc^2)^(3/2);
m_dot=n1;
GM1=n1^2*sma^3;

t_rev0=2*pi/n0;
t_rev=2*pi/n1;

if rep==1
    dur_rep=nor*t_rev;
    delta_t=dur_rep/num;
    tim=(0:delta_t:dur*dur_rep)';
else
    tim=(0:num:dur*86400)';
end

disp('DERIVED PARAMETERS')
disp(['rate o.t. asc. node [deg/day]    ',num2str(lan_dot*86400*180/pi)])
% disp(['rate o.t. perigee [deg/day]      ',num2str(aop_dot*86400*180/pi)])
disp(['diff. Trev 0-1 [s]               ',num2str(t_rev0-t_rev)])
disp(['revolution time [s]              ',num2str(t_rev)])
disp(['duration [solar days]            ',num2str(max(tim)/86400)])
disp(['sampling [s]                     ',num2str(tim(2)-tim(1))])
disp('------------------------------------------------')

M=man+m_dot*tim; M=mod(M,2*pi);
E=kepler(M,ecc);
E=mod(E,2*pi);
% ny=atan2(sqrt(1-ecc^2)*sin(E),cos(E)-ecc);
ny=2*atan2(sqrt(1+ecc)*sin(E/2),sqrt(1-ecc)*cos(E/2));
ny=mod(ny,2*pi);

rr=sma*(1-ecc^2)./(1+ecc*cos(ny));
r_b(:,1)=rr.*cos(ny);
r_b(:,2)=rr.*sin(ny);

r_dot_b(:,1)=-sqrt(GM1/sma/(1-ecc^2))*sin(ny);
r_dot_b(:,2)=sqrt(GM1/sma/(1-ecc^2))*(ecc+cos(ny));

lan=lan+lan_dot*tim;
aop=aop+aop_dot*tim;

R11=cos(lan).*cos(aop)-sin(lan)*cos(inc).*sin(aop);
R12=-cos(lan).*sin(aop)-sin(lan)*cos(inc).*cos(aop);
R21=sin(lan).*cos(aop)+cos(lan)*cos(inc).*sin(aop);
R22=-sin(lan).*sin(aop)+cos(lan)*cos(inc).*cos(aop);
R31=sin(inc)*sin(aop);
R32=sin(inc)*cos(aop);

iop(:,1)=R11.*r_b(:,1)+R12.*r_b(:,2);
iop(:,2)=R21.*r_b(:,1)+R22.*r_b(:,2);
iop(:,3)=R31.*r_b(:,1)+R32.*r_b(:,2);
iop(:,4)=R11.*r_dot_b(:,1)+R12.*r_dot_b(:,2);
iop(:,5)=R21.*r_dot_b(:,1)+R22.*r_dot_b(:,2);
iop(:,6)=R31.*r_dot_b(:,1)+R32.*r_dot_b(:,2);

efp=zeros(size(iop));

% the=om_E*(tim+man/m_dot);
the=om_E*tim;
R11=cos(the); R12=sin(the);
R21=-sin(the); R22=cos(the);
efp(:,1)=R11.*iop(:,1)+R12.*iop(:,2);
efp(:,2)=R21.*iop(:,1)+R22.*iop(:,2);
efp(:,3)=iop(:,3);
efp(:,4)=R11.*iop(:,4)+R12.*iop(:,5)+om_E*efp(:,2);
efp(:,5)=R21.*iop(:,4)+R22.*iop(:,5)-om_E*efp(:,1);
efp(:,6)=iop(:,6);

r0=sqrt(efp(1,1)^2+efp(1,2)^2+efp(1,3)^2);
lat0=pi/2-mod(atan2(sqrt(efp(1,1)^2+efp(1,2)^2),efp(1,3)),2*pi);
lon0=mod(atan2(efp(1,2),efp(1,1)),2*pi);
r1=sqrt(efp(end,1)^2+efp(end,2)^2+efp(end,3)^2);
lat1=pi/2-mod(atan2(sqrt(efp(end,1)^2+efp(end,2)^2),efp(end,3)),2*pi);
lon1=mod(atan2(efp(end,2),efp(end,1)),2*pi);
dis_lat=mod(lat1-lat0,2*pi);
dis_lon=mod(lon1-lon0,2*pi);
if dis_lat>pi; dis_lat=dis_lat-2*pi; end
if dis_lon>pi; dis_lon=dis_lon-2*pi; end
cl_dist=sqrt(sum((efp(end,:)-efp(1,:)).^2));

if rep==1
    disp('CLOSED-LOOP DISCREPANCIES')
    disp(['radius [m]                       ',num2str(r1-r0)])
    disp(['latitude [deg]                   ',num2str(dis_lat*180/pi)])
    disp(['longitude [deg]                  ',num2str(dis_lon*180/pi)])
    disp(['distance [m]                     ',num2str(cl_dist)])
    disp('------------------------------------------------')
end

tim=tim(1:end-1);
iop=iop(1:end-1,:);
efp=efp(1:end-1,:);