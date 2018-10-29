#include "Circle.hpp"

// Bob o construror
Circle::Circle(int _xc, int _yc, int _radius, bool _fillMode, char _brush) {
    xc = _xc; 
    yc = _yc;
    radius = _radius;
    fillMode = _fillMode;
    brush = _brush;
}

// Bresenham's circle algorithm
void drawPixels(Screen &t, int &x, int &y, int &xc, int &yc) {
    t.setPixel( x + xc,  y + yc);
	t.setPixel(-x + xc,  y + yc);
	t.setPixel( x + xc, -y + yc);
	t.setPixel(-x + xc, -y + yc);
	t.setPixel( y + xc,  x + yc);
	t.setPixel( y + xc, -x + yc);
	t.setPixel(-y + xc,  x + yc);
	t.setPixel(-y + xc, -x + yc);
}

void drawCircle(Screen &t, int pk, int x, int y, int xc, int yc) {
    drawPixels(t, x, y, xc, yc);
    
    while(x < y) {
		if(pk <= 0) {
			pk = pk + (4*x) + 6;
			drawPixels(t, ++x, y, xc, yc);
		}
		else {
			pk = pk + (4*(x-y)) + 10;
			drawPixels(t, ++x, --y, xc, yc);
		}
	}
}

void Circle::draw(Screen &t) {
    int pk  = 3 - 2*radius;
	int x   = 0; 
    int y   = radius;
	
    if(fillMode) {
        while(radius > 0) {
            t.setBrush(brush);
            drawCircle(t, pk, x, y, xc, yc); 

            radius--;
            pk  = 3 - 2*radius;
            x   = 0; 
            y   = radius;
        } 
    } else {
        t.setBrush(brush);
        drawCircle(t, pk, x, y, xc, yc); 
    }
}