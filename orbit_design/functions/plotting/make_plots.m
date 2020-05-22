function [] = make_plots(satellites, cfg, coe, const, sensor)
%make_plots Generates 3D and 2D plots of the orbits and their groundtracks
%   :param: satellites: Struct containing position and velocity for all
%   satellites
%   :param: coe: Struct containing constant orbital parameters of the orbit
%   :const: const: Struct containing the physical constants to use

if cfg.plot3d == true
    f_3d = figure(1); % handle to fig containing 3d plot
end
if cfg.plot2dww == true
    f_gt = figure(2); % handle to fig containing ground track
end
if cfg.plot2d_bav == true
    f_bav = figure(3); % handle to fig containing ground track over Bavaria
end
if cfg.plot_animation == true
    f_anim = figure(4); % handle to fig containing ground track over Bavaria
    if cfg.export_movie == true
        v = VideoWriter(cfg.movie_name,'Motion JPEG 2000');
        v.MJ2BitDepth = 8;
        %v.Quality = 95;
        open(v);
    else
        v = [];
    end
end

% define bounding box for Bavaria plot
lat_min = 46.7;
lat_max = 51;
long_min = 8;
long_max = 15;
[x_min,y_min] = wgs2utm(lat_min,long_min,32,'N');
[x_max,y_max] = wgs2utm(lat_max,long_max,32,'N');
bounding_box = [x_min, x_max; y_min, y_max];

% Initialize background for Bavaria plot
if cfg.plot2d_bav == true
    figure(f_bav);
    ax_bav = gca()
    [h1] = plot_DTM(bounding_box)
end
if cfg.plot_animation == true
    figure(f_anim);
    [h2, size_A, R] = plot_DTM(bounding_box)
    Bavaria_border('UTM');
    ax_bav_anim = gca();
    alpha = zeros(size_A(1), size_A(2));
    set(h2, 'AlphaData', alpha);
end
% loop over all satellites
for num_sat = 21:23%cfg.num_sats
   
    posx = satellites.('s' + string(num_sat)).efp(:,1);
    posy = satellites.('s' + string(num_sat)).efp(:,2);
    posz = satellites.('s' + string(num_sat)).efp(:,3);
    %Convert x,y,z to longitude and latitude
    lon=rad2deg(atan2(posy,posx));
    lat=rad2deg(atan(posz./(posx.^2+posy.^2).^0.5));
    % 3d orbit plot
    if cfg.plot3d == true
        figure(f_3d);
        plot3(posx,posy,posz); hold on;
        if num_sat == length(cfg.num_sats)
            Earth_coast(3);
            ax_3d = gca();
        end
    end
    if cfg.plot2dww == true
        % 2d ground track worldwide
        figure(f_gt); 
        plot(lon,lat,'.');hold on;
        if num_sat == length(cfg.num_sats)
            Earth_coast(2);
            Bavaria_border(2);
            ax_gt = gca();
        end
    end
    if cfg.plot2d_bav == true || cfg.plot_animation == true
        % 2d ground track and swath over Bavaria
        [x y] = wgs2utm(lat,lon,32,'N');
        ground_track = [x, y];
        [sw_dir,sw_start,sw_end,sw_start_lon,sw_start_lat,sw_end_lon,sw_end_lat] = swath(satellites.('s' + string(num_sat)).efp,sensor.sw);
        sw_start_lon=rad2deg(atan2(sw_start(:,2),sw_start(:,1)));
        sw_start_lat=rad2deg(atan(sw_start(:,3)./(sw_start(:,1).^2+sw_start(:,2).^2).^0.5));
        [sw_start_x, sw_start_y] = wgs2utm(sw_start_lat,sw_start_lon,32,'N');
        sw_end_lon=rad2deg(atan2(sw_end(:,2),sw_end(:,1)));
        sw_end_lat=rad2deg(atan(sw_end(:,3)./(sw_end(:,1).^2+sw_end(:,2).^2).^0.5));

        [sw_end_x, sw_end_y] = wgs2utm(sw_end_lat,sw_end_lon,32,'N');

        ind = find(lat > lat_min & lat < lat_max & lon > long_min & lon < long_max);
        sw_lon = [sw_start_lon(ind) sw_end_lon(ind)];
        sw_lat = [sw_start_lat(ind) sw_end_lat(ind)];
        sw_x = [sw_start_x(ind) sw_end_x(ind)];
        sw_y = [sw_start_y(ind) sw_end_y(ind)];
        color = [0 0 0];

        if cfg.plot2d_bav == true
                figure(f_bav);
        end
        pos_params = plot_swath(ground_track, bounding_box, color, sensor, coe, cfg); hold on; 
     
        if cfg.plot_animation == true
           figure(f_anim); 

           v = create_2d_animation(pos_params, cfg, bounding_box, h2, size_A, R, v)
           
        end
       
    end
end
%% Format plots
if cfg.plot3d == true
    % 3d
    axes(ax_3d);
    title("Orbit in Earth-Fixed Reference Frame");
    set(gca,'xtick',[], 'ytick', [], 'ztick', []);
    set(gca,'XColor', 'none','YColor','none', 'ZColor', 'none');
end
if cfg.plot2dww == true
    % 2d ground track worldwide 
    axes(ax_gt);
    xlabel('Longtitude [°]');
    ylabel('Latitude [°]');
    title('Ground track worldwide (WGS84)');
    grid on;
end
if cfg.plot2d_bav == true
    % groundtrack over Bavaria
    axes(ax_bav);
    xlim([x_min x_max])
    ylim([y_min y_max])
    xlabel('x [m]');
    ylabel('y [m]');
    title('Ground swath over Bavaria (UTM32N)');
end

if cfg.plot_animation == true
    % groundtrack over Bavaria
    axes(ax_bav_anim);
    xlim([x_min x_max])
    ylim([y_min y_max])
    xlabel('x [m]');
    ylabel('y [m]');
    title('Ground swath over Bavaria (UTM32N)');
end
% Arrange all figures
close(v);
autoArrangeFigures();


end

