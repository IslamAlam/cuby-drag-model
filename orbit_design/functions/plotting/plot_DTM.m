function [h, size_A, R] = plot_DTM(bounding_box, cfg)
%plot_DTM Plots the DTM of Bavaria
% unpack bounding_box
x_min = bounding_box(1,1);
x_max = bounding_box(1,2);
y_min = bounding_box(2,1);
y_max = bounding_box(2,2);

if cfg.GermanyAustriaSwitzerland == false
    filename = 'data/TandemX_DTM_extended.tif'; 
    nodata = 0;
elseif cfg.GermanyAustriaSwitzerland == true
    filename = 'SRTM_Austria_Switzerland_Germany_32N_Resampled.tif';
    Germany_shp = shaperead('Germany_border_32N.shp');
    Germany_NUTS_shp = shaperead('Germany_NUTS_L1.shp');
    Austria_shp = shaperead('Austria_border_32N.shp');
    Switzerland_shp = shaperead('Switzerland_border_32N.shp');
    nodata = 5000;
end
[A,R,cmap] = readgeoraster(filename);
cmap = demcmap([100, 100], 2048);
% set cmap for value 0 to white
cmap(nodata + 1,:) = ones(1,3);
h = mapshow(A, cmap, R); hold on;
alpha = get(h, 'AlphaData');
alpha(:) = 0.5;
set(h, 'AlphaData', alpha);
if cfg.GermanyAustriaSwitzerland == true
    lw = 1;
    x_GER = Germany_shp.X;
    y_GER = Germany_shp.Y;
    x_AUT = Austria_shp.X;
    y_AUT = Austria_shp.Y;
    x_SUI = Switzerland_shp.X;
    y_SUI = Switzerland_shp.Y;
    plot(x_GER,y_GER,'-', 'LineWidth', lw, 'Color', [0 0 0],'HandleVisibility','off');
    plot(x_AUT,y_AUT,'-', 'LineWidth', lw, 'Color', [0 0 0 ],'HandleVisibility','off');
    plot(x_SUI,y_SUI,'-', 'LineWidth', lw, 'Color', [0 0 0 ],'HandleVisibility','off');
    for state = 1:length(Germany_NUTS_shp)
          X = Germany_NUTS_shp(state).X;
          Y = Germany_NUTS_shp(state).Y;
          plot(X,Y,'-', 'LineWidth', lw, 'Color', [0 0 0],'HandleVisibility','off');
    end
end


xlim([x_min x_max])
ylim([y_min y_max])
set(gca,'xtick',[], 'ytick', [], 'ztick', []);
set(gca,'XColor', 'none','YColor','none', 'ZColor', 'none');

size_A = size(A);
end

