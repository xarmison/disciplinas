clear
clc

// Resolução de sistemas lineares pelo metodo de Gauss-Seidel
function [x, i, eR] = gauss_seidel(A, b, x, p)
    [r c] = size(A);
    B = eye(A) - inv(A .* eye(A))*A;
    g = inv(A .* eye(A)) * b;

    i = 0;
    while(1)
        xOld = x;

        for (j = 1:r)
            x(j) = B(j, :)*x + g(j);
        end

        eR = max(abs(x-xOld))/max(abs(x));

        if(eR < 10^-p)
            break
        end

        i = i + 1;
    end
endfunction

A = [15 5 -5; 4 10 1; 2 -2 8];
b = [30; 23; -10];

[x, i, eR] = gauss_seidel(A, b, zeros(b), 6)