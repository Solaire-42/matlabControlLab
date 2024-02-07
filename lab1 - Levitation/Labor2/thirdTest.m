%% Clean up
clear all
close all
clc

%% Daten

data.ist.t = importdata('meassure.mat').v_sensor.time;
data.ist.y = importdata('meassure.mat').v_sensor.data;
data.step.t = importdata('meassure.mat').v_fan.time;
data.step.y = importdata('meassure.mat').v_fan.data;

% % Plot
% figure('Name', 'Raw Data', 'NumberTitle', 'off');
% % raw data
% plot(data.ist.t, data.ist.y, 'r')
% grid on
% hold on
% % Data fitted
% plot(data.step.t, data.step.y, 'b')
% hold on
% xlabel('Voltage U/V');
% ylabel('Height h/m');
% legend({'Raw Data','Data fitted'},'Location','southeast')

%% Trimming

i_before = 122240;
idx_1 = 122244;
idx_2 = 126000; 
dt = 2e-3;
data.istTrimmed.t = [0:idx_2-idx_1]'*dt;
data.istTrimmed.y = data.ist.y(idx_1:idx_2);
data.stepTrimmed.t = [0:idx_2-idx_1]'*dt;
data.stepTrimmed.y = data.step.y(idx_1:idx_2);

% Normalize Motor
data.GainMotor = data.step.y(idx_1) - data.step.y(i_before);
data.OffsetMotor = data.step.y(i_before); 

% % Plot
% figure('Name', 'Trimming', 'NumberTitle', 'off');
% % raw data
% plot(data.istTrimmed.t, data.istTrimmed.y, 'r')
% grid on
% hold on
% % Data fitted
% plot(data.stepTrimmed.t, data.stepTrimmed.y, 'b')
% hold on
% xlabel('Voltage U/V');
% ylabel('Height h/m');
% legend({'Raw Data','Data fitted'},'Location','southeast')

%% Nomalisieren

% Offset
data.OffsetSensor = min(data.istTrimmed.y);
data.istNorm.y = data.istTrimmed.y-data.OffsetSensor;



% Normalize Sensor
idx_1 = 1876;
idx_2 = 3757; 
data.GainSensor = mean(data.istNorm.y(idx_1:idx_2));

data.istNorm.y = data.istNorm.y/data.GainSensor;
data.istNorm.t = data.istTrimmed.t;

data.stepNorm.y = data.stepTrimmed.y/max(data.stepTrimmed.y);
data.stepNorm.t = data.stepTrimmed.t;

% % Plot
% figure('Name', 'Normalisieren', 'NumberTitle', 'off');
% % raw data
% plot(data.istNorm.t, data.istNorm.y, 'r')
% grid on
% hold on
% % Data fitted
% plot(data.stepNorm.t, data.stepNorm.y, 'b')
% hold on
% xlabel('Voltage U/V');
% ylabel('Height h/m');
% legend({'Raw Data','Data fitted'},'Location','southeast')

%% Fitting

data.fitting.Para.a=1; %k
data.fitting.Para.b=2; %w_n
data.fitting.Para.c=0.8; %zeta

data.fitting.coeff = lsqcurvefit(@unit_step_PT2, [data.fitting.Para.a data.fitting.Para.b data.fitting.Para.c], data.istNorm.t, data.istNorm.y);

% % plot PT2 Fitting
% figure('Name', 'PT2 Fitting', 'NumberTitle', 'off');
% % raw data
% plot(data.istNorm.t, data.istNorm.y, 'r')
% grid on
% hold on
% % PT2 fitted
% plot(data.istNorm.t, unit_step_PT2(data.fitting.coeff, data.istNorm.t), 'b')
% hold on
% xlabel('time t/s');
% ylabel('Voltage U/V');
% legend({'Raw Data','PT2 fitted'},'Location','southeast')


%% State Space Model

[A B C D] = tf2ss(data.fitting.coeff(2)^2, [1 2*data.fitting.coeff(3)*data.fitting.coeff(2) data.fitting.coeff(2)^2]);


%% pole placement for state feedback

data.pp.ss.ts = 4; % in s
data.pp.ss.ps = 5/100; % in %

% calculation of zeta 
data.pp.ss.zeta = sqrt(log(data.pp.ss.ps)^2/(pi^2+log(data.pp.ss.ps)^2));

% calculation of natural frequency
data.pp.ss.w_n = 4/(data.pp.ss.zeta*data.pp.ss.ts);

% calcuate the pole regions complex conjugated:
data.pp.ss.p2 = -data.pp.ss.zeta*data.pp.ss.w_n + 1i * data.pp.ss.w_n*sqrt(1-data.pp.ss.zeta^2);
data.pp.ss.p3 = -data.pp.ss.zeta*data.pp.ss.w_n - 1i * data.pp.ss.w_n*sqrt(1-data.pp.ss.zeta^2);

% add 3th pole which is nondominant ==> so more left
data.pp.ss.p1 = real(data.pp.ss.p2) * 2;

data.pp.ss.pl = [data.pp.ss.p1;data.pp.ss.p2;data.pp.ss.p3]

% calculate new matrices: 
% no error according due to step input see script ex. 3.4

A_strich = [0,-C;
            0, A(1,1),A(1,2);
            0 ,A(2,1),A(2,2)];

B_strich = [0;B];

% poleplacement: 
data.pp.ss.K = place(A_strich,B_strich,data.pp.ss.pl)

data.pp.ss.Ki = data.pp.ss.K(1)-1;
data.pp.ss.Kp = data.pp.ss.K(2:end);

%% Pole placement for obeserver gain
data.pp.ss.os = [-4; -6]; %
% poleplacement
data.pp.ss.L = place(A',C',data.pp.ss.os);
data.pp.ss.L = data.pp.ss.L';





















