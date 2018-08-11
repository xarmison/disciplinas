clear
clc
// Metodo iterativo de jacobi para resolução de sistemas lineares
function [x, i, eR] = jacobi(A, b, x, p)
    B = eye(A) - inv(A .* eye(A))*A;
    g = inv(A .* eye(A)) * b;

    i = 0
    while(1)
        xOld = x;

        x = B * xOld + g;

        eR = max(abs(x-xOld))/max(abs(x));

        if(eR < 10^-p)
            break
        end

        i = i + 1;
    end

endfunction

A = [15 5 -5; 4 10 1; 2 -2 8];
b = [30; 23; -10];

[x, i, eR] = jacobi(A, b, zeros(b), 2)
