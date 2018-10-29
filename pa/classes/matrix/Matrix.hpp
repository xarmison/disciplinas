#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
    private:
        int rows, cols;

    public:
        float **x;

        /**
         * @brief Matrix é o construtor da classe
         * @param _rows é a quantiadade de linhas
         * @param _cols é a quantiadade de colunas
        **/
        Matrix(int _rows=0, int _cols=0);

        /**
         * @brief Construtor de cópia da classe
        **/
        Matrix(const Matrix& matrix);

        /**
         * @brief Destrutor da classe
        **/
        ~Matrix();

        /**
         * @brief Função para mostrar a matriz
        **/
        void print();

        /**
         * @brief Função para preencher a matriz 
         * com números aleatórios
        **/
        void randomize();

        /**
         * @brief Função para preencher a matriz 
         * com uns
        **/
        void ones();

        /**
         * @brief Função para preencher a matriz 
         * com zeros
        **/
        void zeros();

        /** 
         * @brief Sobrecarga do operador () para 
         * alterações pontuaisna matriz
         * @param i é a linha a ser alterada
         * @param j é a coluna a ser alterada
        **/
        float &operator()(int i, int j);

        void operator=(Matrix &matrix);

        /**
         * @brief Sobrecarga do operador * para 
         * multiplicar a matriz por um escalar
        **/
        Matrix operator*(float scalar);


};

#endif // MATRIX_H