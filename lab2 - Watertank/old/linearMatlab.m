

%% **********************************************************************
% Clean up
% ***********************************************************************
clear;
close all;
clc;


%% Define input data

v_out = [2.7,3,3.3,3.7,4];
v_data1 = [0.1,0.19,0.44,0.64,0.9]; % measured steady-state output voltage in V
h_data1 = [8,30,54,84,112]; % measured steady-state height in mm

v_data2 = [0.14,0.19,0.4,0.56,0.8]; % measured steady-state output voltage in V
h_data2 = [14,31,50,79,94]; % measured steady-state height in mm

%% Fit 1
% p = polyfit(v_data1, h_data1, 1)
% 
% figure(1)
% hold on
% plot(v_data1, p(1)*v_data1 +p(2))
% plot(v_data1, h_data1, 'o')
% hold off

%% Use Fit 2
p = polyfit(v_data2, h_data2, 1)

%%Plot
figure(2)
hold on
plot(v_data2, p(1)*v_data2 +p(2))
plot(v_data2, h_data2, 'o')
hold off

%% Modelling
roh = 1000; % [kg/m^3]
At = 50; % [cm^2]
Aout = 25 % [mm^2]
zeta = 0.05;
g = 9.81; % [m/s^2]

