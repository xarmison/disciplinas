#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polygon.hpp"

class Rectangle : public Polygon {
    public:
        /**
         * @brief Construtor da classe retângulo
         * 
         * @param x é a coordena x do ponto superior esquerdo
         * @param y é a coordena y do ponto superior esquerdo
         * @param width é a largura 
         * @param height é a altura
         */
        Rectangle(float x, float y, float width, float height);
};


#endif