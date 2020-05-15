function [] = plot_swath(ground_track, bounding_box, color, sw, inc, groundtracks, num_sat)
%plot_swath Plots the swath of a satellite over a certain ROI
%   Arguments
%       ground_track    -- [x,y] coordinates of the satellite groundtrack (UTM)
%       bounding_box    -- [x_min, x_max; y_min, y_max] defines ROI (UTM)
%       color           -- [c1 c2 c3] RGB array containing color
%       sw              -- swathwidth [meter]
%       inc             -- inclination [�]
%   Return
%       None
x = ground_track(:,1);
y = ground_track(:,2);
x_min = bounding_box(1,1);
x_max = bounding_box(1,2);
y_min = bounding_box(2,1);
y_max = bounding_box(2,2);

% find ground track coordinates in the bounding box
x_bb_indices = find((x > x_min) & (x < x_max));
y_bb_indices = find((y > y_min) & (y < y_max));
bb_indices = intersect(x_bb_indices, y_bb_indices);


% find the array elements that belong to different orbital revolutions
di = diff(bb_indices);
next_rev = find(di > 1);
rev_no=length(next_rev)+1;
if isempty(next_rev)
    % next_rev = length(di);
    rev_no=1;
end
% plot ground tracks (figure to plot in should be opened at function call)
start = 1;
for revs = 1:rev_no
    % rev_range = bb_indices(start+1:next_rev(revs));
	if revs == rev_no
     rev_range = bb_indices(start:end);
	else
	 rev_range = bb_indices(start:next_rev(revs));
	 start = next_rev(revs)+1;
	end
    
    % get borders of the swath for plotting
    [swlbx, swlby, swrbx, swrby] = getSwathBorder(sw, x(rev_range), y(rev_range), inc);
    
    plot(x(rev_range), y(rev_range), '--', 'Color', color); hold on;
    plot(swlbx,swlby,'-','Color', color);
    plot(swrbx,swrby,'-','Color', color);

    % start = next_rev(revs);

end

end

