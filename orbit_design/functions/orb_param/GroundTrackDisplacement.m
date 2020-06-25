%% Cuby Project - Technical University of Munich
%  Purpose: Compute the groundtrack difference in m of 2 groundtracks inside the Bavaria boundbox
%  Author: Yvonne Ip
%  Date:   16.06.2020
%  Input:  efp1 (Position vector in earth-fixed coordinate [x,y,z])
%          efp2  (Position vector in earth-fixed coordinate [x,y,z])
%
%  Output:  x_disp acs_discp
%--------------------------------------------------------------------------


function [x_disp acs_discp] = efix2topo(efp1,efp2)
	% define bavaria bound box (for plotting and choice of points)
	lat_min = 46 ;
	lat_max = 52 ;
	long_min = 8 ;
	long_max = 15 ;

	% convert to latlon
	[lat1,lon1] = efix2latlon(efp1);
	[lat2,lon2] = efix2latlon(efp2);
	
	ind1 = find(lat1 > lat_min & lat1 < lat_max & lon1 > long_min & lon1 < long_max);
	ind2 = find(lat2 > lat_min & lat2 < lat_max & lon2 > long_min & lon2 < long_max);
	
	if isempty(ind1) || isempty(ind2)
		error('Empty Index');
	end
	
	di1 = diff(ind1);
	next_pass1 = find(di1 > 1);
	di2 = diff(ind2);
	next_pass2 = find(di2 > 1);
	
	length(next_pass2)
	if length(next_pass1)~=length(next_pass2)
		error('The 2 groundtracks have different number of passes');
	end
	
	x_disp = zeros(length(next_pass1)+1,1);
	acs_discp = zeros(length(next_pass1)+1,1);
	start1=1;
	start2=1;
	
	length(next_pass2)
	
	for i = 1:length(x_disp)
		
		if i==length(x_disp)
			pass1=ind1(start1:end);
			pass2=ind2(start2:end);
		else
			pass1=ind1(start1:next_pass1(i));
			pass2=ind2(start2:next_pass2(i));
			start1=next_pass1(i)+1;
			start2=next_pass2(i)+1;
		end

		[start1_x,start1_y] = wgs2utm(lat1(pass1(1)),lon1(pass1(1)),32,'N');
		[end1_x,end1_y] = wgs2utm(lat1(pass1(end)),lon1(pass1(end)),32,'N');
		
		[start2_x,start2_y] = wgs2utm(lat2(pass2(1)),lon2(pass2(1)),32,'N');
		[end2_x,end2_y] = wgs2utm(lat2(pass2(end)),lon2(pass2(end)),32,'N');
		
		coeff = polyfit([start2_x, end2_x], [start2_y, end2_y], 1);
		s2 = coeff(1); c2 = coeff(2); 
		
		mid1_y = (start1_y+end1_y)/2; mid1_x = (start1_x+end1_x)/2; 
		mid2_y = mid1_y; mid2_x = (mid2_y - c2)/s2;
		
		% Displacement in UTM x direction
		x_disp(i) = abs(mid2_x-mid1_x);
		
		
		% Displacement in Acrosstrack direction
		s1=(end1_y-start1_y)/(end1_x-start1_x); %in flight direction
		s1 = -1/s1; % acs-track direction
		c1 = mid1_y - mid1_x*s1; % pass through mid-pt
		
		% Find intersection of lines (s1,c1) & (s2,c2)
		x_intsc = (c2-c1)/(s1-s2);
		y_intsc = s1*x_intsc+c1;
		acs_discp(i) = pdist([mid1_x,mid1_y;x_intsc,y_intsc]);
		
		
		
	end
	
end