function rop=RepOrbParam(hr,ndr,i,ae,gm,j2,oe,od,cr,mi)
%RepOrbParam    Repeat orbit parameters for altitude range and number of
%   nodal day range
%
%rop=RepOrbParam(hr,ndr,i,ae,gm,j2,oe,od,cr,mi)
%
%IN
%   hr  Altitude range [km], [h_min,h_max]
%   ndr Number of day range [days], [d_min,d_max]
%   i   inclination [deg] or 's' for sun-synchronous, default: 90
%   ae  Earth's semi-major axis [m], default: 6378137
%   gm  Geocentric gravytational constant [m^3/s^2], default: 3.986005e14
%   j2  Earth's dynamic form factor [-], default: 1.08263e-3
%   oe  Mean angular velocity [rad/s], default: 7.292115e-5
%   od  Sun-synchronous node rate [rad/s], default: 1.991063611e-7
%   cr  a-iteration break criterion [m], default: 1e-3
%   mi  max. number of iterations, default: 100
%
%OUT
%   rop Repeat orbit parameters, (n,7)-matrix [nd,nr,h,i,a,tr,td]
%       nd  Number of days
%       nr  Number of revolutions
%       h   Altitude [km]
%       i   Inclination [deg]
%       a   Semi-major axis [m]
%       tr  Revolution time [s]
%       td  Nodal day length [s]
%
%IAPG, Murboeck, 2013 Sep 20

if nargin<10 || isempty(mi), mi=100; end
if nargin<9 || isempty(cr), cr=1e-3; end
if nargin<8 || isempty(od), od=1.991063611e-7; end
if nargin<7 || isempty(oe), oe=7.292115e-5; end
if nargin<6 || isempty(j2), j2=1.08263e-3; end
if nargin<5 || isempty(gm), gm=3.986005e14; end
if nargin<4 || isempty(ae), ae=6378137; end
if nargin<3 || isempty(i), i=90; end

do_sunsync=0;
if strcmpi(i,'s'), do_sunsync=1; disp('sun-synchronous'), end

if numel(ndr)~=2 || min(ndr)<0 || numel(hr)~=2 || min(hr)<0
    error('hr and ndr must have two positive elements each')
end

h_ext=100;
al=ae+[max(min(hr)-h_ext,0),max(hr)+h_ext]*1e3;
nl=sqrt(gm./al.^3);
f=-3/4*nl.*j2*ae^2./al.^2;
if do_sunsync
    il=acosd(-2/3*(al).^(7/2)*od/sqrt(gm)/j2/ae^2);
    omd=f.*(1-5*(cosd(il)).^2);
    dn=f.*(1-3*(cosd(il)).^2);
else
    od=2*f*cosd(i);
    omd=f.*(1-5*(cosd(i))^2);
    dn=f.*(1-3*(cosd(i))^2);
end

