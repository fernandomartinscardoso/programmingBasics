clear all
clc

% Future Value of the investment, including all interest earned:
FV = input('Enter the future value:');

% Initial Principal (the starting lump sum amount):
P = input('Enter the initial principal');

% The amount of the Monthly Contribution (Payment):
PMT = input('Enter the amount of the monthly contribuiton');

% The Number of times interest is compounded per year and the Number of years the money is invested:
n = input('Enter the number of times interest is compounded per year:');
t = input('Enter the number of years the money is invested:');

fr = @ (r) FV-P*(1+r/n)^(n*t)-PMT*((1+r/n)^(n*t)-1)/(r/n);
[r] = solve(fr);
r_calc = double(r);

for m = 1:n
    sprintf('The Annual Interest Rate is: %.3f+%.3fi \n',real(r_calc(m)),imag(r_calc(m)))
end
