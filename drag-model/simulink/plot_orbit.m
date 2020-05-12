clear all
close all
% This program is for plotting the orbital decay, without thruster
% condition. I will integrate the with thruster condition later.
% Please change the following part when using this program:
% 1. filename
% 2. title of the plot
% After checking the plot is correct, save it 

% load data
filename = 'C:/C_Drive/Work/Orbit_data_plot/0420_NewCases/352box.mat'; %!! change
data = load(filename);
t = data.time; % sample: every 60 sec.
h = data.signals.values;

% increase data points after program terminated (for moving ave. visualization)
t_extend = length(t)*60:60:(length(t)+300)*60;
h_extend = interp1(t(end-100:end),h(end-100:end),t_extend,'liner','extrap')

t = [t; t_extend'];
h = [h; h_extend'];


% find entry point
loc = find(h <= 100);
enrty_day = fix(t(loc(1))/86400); % 
entry_str= num2str(enrty_day);

% moving ave.
k = 1440; % k-point mean value
h_ave = movmean(h,k); % introduce moving average to make curve smooth
h_ave(h_ave < 0) = 0;


% plot
plot(t/86400,h_ave);
title(['Orbital height, Reentry: after ',entry_str,' days ( initial: 352.72km, box model)'],'FontSize', 10); %!! change
xlabel('time (day)');
ylabel('height (km)');
%xlim([0 day_end]);
%ylim([0 400]);

%saveas(gcf,'352box.png')