% max_nr=max(ceil(max(ndr)*(dn+nl+omd)./(oe-od)));
nd_vec=min(ndr):max(ndr);
rop=[]; n_orb=0;
for n=1:length(nd_vec)
    d_tmp=nd_vec(n);
    min_r=max(1,floor(min(d_tmp*(dn+nl+omd)./(oe-od))));
    max_r=ceil(max(d_tmp*(dn+nl+omd)./(oe-od)));
    if n==1, min_r=max(1,min_r);
    else min_r=max(d_tmp+1,min_r); end
    id_d=[IntegerDivisors(d_tmp),d_tmp];
    for r=min_r:max_r
        id_r=[IntegerDivisors(r),r];
        ism_d=ismember(id_d,id_r);
        if max(ism_d)==0
            % iteration for (d_tmp,r)-->a
            if do_sunsync
                TN0=d_tmp/r*86400;   % initial revolution time [s]
                n0_tmp=2*pi/TN0;            % initial mean motion [rad/s]
                a0_tmp=(gm/n0_tmp^2)^(1/3);     % initial semi-major axis [m]
                i0_tmp=acosd(-2/3*(a0_tmp)^(7/2)*od/sqrt(gm)/j2/ae^2);
                
                da_tmp=cr+1; num_iter=0;
                while da_tmp>cr
                    f_tmp=-3/4*n0_tmp*j2*ae^2/a0_tmp^2;
                    omd_tmp=f_tmp*(1-5*(cosd(i0_tmp))^2);
                    dn_tmp=f_tmp*(1-3*(cosd(i0_tmp))^2);

                    n0_tmp=2*pi*r/d_tmp/86400-dn_tmp-omd_tmp;
                    a1_tmp=(gm/n0_tmp^2)^(1/3);     % initial semi-major axis [m]
                    i0_tmp=acosd(-2/3*(a1_tmp)^(7/2)*od/sqrt(gm)/j2/ae^2);

                    da_tmp=abs(a0_tmp-a1_tmp);
                    num_iter=num_iter+1;
                    a0_tmp=a1_tmp;
                    if num_iter>mi
                        disp(['max iter (',num2str(d_tmp),',',num2str(r)],')')
                        break
                    end
                end
                h_tmp=(a1_tmp-ae)/1e3;
                
                f_tmp=-3/4*n0_tmp*j2*ae^2/a0_tmp^2;
                od_tmp=2*f_tmp*cosd(i0_tmp);
                omd_tmp=f_tmp*(1-5*(cosd(i0_tmp))^2);
                dn_tmp=f_tmp*(1-3*(cosd(i0_tmp))^2);
                tr_tmp=2*pi*d_tmp/r/(oe-od_tmp);
                td_tmp=2*pi/(oe-od_tmp);
                tr2_tmp=2*pi/(dn_tmp+n0_tmp+omd_tmp);
%                 tr2_tmp=2*pi/n0_tmp;
            else
                TN0=d_tmp/r*86400;   % initial revolution time [s]
                n0_tmp=2*pi/TN0;            % initial mean motion [rad/s]
                a0_tmp=(gm/n0_tmp^2)^(1/3);     % initial semi-major axis [m]

                da_tmp=cr+1; num_iter=0;
                while da_tmp>cr
                    f_tmp=-3/4*n0_tmp*j2*ae^2/a0_tmp^2;
                    od_tmp=2*f_tmp*cosd(i);
                    omd_tmp=f_tmp*(1-5*(cosd(i))^2);
                    dn_tmp=f_tmp*(1-3*(cosd(i))^2);

                    n0_tmp=r/d_tmp*(oe-od_tmp)-dn_tmp-omd_tmp;
                    a1_tmp=(gm/n0_tmp^2)^(1/3);
                    da_tmp=abs(a0_tmp-a1_tmp);
                    num_iter=num_iter+1;
                    a0_tmp=a1_tmp;
                    if num_iter>mi, disp('max iter'), break, end
                end
                h_tmp=(a1_tmp-ae)/1e3;
                f_tmp=-3/4*n0_tmp*j2*ae^2/a0_tmp^2;
                od_tmp=2*f_tmp*cosd(i);
                omd_tmp=f_tmp*(1-5*(cosd(i))^2);
                dn_tmp=f_tmp*(1-3*(cosd(i))^2);
                tr_tmp=2*pi*d_tmp/r/(oe-od_tmp);
                td_tmp=2*pi/(oe-od_tmp);
                tr2_tmp=2*pi/(dn_tmp+n0_tmp+omd_tmp);
            end
            if h_tmp>=min(hr) && h_tmp <=max(hr)
                n_orb=n_orb+1;
                if do_sunsync
                    rop(n_orb,:)=[d_tmp,r,h_tmp,i0_tmp,a0_tmp,tr_tmp,td_tmp,tr2_tmp];
                else
                    rop(n_orb,:)=[d_tmp,r,h_tmp,i,a0_tmp,tr_tmp,td_tmp,tr2_tmp];
                end
            end
        end
    end
end

% rop1=rop;
% rop=[];
% for i=1:size(rop1,1)
%     d_tmp=rop1(i,1); r_tmp=rop1(i,2);
%     if d_tmp>2
%         rem_d_tmp=rem(d_tmp,[2:d_tmp-1]);
%         rem_r_tmp=rem(r_tmp,[2:d_tmp-1]);
%     elseif d_tmp==2
%         
%     else
%         
%     end
%     
% end

end