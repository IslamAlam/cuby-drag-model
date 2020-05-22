function [v] = create_2d_animation(pos_params, cfg, bb, h, size_A, R, v)
%create_2d_animation Creates a 2d animation of the plot of the Bavaria
%areas
h_gt = animatedline('LineStyle', '-', 'Color', 'k');
%h_sl = animatedline;
%h_sr = animatedline;

%% Plot current satellite position with marker
hAx=gca;      % get the axis handle
sz=50;        % size of marker
clr='k';      % color
hS=scatter(hAx,nan,nan,sz,clr);  % initial point won't show but creates handle
hS.Marker = 'square';
hS.MarkerFaceColor = [0 0 0];

%% unpack positional parameters
% ground track
gt_x = pos_params.x;
gt_y = pos_params.y;
% left swath border
swlbx = pos_params.swlbx;
swlby = pos_params.swlby;
% right swath border
swrbx = pos_params.swrbx;
swrby = pos_params.swrby;

alpha = get(h, 'AlphaData');
%%
for k = 1:length(gt_x)
    addpoints(h_gt,gt_x(k),gt_y(k));
    set(hS,'xdata',gt_x(k),'ydata',gt_y(k));
    %addpoints(h_sl, swlbx(k), swlby(k));
    %addpoints(h_sr, swrbx(k), swrby(k));
    if k > 1
        polyx = [swlbx(k-1), swlbx(k), swrbx(k), swrbx(k-1)];
        polyy = [swlby(k-1), swlby(k), swrby(k), swrby(k-1)];
        [I,J] = worldToDiscrete(R,polyx,polyy);
        
        if sum(isnan(I)) == 0 || sum(isnan(J)) == 0
            BW = poly2mask(J, I, size_A(1), size_A(2));
            alpha(find(BW > 0)) = 1; 
            set(h, 'AlphaData', alpha);
        end   
        
    end
    drawnow;
    pause(1/cfg.animation_sampling_rate);
    if cfg.export_movie == true
        cdata = print('-RGBImage','-r900');
        frame = im2frame(cdata);
        writeVideo(v,frame);
    end
   
end
 delete(hS);
end

