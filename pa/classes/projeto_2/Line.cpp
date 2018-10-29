#include "Line.hpp"

// Bob o construtor 
Line::Line(int _x0, int _y0, int _x1, int _y1, char _brush) {
    x0 = _x0; 
    y0 = _y0; 
    x1 = _x1; 
    y1 = _y1; 
    brush = _brush;
}

// Bresenham's line algorithm
void plotLineLow(Screen &t, int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int yi = 1;

    if(dy < 0) {
        yi = -1;
        dy = -dy;
    }

    int D = 2*dy - dx;
    int y = y0;

    for(int x = x0; x <= x1; x++) {
        t.setPixel(x, y);
        if(D > 0) {
            y = y + yi;
            D = D - 2*dx;
        }
        D = D + 2*dy;
    }
}

void plotLineHigh(Screen &t, int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int xi = 1;

    if(dx < 0) {
        xi = -1;
        dx = -dx;
    }

    int D = 2*dx - dy;
    int x = x0;

    for(int y = y0; y <= y1; y++) {
        t.setPixel(x, y);
        if(D > 0) {
            x = x + xi;
            D = D - 2*dy;
        }

        D = D + 2*dx;
    }
}

void Line::draw(Screen &t) {
    if(abs(y1 - y0) < abs(x1 - x0)) {
        if(x0 > x1) {
            t.setBrush(brush);
            plotLineLow(t, x1, y1, x0, y0);
        }
        else {
            t.setBrush(brush);
            plotLineLow(t, x0, y0, x1, y1);
        }
    }
    else {
        if(y0 > y1) {
            t.setBrush(brush);
            plotLineHigh(t, x1, y1, x0, y0);
        }
        else {
            t.setBrush(brush);
            plotLineHigh(t, x0, y0, x1, y1);
        }
    }
}