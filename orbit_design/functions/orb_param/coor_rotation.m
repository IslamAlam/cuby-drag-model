%% Cuby Project - Technical University of Munich
%  Purpose: create 2/3d coor_rotation matrix for coordinate changing.
%  Author: Yvonne Ip
%  Date:   21.03.2020
%  Input:  dim (dimensional:2/3)
%          angle (in radian)
%          axis:1=x, 2=y, 3=z
%  Output:  Rotation matrix
%  Note: 2D = rotation along z-axis, regardless input for axis
%--------------------------------------------------------------------------


function [rot_matrix] = coor_rotation(dim,angle,axis)
	if dim==2
		rot_matrix = [cos(angle) sin(angle);-sin(angle) cos(angle)];
	elseif dim==3
		rot_matrix=eye(3);
		rot=[cos(angle) sin(angle);-sin(angle) cos(angle)];
		if axis==1
			rot_matrix(2:3,2:3)=rot;
		elseif axis==2
			rot_matrix([1 3],[1 3])=rot;
		elseif axis==3
			rot_matrix(1:2,1:2)=rot;
		else
			error('Wrong axis.');
		end
	else
		error('Wrong dim.');
	end
end