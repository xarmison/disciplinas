#include "Polygon.hpp"
#include <iostream>
#include <cmath>

#define PI 3.14159265

void Polygon::addVertex(Point p) {
    vertices.push_back(p);
}

int Polygon::getNumVertices() {
    return vertices.size();
}

double Polygon::area() {
    // Shoelace algorithm
    double area = 0.0;

    int n = vertices.size();

    // O vertice anterior ao primeiro é o ultimo
    int j = n - 1;
    for(int i = 0; i < n; i++) {
        area += (vertices[j].getX() + vertices[i].getX()) * (vertices[j].getY() - vertices[i].getY());
        j = i;  // j é anterior ao vertice i
    }

    // Retorna o valor absoluto da area 
    return abs(area / 2.0);
}

void Polygon::translatePolygon(float a, float b) {
    for(Point &p : vertices) {
        p.traslada(a, b);
    }
}

void Polygon::rotate(Point o, float angle) {
    /*
        Iplementa as tranformações 2D necessarias para deslocar
        a origem do sistema de coordenadas para o ponto fornecido
        e rotacionar os outros pontos torno da nova origem

        [x', y']' = R[[x - o.x], [y - o.y]] + [o.x, 0.y]

        p.x = o.x + (p.x - o.x)*cos(angle) + (p.y - o.y)*sin(angle)
        p.y = o.y + (p.y - o.y)*cos(angle) - (p.x - o.x)*sin(angle))
    */

    for(Point &p : vertices) {
        p.setX(o.getX() + (p.getX() - o.getX())*cos(-angle * (PI/180.0)) + (p.getY() - o.getY())*sin(-angle * (PI/180.0)));
        p.setY(o.getY() + (p.getY() - o.getY())*cos(-angle * (PI/180.0)) - (p.getX() - o.getX())*sin(-angle * (PI/180.0)));
    }

}

void Polygon::print() {
    for(Point p : vertices) {
        p.imprime();
        std::cout << " -> ";
    }
    vertices[0].imprime();
    std::cout << std::endl;
}