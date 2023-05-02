% Joseph Schoen plot creating file

y = -100:100

x = ((y.^2)/4) + (3.*y);

csvwrite('create_data_1.CSV', x)

x = -100:100
y = (x+(4.*x))./x;

csvwrite('create_data_2.CSV', y)