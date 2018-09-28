#ifndef POINT_H
#define POINT_H

class Point {
    private:
        float x, y;

    public:
        /**
         * @brief Matrix é o construtor default da classe
        **/
        Point();

        /**
         * @brief Matrix é o construtor que recebe a mesma 
         * inicialização para amba as cordenadas
         * @param _rows é a quantiadade de linhas
         * @param _cols é a quantiadade de colunas
        **/
        Point(float);

        /**
         * @brief Point é o construtor que recebe a 
         * inicialização das coordenadas
         * @param _x é a coordenada x 
         * @param _y é a coordenada y
        **/
        Point(float, float);

        /**
         * @brief Matrix é o construtor de cópia da classe
         * @param p é o ponto a ser copiado 
        **/
        Point(const Point &p);
        
        /**
         * @brief setX define o valor da coordenada x
         * @param _x é o valor da coordenada x  
        **/
        void setX(float _x);

        /**
         * @brief setY define o valor da coordenada y
         * @param _y é o valor da coordenada y  
        **/
        void setY(float _y);

        /**
         * @brief setXY define o valor das duas coordenadas
         * @param _x é o valor da coordenada x  
         * @param _y é o valor da coordenada y  
        **/
        void setXY(float _x, float _y);

        /**
         * @brief getX recupera o valor da coordenada x
        **/
        float getX();

        /**
         * @brief getY recupera o valor da coordenada y
        **/
        float getY();

        /**
         * @brief add Adiciona as coordenadas (x,y) do
         * ponto com as coordenadas de um ponto P1(x1,y1)
         * fornecido
         * @param p é o ponto cuja as coordenadas serão 
         * adicionadas 
        **/
        Point add(Point p);
        
        /**
         * @brief sub Subtrai as coordenadas (x,y) do
         * ponto com as coordenadas de um ponto P1(x1,y1)
         * fornecido
         * @param p é o ponto cuja as coordenadas serão 
         * adicionadas 
        **/
        Point sub(Point p);
        
        /**
         * @brief norma Calcula a distância do ponto para 
         * a origem do sistema de coordenadas
        **/
        float norma();

        /**
         * @brief traslada Adicona as coordenadas fornecidas 
         * ao ponto
         * @param a é o incremento a coordenada x
         * @param b é o incremento a coordenada y
        **/
        void traslada(float a, float b);

        /**
         * @brief imprime mostra as coordenadas do ponto 
        **/
        void imprime();

};

#endif //POINT_H

