#ifndef LINE_H
#define LINE_H

#include "GeometricFigure.hpp"

class Line : public GeometricFigure {
    private:
        int x0, y0, x1, y1;

    public:
        /**
         * @brief Construtor default da classe
        **/
        Line(int _x0, int _y0, int _x1, int _y1, char _brush);
        
        /**
         * @brief Desenha a figura na tela 
        **/
        void draw(Screen &t);

};

#endif // LINE_H