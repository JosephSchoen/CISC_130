% Joseph Schoen plotting Rabia Malik's work

data1 = csvread('data2.CSV');
data2 = csvread('data1 (1).CSV');

figure();
plot(data1, data2,'-b','LineWidth', 1)
xlabel('x');
ylabel('y');