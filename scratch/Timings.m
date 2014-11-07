clear all
clc


load('Timings.txt');

lenghts=Timings(:,1);

O3_0=Timings(:,2);
O3_1=Timings(:,3);
O3_2=Timings(:,4);
O4=Timings(:,5);
O5=Timings(:,6);

DO4=(-O4./O3_2+1)*100;
DO5=(-O5./O3_2+1)*100;


[f,gof]=fit(lenghts,O5,'poly2');

nlf=NonLinearModel.fit(lenghts, O5,@(b,x) b(1)+b(2)*x.^2, [0,1])

q=@(b,x) b(1)+b(2)*x.^2;

A=nlinfit(lenghts, O5,q, [0,1])
xfit=linspace(0,2000,1000);
yfit=q(A,xfit);

figure(1)
xlabel('Grid size')
ylabel('time [s]')
plot(lenghts, O3_0,'+-', lenghts, O3_1,'x-',lenghts, O3_2,'o-' )


figure(2)
xlabel('Grid size')
ylabel('time [s]')
plot(lenghts, O3_2,'+-', lenghts, O4,'x-',lenghts, O5,'o-')

figure(3)
bar(lenghts,[DO4,DO5])

figure(4)
plot(lenghts, O5,'r x',xfit,yfit)

