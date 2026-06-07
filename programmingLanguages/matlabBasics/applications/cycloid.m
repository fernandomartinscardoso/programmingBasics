clear all
clc

t=linspace(0,2*pi,1000);
r=2;
x1=r.*(t-sin(t));
y1=r.*(1-cos(t));
x2=r.*cos(t);
y2=r.*sin(t)+r;
figure(1)
plot(x1,y1,'-b',x2,y2,'-k')
axis equal