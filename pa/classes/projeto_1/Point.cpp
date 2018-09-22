#include <iostream>
#include <cmath>
#include "Point.hpp"

// Bob o Construtor
Point::Point() {
    x = 0;
    y = 0;
}

// Contrutor com os mesmos valores para as coordenadas
Point::Point(float _xy) {
    x = y = _xy;
}

// Contrutor com um valor para cada coordenada
Point::Point(float _x, float _y) {
    x = _x;
    y = _y;
}

// Contrutor de cópia 
Point::Point(const Point &p) {
    x = p.x;
    y = p.y;
}

// Define o valor da coordenada x
void Point::setX(float _x) {
    x = _x;
}

// Define o valor da coordenada y
void Point::setY(float _y) {
    y = _y;
}

// Define os valores das coordenadas x e y
void Point::setXY(float _x, float _y) {
    x = _x;
    y = _y;
}

// Recupera o valor da coordenada x
float Point::getX(void) {
    return x;
}

// Recupera o valor da coordenada y
float Point::getY(void) {
    return y;
}

// Adiciona as coordenadas (x,y) do ponto com as coordenadas de um ponto P1(x1,y1) fornecido
Point Point::add(Point p) {
    return Point(x + p.x, y + p.y);
}

// Subtrai as coordenadas (x,y) do ponto com as coordenadas de um ponto P1(x1,y1) fornecido
Point Point::sub(Point p) {
    return Point(x - p.x, y - p.y);
}

// Calcula a distância do ponto para a origem do sistema de coordenadas
float Point::norma(void) {
    return sqrt(x*x + y*y);
}

// Translada o ponto
void Point::traslada(float a, float b) {
    x += a;
    y += b;
}

// Imprime o ponto
void Point::imprime() {
    std::cout << "(" << x << ", " << y << ")";
}


