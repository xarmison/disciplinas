#ifndef POLYGON_H
#define POLYGON_H

#include "Point.hpp"
#include <vector>

class Polygon {
    private:
        std::vector<Point> vertices;
    
    public:
        /**
         * @brief addVertex adiciona mais um vértice ao 
         * polígono
         * @param p ponto a ser adicionado
        **/
        void addVertex(Point p);
        
        /**
         * @brief getNumVertices retorna a quantidade de 
         * vértices presentes no polígono 
        **/
        int getNumVertices();

        /**
         * @brief area utiliza o algoritmo Shoelace para 
         * calcular a área do polígono
        **/
        double area();

        /**
         * @brief translatePolygon percorre todos os pontos
         * do polígono e os translada
         *  
         * @param a é o incremento em x  
         * @param b é o incremento em y
        **/
        void translatePolygon(float a, float b);

        /**
         * @brief rotate iplementa as tranformações 2D necessarias 
         * para deslocar a origem do sistema de coordenadas para o
         * ponto fornecido e rotacionar os outros pontos torno da 
         * nova origem
         * 
         * [x', y']' = R[[x - o.x], [y - o.y]] + [o.x, 0.y]
         * 
         * p.x = o.x + (p.x - o.x)*cos(angle) + (p.y - o.y)*sin(angle)
         * 
         * p.y = o.y + (p.y - o.y)*cos(angle) - (p.x - o.x)*sin(angle))
         * 
         * @param o ponto em torno do qual o polígono será rotacionado
         * @param angle é o angle que o polígono deve ser rotacionado
         */
        void rotate(Point o, float angle);

        /**
         * @brief Imprime as ligações entre os vértices do polígono 
         */
        void print();
};

#endif // POLYGON_H