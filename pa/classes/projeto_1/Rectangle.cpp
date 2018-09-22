#include "Rectangle.hpp"

Rectangle::Rectangle(float x, float y, float width, float height) {
    Polygon::addVertex(Point(x, y));
    Polygon::addVertex(Point(x + width, y));
    Polygon::addVertex(Point(x + width, y + height));
    Polygon::addVertex(Point(x, y + height));
}