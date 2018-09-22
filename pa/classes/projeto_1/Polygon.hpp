#ifndef POLYGON_H
#define POLYGON_H

#include "Point.hpp"
#include <vector>

class Polygon : public Point {
    private:
        std::vector<Point> vertices;
    
    public:
        void addVertex(Point);
        
        int getNumVertices();
        double area();

        void translatePolygon(float, float);
        void rotate(Point, float);
        void print();
};


#endif // POLYGON_H