#ifndef POINT_H
#define POINT_H

class Point {
    private:
        float x, y;

    public:
        Point();
        Point(float);
        Point(float, float);
        Point(const Point &p);
        
        void setX(float);
        void setY(float);
        void setXY(float, float);
        float getX();
        float getY();

        Point add(Point p);
        Point sub(Point p);
        
        float norma();
        void traslada(float, float);
        void imprime();

};

#endif //POINT_H

