#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "GeometricFigure.hpp"

class Rectangle : public GeometricFigure {
    private:
        int x, y, width, height;
        bool fillMode;
    
    public:
        /**
         * @brief Construtor default da classe
         * @param _x, Coordenada x do canto superior 
         * esquedo do retângulo
         * @param _y, Coordenada y do canto superior 
         * esquedo do retângulo
         * @param _width, Largura do retângulo
         * @param _height, Altura do retângulo
         * @param _fillMode, Modo de preenchimento: 
         * 0 não preenchido, 1 completamente preenchido
        **/
        Rectangle(int _x, int _y, int _width, int _height, bool _fillMode, char _brush);

        /**
         * @brief Desenha a figura na tela 
        **/
        void draw(Screen &t);

};

#endif // RECTANGLE_H