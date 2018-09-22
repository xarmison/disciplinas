#include <iostream>
#include "Point.hpp"
#include "Polygon.hpp"
#include "Rectangle.hpp"

using namespace std;

void testPoint() {
    Point a(666), b(1, 2), c;
    cout << "Point A: ";
    a.imprime();
    cout << endl;

    cout << "Point B: ";
    b.imprime();
    cout << endl;

    cout << "Point C: ";
    c.imprime();
    cout << endl;

    cout << "Copia A -> C: ";
    c = a;
    c.imprime();
    cout << endl;

    cout << "D = A+B: ";
    Point d = a.add(b);
    d.imprime();
    cout << endl;

    cout << "E = C-B: ";
    Point e = c.sub(b);
    e.imprime();
    cout << endl;

    float norma_e = e.norma();
    cout << "Norma de E: " << norma_e << endl;
    
    cout << "Translada E de (10, 10): ";
    e.traslada(10, 10);
    e.imprime();
    cout << endl;
}

void testPolygon() {
    Polygon triangle;

    triangle.addVertex(Point(1, 1));
    triangle.addVertex(Point(2, 3));
    triangle.addVertex(Point(3, 1));

    cout << "Numero de vertices: " << triangle.getNumVertices() << endl;
    triangle.print();
    cout << "Area: " << triangle.area() << endl;

    cout << "\nRotacionar o poligono 180 graus em torno de (1, 1) \n";
    triangle.rotate(Point(1, 1), 180);
    triangle.print();

    cout << "\nTransladar o poligono (10, 10)\n";
    triangle.translatePolygon(10, 10);
    triangle.print();
}

void testRectangle() {
    Rectangle rect(0, 0, 4, 3);
    cout << "Retangulo: \n";
    rect.print();
    cout << "Area do retangulo: " << rect.area() << endl;

    cout << "\nTransladar o poligono (-3, 4)\n";
    rect.translatePolygon(-3, 4);
    rect.print();
    cout << "Area do retangulo: " << rect.area() << endl;

    cout << "\nRotacionar o poligono 180 graus em torno de (-1, 5.5) \n";
    rect.rotate(Point(-1, 5.5), 30);
    rect.print();
    cout << "Area do retangulo: " << rect.area() << endl;

}

int main(){
    
    testRectangle();

    return 0;
}