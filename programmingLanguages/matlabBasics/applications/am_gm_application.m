% Arithmetic mean and geometric mean inequality
%   (x + y)/2 >= sqrt(xy)
%
% This property can be used to solve 16.^(x^2+y)+16.^(x+y^2)=1
% The code below solves the equation to check the solution

fxy = @ (x,y) 16.^(x^2+y)+16.^(x+y^2)-1;
[x,y] = solve(fxy);
x_calc = double(x)
y_calc = double(y)