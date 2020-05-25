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
        v = VideoWriter(cfg.movie_name,'Motion JPEG AVI');
        v.Quality = 90;
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
    [h1] = plot_DTM(bounding_box)
    ax_bav = gca()
    offset = 50e3;
    xlim([x_min + offset,  x_max - offset])
    ylim([y_min +  offset, y_max - offset])
    xlabel('x [m]');
    ylabel('y [m]');
    Bavaria_border('UTM');
    title('Ground swath over Bavaria (UTM32N)');
end
if cfg.plot_animation == true
    figure(f_anim);
    [h2, size_A, R] = plot_DTM(bounding_box)
    Bavaria_border('UTM');
    ax_bav_anim = gca();
    offset = 50e3;
    xlim([x_min + offset,  x_max - offset])
    ylim([y_min +  offset, y_max - offset])
    xlabel('x [m]');
    ylabel('y [m]');
    title('Ground swath over Bavaria - animation (UTM32N)');
    if cfg.plot_dynamic_DTM == true
        alpha = zeros(size_A(1), size_A(2));
        set(h2, 'AlphaData', alpha);
    end
end
% loop over all satellites
for num_sat = 1:cfg.num_sats
   
    posx = satellites.('s' + string(num_sat)).efp(:,1);
    posy = satellites.('s' + string(num_sat)).efp(:,2);
    posz = satellites.('s' + string(num_sat)).efp(:,3);
    %Convert x,y,z to longitude and latitude
	[lat,lon] = efix2latlon(satellites.('s' + string(num_sat)).efp);
    % lon=rad2deg(atan2(posy,posx));
    % lat=rad2deg(atan(posz./(posx.^2+posy.^2).^0.5));
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
        [sw_dir,sw_start,sw_end] = swath(satellites.('s' + string(num_sat)).efp,sensor.sw);
        [sw_start_lat,sw_start_lon] = efix2latlon(sw_start);
        [sw_start_x, sw_start_y] = wgs2utm(sw_start_lat,sw_start_lon,32,'N');
        [sw_end_lat,sw_end_lon] = efix2latlon(sw_end);
        [sw_end_x, sw_end_y] = wgs2utm(sw_end_lat,sw_end_lon,32,'N');

        ind = find(lat > lat_min & lat < lat_max & lon > long_min & lon < long_max);
        sw_lon = [sw_start_lon(ind) sw_end_lon(ind)];
        sw_lat = [sw_start_lat(ind) sw_end_lat(ind)];
        sw_x = [sw_start_x(ind) sw_end_x(ind)];
        sw_y = [sw_start_y(ind) sw_end_y(ind)];
        color = [0 0 0];

        if cfg.plot2d_bav == true
                figure(f_bav);
                axes(ax_bav)
        end
        pos_params = plot_swath(ground_track, bounding_box, color, sensor, coe, cfg); hold on; 
     
        if cfg.plot_animation == true
           figure(f_anim); 
           axes(ax_bav_anim)
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

%% Legends
axes(ax_bav);
legend("Ground track", "Ground swath", "Overlap");
% Arrange all figures
if cfg.export_movie == true
    close(v);
end
autoArrangeFigures();


end

