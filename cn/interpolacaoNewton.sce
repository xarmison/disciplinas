clear
clc
function c = coeficientesNewton(x, y)
    n = length(x);
    T = zeros(n, n);
    T(:, 1) = y;
    for j = 2:n
        for i = 1:(n-j+1)
            T(i, j) = (T(i+1, j-1)-T(i, j-1))/(x(j+i-1)-x(i));
        end
    end
    c = T(1, :);
endfunction

function y = interpolacao(a, x, c)
    y = c(1);
    for i = 2:length(c)
        produto = c(i);
        for j = 1:(i-1)
           produto = produto*(a - x(j));
        end
        y = y + produto;
    end
endfunction

x = [-2; 1; 2];
y = [11; 2; 3];

c = coeficientesNewton(x, y)
p = interpolacao(1.5, x, c)
