%% Cuby Project - Technical University of Munich
%  Purpose: compute downlink window
%  Author: Yvonne Ip
%  Date:   12.05.2020
%  Input:  efp (Position and Velocity vector in earth-fixed coordinate [x,y,z])
%          tim (time vector, starting with zero [s])
%          lat_gs (latitude of ground station [degrees])
%          lon_gs (latitude of ground station [degrees])
%          mask_angle (mask_angle of downlink window [degrees])
%  Output: dl_win (Downlink window in [s])
%          pass_no (number of pass)
%--------------------------------------------------------------------------


function [dl_win,pass_no] = downlink(efp,tim,lat_gs,lon_gs,mask_angle)

	[r_topo,azi,ele] = efix2topo(efp(:,1:3),lat_gs,lon_gs);

	pass_ind = find(ele > mask_angle);
	if length(pass_ind)==0
		dl_win=0;
		pass_no=0;
	else
		di = diff(pass_ind);
		next_pass = find(di > 1);
		pass_no=length(next_pass)+1;
		dl_win = zeros(pass_no,1);
		start=1;
		for pass = 1:pass_no
			if pass == pass_no
			 dl_win(pass) = range(tim(pass_ind(start:end)));
			else
			 dl_win(pass) = range(tim(pass_ind(start:next_pass(pass))));
			 start = next_pass(pass)+1;
			end
		end
	end

end

