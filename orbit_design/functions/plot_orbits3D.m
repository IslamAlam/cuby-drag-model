function [] = plot_orbits3D(efp, param)
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
    'RowNames',{'a [m]:', 'RAAN [°]:','i [°]:', 'e:', sprintf('\\omega[°]:'), 'Swathwidth [km]', 'GSD [m]', 'Altitude [km]'});
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

%% Plot swath over bavaria  
subplot(2,2,3:4);
title('Ground swath over Bavaria');

end

