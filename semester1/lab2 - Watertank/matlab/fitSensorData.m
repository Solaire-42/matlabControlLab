%% Fit Sensor data
data.Sensor.FitPara = polyfit(data.Sensor.v, data.Sensor.h, 1);

figure('Name', 'Waterlevel Sensor', 'NumberTitle', 'off');
% raw data
plot(data.Sensor.v, data.Sensor.h, 'r')
grid on
hold on
% Data fitted
plot(data.Sensor.v, data.Sensor.FitPara(1)*data.Sensor.v + data.Sensor.FitPara(2), 'b')
hold on
h_xlabel = xlabel({'$U$\,/\,V'});
set(h_xlabel,'Interpreter','latex')
h_ylabel = ylabel({'$h$\,/\,mm'});
set(h_ylabel,'Interpreter','latex')
legend({'Raw Data','Data fitted'},'Location','southeast')