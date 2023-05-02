x=zeros(100, 2);
y=-7:10
x=y.^3;
csvwrite('data1.CSV',x)

x=-7:10
y=zeros(100,2);
y=(x.^3)+(7.*x);
csvwrite('data2.CSV',y)
