#ifndef CIRCLE_H
#define CIRCLE_H

#include "GeometricFigure.hpp"

class Circle : public GeometricFigure {
    private:
        int xc, yc, radius;
        bool fillMode;

    public:    
        /**
         * @brief Construtor default da classe
        **/
        Circle(int _x, int _y, int _r, bool _fillMode, char _brush);

        /**
         * @brief Desenha a figura na tela 
        **/
        void draw(Screen &t);
};

#endif // CIRCLE_H