// MMQ
clear
clc

// Solução por mmq de um sistema do tipo Xa = C
function [aHat, EQ] = mmq(X, C)
    aHat = inv(X'*X)*(X'*C)
    e = X*aHat - C
    EQ = e'*e
endfunction

//X = [1 2; 1 3.5; 1 6.5];
//C = [1.2; 3.7; 4.5];

//[aHat, EQ] = mmq(X, C)

x = [0.1:0.1:1]';
X = [ones(x), x, x.^2];

C = [0.62; 0.63; 0.64; 0.66; 0.68; 0.71; 0.76; 0.81; 0.89; 1];

[aHat, EQ] = mmq(X, C)

plot(x, C, 'x')
plot(x, X*aHat, 'r')

