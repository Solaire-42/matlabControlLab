%% Clean up
clear all
close all
clc

%% Daten

data.ist.t = importdata('meassure.mat').v_sensor.time;
data.ist.y = importdata('meassure.mat').v_sensor.data;
data.step.t = importdata('meassure.mat').v_fan.time;
data.step.y = importdata('meassure.mat').v_fan.data;

% Plot
figure('Name', 'Raw Data', 'NumberTitle', 'off');
% raw data
plot(data.ist.t, data.ist.y, 'r')
grid on
hold on
% Data fitted
plot(data.step.t, data.step.y, 'b')
hold on
xlabel('Voltage U/V');
ylabel('Height h/m');
legend({'Raw Data','Data fitted'},'Location','southeast')

%% Trimming

idx_1 = 122244;
idx_2 = 126000; 
dt = 2e-3;
data.istTrimmed.t = [0:idx_2-idx_1]'*dt;
data.istTrimmed.y = data.ist.y(idx_1:idx_2);
data.stepTrimmed.t = [0:idx_2-idx_1]'*dt;
data.stepTrimmed.y = data.step.y(idx_1:idx_2);

% Plot
figure('Name', 'Trimming', 'NumberTitle', 'off');
% raw data
plot(data.istTrimmed.t, data.istTrimmed.y, 'r')
grid on
hold on
% Data fitted
plot(data.stepTrimmed.t, data.stepTrimmed.y, 'b')
hold on
xlabel('Voltage U/V');
ylabel('Height h/m');
legend({'Raw Data','Data fitted'},'Location','southeast')

%% Nomalisieren

% Offset
data.istNorm.y = data.istTrimmed.y-min(data.istTrimmed.y);

% Normalize
idx_1 = 1876;
idx_2 = 3757; 

data.istNorm.y = data.istNorm.y/mean(data.istNorm.y(idx_1:idx_2));
data.istNorm.t = data.istTrimmed.t;

data.stepNorm.y = data.stepTrimmed.y/max(data.stepTrimmed.y);
data.stepNorm.t = data.stepTrimmed.t;

% Plot
figure('Name', 'Normalisieren', 'NumberTitle', 'off');
% raw data
plot(data.istNorm.t, data.istNorm.y, 'r')
grid on
hold on
% Data fitted
plot(data.stepNorm.t, data.stepNorm.y, 'b')
hold on
xlabel('Voltage U/V');
ylabel('Height h/m');
legend({'Raw Data','Data fitted'},'Location','southeast')

%% Fitting

data.fitting.Para.a=1;
data.fitting.Para.b=2;
data.fitting.Para.c=0.8;

data.fitting.coeff = lsqcurvefit(@unit_step_PT2, [data.fitting.Para.a data.fitting.Para.b data.fitting.Para.c], data.istNorm.t, data.istNorm.y);

% plot PT2 Fitting
figure('Name', 'PT2 Fitting', 'NumberTitle', 'off');
% raw data
plot(data.istNorm.t, data.istNorm.y, 'r')
grid on
hold on
% PT2 fitted
plot(data.istNorm.t, unit_step_PT2(data.fitting.coeff, data.istNorm.t), 'b')
hold on
xlabel('time t/s');
ylabel('Voltage U/V');
legend({'Raw Data','PT2 fitted'},'Location','southeast')

