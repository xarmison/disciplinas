#include "Rectangle.hpp"
#include "Line.hpp"

// Bob o construtor 
Rectangle::Rectangle(int _x, int _y, int _width, int _height, bool _fillMode, char _brush) {
    x      = _x;
    y      = _y;     
    width  = _width; 
    height = _height;
    fillMode = _fillMode;
    brush = _brush;
}

void setPixels(Screen &t, int &x, int &y, int &width, int &height, char &brush) {
    Line l (x, y, x, y + width, brush), 
    l2(x, y + width, x + height, y + width, brush),
    l3(x + height, y + width, x + height, y, brush),
    l4(x + height, y, x, y, brush);

    l.draw(t);
    l2.draw(t);
    l3.draw(t);
    l4.draw(t);
}

void Rectangle::draw(Screen &t) {
    if(fillMode) {
        while(width > 0 && height > 0) {
            setPixels(t, x, y, width, height, brush);

            x++;
            y++;
            width--;
            height--;
        }

    } else {
        setPixels(t, x, y, width, height, brush);
    }

}