clear
clc

function l = lagrange(a, x, y, n)
    soma = 0;
    
    for i = 1:n
        pr = y(i);
        
        for j = 1:n
            if(i <> j)
                pr = pr * ((a-x(j))/(x(i) - x(j)));
            end
        end
        soma = soma + pr;
    end
    l = soma;
endfunction

x = [-2; 1; 2];
y = [11; 2; 3];

a = lagrange(1.5, x, y, length(x))
