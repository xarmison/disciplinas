// Sistema de EDOs
function w = gy(x, y, z)
    //w = -0.4427 * sqrt(y) + 0.23 * (4 + 4 * sin(x));
    w = -0.217730593 * sqrt(y) + 0.221793635 * (8 + 6 * sin(x))
endfunction

function w = gz(x, y, z)
    //w = -0.4427 * sqrt(z) + 0.4427 * sqrt(y);
    w = -0.305476022 * sqrt(z) + 0.217730593 * sqrt(y)
endfunction

function [x, y, z] = eulerSisSolver(a, b, h, y0, z0)
    x = [a:h:b]';
    n = length(x);
    y(1) = y0;
    z(1) = z0;
    
    for i = 1:n-1
        ky = gy(x(i), y(i), z(i));
        kz = gz(x(i), y(i), z(i));
        
        y(i+1) = y(i) + ky * h;
        z(i+1) = z(i) + kz * h;
    end
endfunction

function [x, y, z] = rk4SisSolver(a, b, h, y0, z0)
    x = [a:h:b]';
    n = length(x);
    y(1) = y0;
    z(1) = z0;
    
    for i = 1:n-1
        ky1 = gy(x(i), y(i), z(i));
        kz1 = gz(x(i), y(i), z(i));
        
        ky2 = gy(x(i) + h/2, y(i) + ky1 * h/2, z(i)+ kz1 * h/2)
        kz2 = gz(x(i) + h/2, y(i) + ky1 * h/2, z(i)+ kz1 * h/2)
        
        ky3 = gy(x(i) + h/2, y(i) + ky2 * h/2, z(i)+ kz2 * h/2)
        kz3 = gz(x(i) + h/2, y(i) + ky2 * h/2, z(i)+ kz2 * h/2)
        
        ky4 = gy(x(i) + h, y(i) + ky3 * h, z(i) + kz3 * h);
        kz4 = gz(x(i) + h, y(i) + ky3 * h, z(i) + kz3 * h);
        
        ky = (ky1 + 2*ky2 + 2*ky3 + ky4)/6
        kz = (kz1 + 2*kz2 + 2*kz3 + kz4)/6
        
        y(i+1) = y(i) + ky * h;
        z(i+1) = z(i) + kz * h;
    end
endfunction

//[x, ye, ze] = eulerSisSolver(0, 30, 1, 0, 0);
//plot(x, ye, 'ro')
//plot(x, ze, 'b+')

[x, yrk4, zrk4] = rk4SisSolver(0, 30, 1, 0, 0)
plot(x, yrk4, 'ro')
plot(x, zrk4, 'b+')
