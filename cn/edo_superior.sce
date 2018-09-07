// Exemplo de EDO
function w = gy(x, y, z)
    w = z
endfunction

function w = gz(x, y, z)
    w = -10
endfunction


function [x, y, z] = midPointSisSolver(a, b, h, y0, z0)
    x = [a:h:b]';
    n = length(x);
    y(1) = y0;
    z(1) = z0;
    
    for i = 1:n-1
        ky1 = gy(x(i), y(i), z(i));
        kz1 = gz(x(i), y(i), z(i));
        
        ky2 = gy(x(i) + h/2, y(i) + ky1 * h/2, z(i) + kz1 * h/2);
        kz2 = gz(x(i) + h/2, y(i) + ky1 * h/2, z(i) + kz1 * h/2);
        
        y(i+1) = y(i) + ky2 * h;
        z(i+1) = z(i) + kz2 * h;
    end
endfunction

[x, ymp, zmp] = midPointSisSolver(0, 2, 0.2, 1.8, 12)
plot(x, ymp, 'ro')
plot(x, zmp, 'b+')
