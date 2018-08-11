// Defines the solution if there is one
function y = f(x)
    y = (70/9)*exp(-0.3*x) - (43/9)*exp(-1.2*x);
endfunction

// Defines the EDO
function z = g(x, y)
    z = -1.2*y + 7 * exp(-0.3 * x);
endfunction

// Euler's method
function [x, y] = eulerSolve(a, b, h, y0)
    x = [a:h:b]';
    n = length(x);
    y(1) = y0;
    
    for i = 1:n-1
        y(i+1) = y(i) + g(x(i), y(i)) * h;
    end
endfunction

// Calculates the new step for the adaptive Euler method
function h = getNewStep(x, y, h, p)
    y1 = y + g(x, y) * h;
    y21 = y + g(x + h/2, y) * h/2;
    y2 = y21 + g(x + h, y21) * h/2;
        
    err = abs(y2-y1)
    
    if err > 10^-p then
        alpha = 0.25
    else
        alpha = 0.2
    end
    
    h = h * abs(10^-p/err)^alpha
endfunction

// Adaptive step-size for Euler’s method
function [x, y] = adaptiveEulerSolver(a, b, h, y0, p)
    x(1) = a;
    n = length(x);
    y(1) = y0;
    
    i = 1;
    while %T
        h = getNewStep(x(i), y(i), h, 3);
        x(i+1) = x(i) + h;
        y(i+1) = y(i) + g(x(i), y(i)) * h;
        
        if(x(i+1) > b) then
            break
        end
        i = i + 1;
    end
endfunction

// Heun's method
function [x, y] = heunSolver(a, b, h, y0)
    x = [a:h:b]';
    n = length(x);
    y(1) = y0;
    
    for i = 1:n-1
        k1 = g(x(i), y(i));
        k2 = g(x(i) + h, y(i) + k1 * h);
        k = 0.5*(k1 + k2);
        
        y(i+1) = y(i) + k * h;
    end
endfunction

// Midpoint method
function [x, y] = midpointSolver(a, b, h, y0)
    x = [a:h:b]';
    n = length(x);
    y(1) = y0;
    
    for i = 1:n-1
        k1 = g(x(i), y(i));
        k = g(x(i) + h/2, y(i) + k1 * h/2)
        
        y(i+1) = y(i) + k * h;
    end
endfunction

// Fourth Order Runge-Kutta method
function [x, y] = rk4Solver(a, b, h, y0)
    x = [a:h:b]';
    n = length(x);
    y(1) = y0;
    
    for i = 1:n-1
        k1 = g(x(i), y(i));
        k2 = g(x(i) + h/2, y(i) + k1 * h/2);
        k3 = g(x(i) + h/2, y(i) + k2 * h/2);
        k4 = g(x(i) + h, y(i) + k3 * h);
        k = (1/6)*(k1 + 2*k2 + 2*k3 + k4);
        
        y(i+1) = y(i) + k * h;
    end
endfunction


[x, ye] = eulerSolve(0, 2.5, 0.5, 3);
[xae, yae] = adaptiveEulerSolver(0, 2.5, 0.5, 3);
[x, yh] = heunSolver(0, 2.5, 0.5, 3);
[x, ym] = midpointSolver(0, 2.5, 0.5, 3);
[x, yrk4] = rk4Solver(0, 2.5, 0.5, 3);

plot(x, ye, 'ro')
plot(xae, yae, 'y+')
plot(x, yh, 'g*')
plot(x, ym, 'mx')
plot(x, yrk4, 'kp')

a = [-0.5:0.01:3];
b = f(a);
plot(a, b, 'b--')
