function [h, size_A, R] = plot_DTM(bounding_box)
%plot_DTM Plots the DTM of Bavaria
% unpack bounding_box
x_min = bounding_box(1,1);
x_max = bounding_box(1,2);
y_min = bounding_box(2,1);
y_max = bounding_box(2,2);

filename = 'data/TandemX_DTM_extended.tif'; 
[A,R,cmap] = readgeoraster(filename);
cmap = demcmap([100, 100], 2048);
% set cmap for value 0 to white
cmap(1,:) = ones(1,3);
h = mapshow(A,cmap,R); hold on;
xlim([x_min x_max])
ylim([y_min y_max])
set(gca,'xtick',[], 'ytick', [], 'ztick', []);
set(gca,'XColor', 'none','YColor','none', 'ZColor', 'none');

size_A = size(A);
end

