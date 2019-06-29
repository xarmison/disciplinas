#ifndef GraphMatrix_H
#define GraphMatrix_H

// Implementação de grafos utilizando matriz de adjacência 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream> 
#include <string>
using namespace std;

class GraphMatrix {
    private:
        // Arquivo que armazena o grafo
        ifstream file;
        // Quantidade de vértices
        int vertex;
        // Matrix de adjacência do grafo
        int **matrix;    
    public:
        GraphMatrix(string filePath);
        ~GraphMatrix();

        friend ostream& operator << (ostream &os, GraphMatrix &graph);  
};

#endif // GraphMatrix_H