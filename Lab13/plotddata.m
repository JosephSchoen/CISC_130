plotdata = csvread('create_data_1.CSV');
figure();
plot(plotdata);
xlabel('x');
ylabel('y');
ylim([-50 50]);

plotdata2 = csvread('create_data_2.CSV');
figure(2);
plot(plotdata2);
xlabel('x');
ylabel('y');
