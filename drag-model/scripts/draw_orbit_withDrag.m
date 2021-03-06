clear all
close all

% load data
data = load('C:/C_Drive/Work/Data/height_withNRMLSISE.mat');
orbit_h = data.data{3}{3}.Values;
t = orbit_h.time/86400; % day
h = orbit_h.data;

% exclude unavailable data 
h_limit = 1000; % set height limit
loc = find(h>h_limit);
%t(loc) = NaN;
h(loc) = 0;

% moving ave.
k = 86400; % k-point mean value !! change here !!
h_ave = movmean(h,k); % introduce moving average to make curve smooth
%h_ave = h;

% define time period
day_start = 1; % !! change here !!
day_end = 250; % !! change here !!
t_start = (day_start-1)*86400+1;
t_end = (day_end)*86400;

% plot
plot(t(t_start:t_end),h_ave(t_start:t_end));
title('Orbital height with NRL MSISE-00 (moving ave. = 86400 pt)');
xlabel('time (day)');
ylabel('height (km)');
xlim([0 day_end]);
ylim([0 430]);
