#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polygon.hpp"

class Rectangle : public Polygon {
    public:
        Rectangle(float x, float y, float width, float height);
};


#endif