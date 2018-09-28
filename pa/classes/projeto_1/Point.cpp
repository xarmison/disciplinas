#include <iostream>
#include <cmath>
#include "Point.hpp"

// Bob o Construtor
Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(float _xy) {
    x = y = _xy;
}

Point::Point(float _x, float _y) {
    x = _x;
    y = _y;
}

Point::Point(const Point &p) {
    x = p.x;
    y = p.y;
}

void Point::setX(float _x) {
    x = _x;
}

void Point::setY(float _y) {
    y = _y;
}

void Point::setXY(float _x, float _y) {
    x = _x;
    y = _y;
}

float Point::getX(void) {
    return x;
}

float Point::getY(void) {
    return y;
}

Point Point::add(Point p) {
    return Point(x + p.x, y + p.y);
}

Point Point::sub(Point p) {
    return Point(x - p.x, y - p.y);
}

float Point::norma(void) {
    return sqrt(x*x + y*y);
}

void Point::traslada(float a, float b) {
    x += a;
    y += b;
}

void Point::imprime() {
    std::cout << "(" << x << ", " << y << ")";
}


