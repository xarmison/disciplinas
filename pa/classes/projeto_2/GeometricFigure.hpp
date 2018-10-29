#ifndef GEOMETRICFIGURE_H
#define GEOMETRICFIGURE_H

#include "Screen.hpp"

class GeometricFigure {
    protected:
        char brush;
    public:
        GeometricFigure(){}
        /**
         * @brief Método draw(Screen &t)=0
         * @details Função virtual a ser implementada nas classes derivadas
         *  com isso, ao chamar o método, o programa identificará de qual figura
         *  geometrica se trata para desenhá-la de acordo com sua especificidade.
         */
        virtual void draw(Screen &t)=0;
};

#endif // GEOMETRICFIGURE_H