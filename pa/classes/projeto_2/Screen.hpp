#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <fstream>

using namespace std;

class Screen {
    private:
        // Armazenam o tamanho da tela de desenho no de linhas e de colunas
        int rows, cols;

        // Guarda o caractere usado para desenhar
        char brush;

        // Armazena a matriz da tela
        vector< vector<char> > mat;
        
    public:
        /**
         * @brief Construtor default da classe
        **/
        Screen(int _rows, int _cols);

        /**
         * @brief Desenha um pixel da matriz usando o caratere
         * guardado em 'brush'
        **/
        void setPixel(int x, int y);

        /**
         * @brief Limpa a tela 
        **/
        void clear();

        /**
         * @brief Muda o caractere de desenho
        **/
        void setBrush(char _brush);

        /**
         * @brief Envia a tela para um stream de saida
        **/
        friend ostream& operator << (ostream &os, Screen &t);
};

#endif // SCREEN_H