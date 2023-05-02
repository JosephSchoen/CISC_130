% Joseph Schoen and Rabia Malik

data1 = csvread('log1.csv', 1, 0);
data2 = csvread('log2.csv', 1, 0);
data3 = csvread('log3.csv', 1, 0);

all_data = [data1; data2; data3];

tstart = datenum(all_data(1, 1));
tend = datenum(all_data(end, 1));

figure();
plot(all_data(:, 1), all_data(:, 2), '-b','LineWidth', 1);
datetick('x', 'mm.dd.yyyy');
xlim([tstart tend])
xlabel('Date');
ylabel('Water Level (cm)');
set(gca, 'FontSize', 20);

% Code provided on Matlab website to place more dates
newLim = get(gca,'XLim'); 
newx = linspace(newLim(1), newLim(2), 8); 
set(gca,'XTick', newx); 
datetick(gca,'x','mm.dd.yyyy','keepticks');

figure();
plot(all_data(:, 1), all_data(:, 3), '-m','LineWidth', 1);
datetick('x', 'mm.dd.yyyy');
xlim([tstart tend])
xlabel('Date');
ylabel('Water Temperature (C)');
set(gca, 'FontSize', 20);

% Code provided on Matlab website to place more dates
newLim = get(gca,'XLim'); 
newx = linspace(newLim(1), newLim(2), 8); 
set(gca,'XTick', newx); 
datetick(gca,'x','mm.dd.yyyy','keepticks');


figure();
plot(all_data(:, 1), all_data(:, 4), '-r','LineWidth', 1);
datetick('x', 'mm.dd.yyyy');
xlim([tstart tend])
xlabel('Date');
ylabel('Water Conductivity (\muS/cm)');
set(gca, 'FontSize', 20);

% Code provided on Matlab website to place more dates
newLim = get(gca,'XLim'); 
newx = linspace(newLim(1), newLim(2), 8); 
set(gca,'XTick', newx); 
datetick(gca,'x','mm.dd.yyyy','keepticks');

