%% Quiz3 for Introduction of Mech
% Name: Horace
% Date: 25 March 2020
% Description: this script make a calculation for quiz3.

%% Code
%clear processor
clear all; clc;

%% Calculation
% Set konwn numbers
Co = 0.25; % wt% initial uniform carbon concentration.
Cs = 1.20; % wt% Concentration of carbon at the surface.
Cx = 0.80; % wt% Concentration of carbon at position 0.5 mm below surface.
x = 5*10^(-4); % m The lenghth below below surface.
dc = 1.6*10^(-6); % m2/s The diffusion coefficient for carbon in iron at this temperature.
% Calculate the time
erf=1-(Cx-Co)/(Cs-Co); % Calculate the erro of function.
z=(0.40-0.35)/(0.4284-0.3794)*(erf-0.3794)+0.35; % Calculate the value of z.
t = (x/(2*dc^(1/2))/z)^2; % Calculate the time.
fprintf('It will take %0.4f s to achieve a carbon content of 0.80 wt%% at position 0.5 mm below surface.',t);
