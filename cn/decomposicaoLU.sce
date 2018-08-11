// Decomposição LU
// Entradas: matriz A do sistema linear e matriz b de termos independentes
// Saida: x tal que A*x = b

// Decomposição LU pela eliminação gaussiana
function [L, U] = decomposicaoLU(A)
    [r, c] = size(A);
    L = eye(r, c);
    for j = 1:(r-1)
        pivo = A(j, j);
        for i = (j+1):r
            fator = A(i, j)/pivo
            A(i, :) = A(i, :) - (fator * A(j, :));
            L(i, j) = fator;
        end
    end
    U = A;
endfunction

// Fazendo A = LU tem-se L*U*x = b

// Solução para o passo intermediario L*y = b, onde y = U*x
function y = Ly(L, b)
    [r, c] = size(L);
    y = zeros(b);
    
    for i = 1:r
        soma = 0;
        for j = 1:c
            soma = soma + (L(i, j) * y(j))
        end
        y(i) = b(i) - soma
    end
endfunction

// Solução para o passo U*x = y
function x = Ux(U, y)
    [r, c] = size(U);
    x = zeros(b);
    D = diag(U);
    
    for i = r:-1:1
        soma = 0;
        for j = c:-1:1
            soma = soma + (U(i, j) * x(j))
        end
        x(i) = (y(i) - soma) * 1/D(i);
    end
endfunction

// Função para lidar com a entrada e saida de dados
function x = solveSystem(A, b)
    [L, U] = decomposicaoLU(A);
    y = Ly(L, b);
    x = Ux(U, y);
endfunction

clc

// Exemplo
A = [2 2 1 4 5 5; -4 1 0 -3 -9 -9; 4 24 15 29 19 17; 1 16 -8.5 18 -4.5 -2.5; -4 -9 -24 -9 -18 -17; -4 -9 -4 3 12 -1];

b = [13; -24; 26; 37.5; 11; -15];

x = solveSystem(A, b)

// Validação do resultado
// x encontrado precisa satisfazer A*x = b para ser solução
A*x
b
