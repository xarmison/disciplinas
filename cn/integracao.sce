// Integral pelo método do trapezio com n aplicações
function i = trapezioDescendente(a, b, n)
    h = (b-a)/n;
    y = f(a:h:b);
    k = length(y);
    
    i = h/2;
    soma = y(1)+y(k);
    for j = 2:k-1
        soma = soma + 2*y(j);
    end
    i = i * soma;
endfunction

// Integral pelo método de 1/3 de Simpson com n aplicações
function i = simpson13(a, b, n )
    h = (b-a)/(2*n);
    y = f(a:h:b);
    k = length(y);
    
    i = h/3;
    soma = y(1)+y(k);
    for j = 2:k-1
        if(modulo(j, 2) == 0)
            soma = soma + 4*y(j)
        else
            soma = soma + 2*y(j)
        end
    end
    i = i * soma
endfunction

// Integral pelo método de 3/8 de Simpson com n aplicações
function i = simpson38(a, b, n)
    h = (b-a)/(3*n);
    y = f(a:h:b);
    k = length(y);
    
    i = 3/8*h;
    soma = 0;
    for j = 1:n
        soma = soma + y(3*j -2) + 3*y(3*j - 1) + 3*y(3*j) + y(3*j + 1)
    end
    i = i * soma
endfunction
