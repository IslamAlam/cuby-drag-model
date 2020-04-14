%% Cuby Project - Technical University of Munich
%  Purpose: Generation Ground Track Shift Over Time
%  Author: Yvonne Ip
%  Date:   07.04.2020
%  Input:  K_days,N_tracks,del_lambdarev
%  Output:  groundtrackshift_info (Cols:
%           n_rev- no of rev
%           t_day- day fraction
%           del_lambda_nrev)
%--------------------------------------------------------------------------

function [groundtrackshift_info] = GroundTrackShiftOverTime(K_days,N_tracks,del_lambdarev)

max_shift = 4;

n_rev = (1:N_tracks)';
t_day = n_rev.*(K_days/N_tracks);
del_lambda_nrev = rem((n_rev-1).*del_lambdarev,360);
observable_inc = del_lambda_nrev<=max_shift;
observable_dec = (del_lambda_nrev-360>=(-max_shift));

groundtrackshift_info = table(n_rev,t_day,del_lambda_nrev,observable_inc,observable_dec);

ind = find(groundtrackshift_info.observable_inc==1 | groundtrackshift_info.observable_dec==1 );

%display useful revolution
groundtrackshift_info(ind,1:3)

end

