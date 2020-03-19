function [] = plot_orbits3D(efp, param,sw_start,sw_end)
%% Cuby Project - Technical University of Munich
%  Purpose: Orbit design
%  Author: Max Helleis
%  Date:   16.03.2020

% plot_orbits3D Plots the orbits in 3d around an Earth model for better
% visualization
%   efp:    Earth-fixed orbit positions
%   param:  Keplerian orbit parameters: [sma, raan, inc, ecc, omega, swathwidth, GSD]

% get position components
posx = efp(:,1);
posy = efp(:,2);
posz = efp(:,3);

% plot the orbit
subplot(2,2,1);
plot3(posx,posy,posz); hold on;
Earth_coast(3);
% hide axis
set(gca,'XColor', 'none','YColor','none', 'ZColor', 'none');
% format plot
fig3d = gca;
title("Orbit in Earth-fixed reference frame");

%% plot orbit information as a table
T = table(param(:), 'VariableNames', "Relevant properties", ...
    'RowNames',{'a [m]:', 'RAAN []:','i []:', 'e:', sprintf('\\omega[]:'), 'Swathwidth [km]', 'GSD [m]', 'Altitude [km]', 'Eclipse time [s]', 'Orbital period [s]'});
% Get the table in string form.
TString = evalc('disp(T)');
% Use TeX Markup for bold formatting and underscores.
TString = strrep(TString,'<strong>','\bf');
TString = strrep(TString,'</strong>','\rm');
TString = strrep(TString,'_','\_');
% Get a fixed-width font.
FixedWidth = get(0,'FixedWidthFontName');
% Output the table using the annotation command.
ann = annotation(gcf,'Textbox','String',TString,'Interpreter','Tex',...
    'FontName',FixedWidth,'Units','Normalized','Position',[0.5 0.75 0.1 0.1]);
ann.LineStyle = 'None';

%% define bavaria bound box
lat_min = 46;
lat_max = 52;
long_min = 8;
long_max = 15;

%% Convert to lat lon
lon=rad2deg(atan2(efp(:,2),posx));
lat=rad2deg(atan(posz./(posx.^2+posy.^2).^0.5));

sw_start_lon=rad2deg(atan2(sw_start(:,2),sw_start(:,1)));
sw_start_lat=rad2deg(atan(sw_start(:,3)./(sw_start(:,1).^2+sw_start(:,2).^2).^0.5));

sw_end_lon=rad2deg(atan2(sw_end(:,2),sw_end(:,1)));
sw_end_lat=rad2deg(atan(sw_end(:,3)./(sw_end(:,1).^2+sw_end(:,2).^2).^0.5));

ind = find(lat > lat_min & lat < lat_max & lon > long_min & lon < long_max);

sw_lon = [sw_start_lon(ind) sw_end_lon(ind)];
sw_lat = [sw_start_lat(ind) sw_end_lat(ind)];

%% Plot swath over bavaria  
subplot(2,2,3:4);
plot(lon(ind),lat(ind),'.');hold on;
for i = 1:length(sw_lon)
    plot(sw_lon(i,:),sw_lat(i,:),'Color',[0,0,0,0.5]);
    hold on;
end
Bavaria_border(2);
xlim([long_min long_max])
ylim([lat_min lat_max])
title('Ground swath over Bavaria (WGS)');

end
