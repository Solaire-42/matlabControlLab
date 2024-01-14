%% Clean up
close all;
clear;
clc;

%% System Parmeter

data.SysPara.roh = 1000 %kg/m³
data.SysPara.At = 50 %cm²
data.SysPara.Aout = 25 %mm²
data.SysPara.zeta = 0.05
data.SysPara.g = 9.81 %m/s²

%% Sensor input data

v_out = [2.7,3,3.3,3.7,4];
data.Sensor.v = [0.14,0.19,0.4,0.56,0.8]; % measured steady-state output voltage in V
data.Sensor.h = [14,31,50,79,94]; % measured steady-state height in mm

%% Fit

data.Sensor.FitPara = polyfit(data.Sensor.v, data.Sensor.h,1)

figure('Name', 'Waterlevel Sensor', 'NumberTitle', 'off');
% raw data
plot(data.Sensor.v, data.Sensor.h, 'r')
grid on
hold on
% Data fitted
plot(data.Sensor.v, data.Sensor.FitPara(1)*data.Sensor.v+data.Sensor.FitPara(2), 'b')
hold on
h_xlabel = xlabel({'$U$\,/\,V'});
set(h_xlabel,'Interpreter','latex')
h_ylabel = ylabel({'$h$\,/\,mm'});
set(h_ylabel,'Interpreter','latex')
legend({'Raw Data','Data fitted'},'Location','southeast')

%% System Identification
