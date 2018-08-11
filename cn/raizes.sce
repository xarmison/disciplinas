clear
clc
// Função para se calcular a raiz
function y = f(x)
    y = log(x) - 1;
endfunction

// Derivada da função - necessaria para metodo de newton
function y = f1(x)
    y = 1/x;
endfunction

function y = bissecao(a, b, p) 
    i = 0;
    while 1 then
        // Aproximação da raiz
        x = (a+b)/2;
        // Erro relativoS
        eR = abs((x - a)/x);

        if( f(a)*f(x) < 0 ) then
            b = x;
        else 
            a = x;
        end

       if eR < 10^-p then
            break
       end

       i = i+1;
    end

    disp('[raiz, erro_relativo, iterações]')
    y = [x, eR, i];
endfunction

function y = falsa_posicao(a, b, p)    
    i = 0;
    while 1 then
        // Aproximação da raiz
        x = a - ((f(a)*(b-a))/(f(b)-f(a)));
        // Erro relativo
        eR = abs((x - a)/x);

        if( f(a)*f(x) < 0 ) then
            b = x;
        else 
            a = x;
        end

       if eR < 10^-p then
            break
       end

       i = i+1;
    end

    disp('[raiz, erro_relativo, iterações]')
    y = [x, eR, i];
endfunction

function y = newton(x, p)
    i = 0;
    while 1 then
        xOld = x;
        // Aproximação da raiz
        x = xOld - (f(xOld)/f1(xOld));
        // Erro relativo
        eR = abs((x - xOld)/x);

        if eR < 10^-p then
            break;
        end
        
        i = i + 1;
    end

    disp('[raiz, erro_relativo, iterações]')
    y = [x, eR, i];
endfunction

function y = secante(x, xOld, p)
    i = 0;
    while 1 then
        xTemp = xOld;
        xOld = x;
        // Aproximação da raiz
        x = xOld - ((f(xOld)*(xTemp - xOld))/(f(xTemp) - f(xOld)));
        // Erro relativo
        eR = abs((x - xOld)/x);

        if eR < 10^-p then
            break;
        end
        
        i = i + 1;
    end

    disp('[raiz, erro_relativo, iterações]')
    y = [x, eR, i];
endfunction

bissecao(2, 3, 5)
falsa_posicao(2, 3, 5)
newton(2, 5)
secante(2, 3, 5)