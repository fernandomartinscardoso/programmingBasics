## [step_response_discrete_system.m](https://github.com/fernandomartinscardoso/matlabBasics/blob/main/SignalsAndSystems/step_response_discrete_system.m)

This MATLAB script computes and plots the time-domain step response of a discrete-time linear time-invariant (LTI) system. It visualizes the system's output against a unit step reference input using a staircase plot layout to accurately represent the discrete-time behavior.

### ⚙️ Mathematical Model

The script analyzes a discrete-time transfer function $G(z)$ defined as:

$$ G(z)=\frac{z+1}{(z^{2}+0.5)(z^{2}-z+0.5)} $$

#### Polynomial Expansion

The denominator is calculated using polynomial multiplication (convolution), expanding as follows:

$$ \text{denD}=(z^{2}+0.5)\cdot (z^{2}-z+0.5)=z^{4}-z^{3}+z^{2}-0.5z+0.25 $$

In the future, the code will be modified to request the coefficients from the user via prompt.

---
