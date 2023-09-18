clear;close all;clc
k = 0:0.01:0.3;
NPV = -50 + 115./(1+k) + (-66)./(1+k).^2;
plot(k,NPV)
hold on
plot([0,0.3],[0,0])
xlabel('k')
ylabel('NPV')