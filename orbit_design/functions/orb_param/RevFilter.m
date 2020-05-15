%% Cuby Project - Technical University of Munich
%  Purpose: Return Filtered efp,tim,iop according to specified revolution numbers and period.
%  Author: Yvonne Ip
%  Date:   12.04.2020
%  Input:  efp (Position and Velocity vector in earth-fixed coordinate [x,y,z])
%          tim (time vector, starting with zero [s])
%          iop (Position and Velocity vector in Intial Frame [x,y,z])
%          tr  (revolution period for one orbit [s])
%          rev_no  (array of rev wanted)
%  Output: efp_new
%          tim_new
%          iop_new
%--------------------------------------------------------------------------

function [efp_new,tim_new,iop_new] = RevFilter(efp,tim,iop,tr,rev_no)
[ind,~]=find(tim>= (rev_no-1)*tr & tim<rev_no*tr);
efp_new = efp(ind,:);
tim_new = tim(ind);
iop_new = iop(ind,:);

end

