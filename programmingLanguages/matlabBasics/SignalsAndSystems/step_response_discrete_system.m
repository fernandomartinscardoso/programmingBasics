% STEP RESPONSE ANALYSIS FOR DISCRETE SYSTEM
% Author: Fernando Martins Cardoso

clc
clear all
close all

% How to declare the transfer function:
% G(z) =             z + 1              --> numD = [1 1]
%        ----------------------------
%         (z^2 + 0.5)(z^2 - z + 0.5)    --> denD = conv([1 0.5],[1 -1 0.5])
% conv is the convolution and polynomial multiplication function

numD = [1 1];
denD = conv([1 0.5],[1 -1 0.5]);   

% The ts variable is the sampling time
ts = 1;
t = 0:ts:25*ts;

% dstep is the step response of discrete-time linear systems function
xstep = dstep(numD,denD,length(t));
ystep = linspace(1,1,length(t));     % step function for reference

figure
stairs(t,xstep,'b-')
hold
stairs(t,ystep,'k:')