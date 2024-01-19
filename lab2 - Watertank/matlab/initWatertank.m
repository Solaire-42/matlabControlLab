%% Clean up
close all;
clear;
clc;


%% System parmeter
data.roh        = 1000; % kg/m³
data.At         = 50;   % cm²
data.Aout       = 25;   % mm²
data.zeta       = 0.05;
data.g          = 9.81; % m/s²
data.initHeight = 0.1;  % cm
data.a          = sqrt(2*data.g/(1+data.zeta))*data.Aout/data.At;


%% Control paramters (fixed-point and trajectory)
data.Controller.A = [0 1; 0 0];
data.Controller.B = [0;1];
data.Controller.C = [1 0];

% Pole-locations for controller parameters
% We want a second order critically damped system -> 2 poles
% Therefore we need one double pole for critically damped
poles = [complex(-0.2,0),complex(-0.2,0)];
% We can use Ackerman, because system is stable (rank(ctrb(c.A,c.B)) == size(c.A,1))
data.Controller.K = acker(data.Controller.A, data.Controller.B,poles);

% calculate prefilter necessary for fixed point control
data.Controller.N = -1/(data.Controller.C*inv(data.Controller.A-data.Controller.B*data.Controller.K)*data.Controller.B);


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
