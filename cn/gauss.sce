clear 
clc
// Eliminação gaussiana

A = [4 3 8 1; 12 10 30 8; 24 25 93 49; 20 19 85 90]

function [A, b] = gauss(A, b)
    [nR, nC] = size(A);

    for i = 1:nR
        pivo = A(i,i);
        for j = i+1:nC
            fator = A(j, i)/pivo;
            A(j, :) = A(j, :) -(fator * A(i, :));
            b(j) = b(j) - fator * b(j)
        end 
    end
endfunction

