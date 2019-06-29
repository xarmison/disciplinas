#include "GraphMatrix.hpp"

// Extrai inteiros de uma string
void extractIntegers(string str, int *arr) { 
    stringstream ss;     
  
    ss << str; 
  
    string temp; 
    int found; 
    int i = 0;
    while (!ss.eof()) { 
  
        ss >> temp; 
  
        if (stringstream(temp) >> found) {
            arr[i] = found;
            i++;
        }

        temp = ""; 
    } 
} 

// Class Constructor
GraphMatrix::GraphMatrix(string filePath) {
    file.open(filePath);

    string line;

    if (file.is_open()) {
        
        // Lê a quantidade de vértices
        getline(file, line);
        vertex = stoi(line);

        // Aloca espaço para a matriz
        matrix = new int*[vertex];

        if(matrix == NULL) {
            delete[] matrix;
            cout << "Erro ao alocar a matriz!\n";
            exit(0);
        }

        matrix[0] = new int[vertex * vertex];

        for(int i = 1; i < vertex; i++) {
            matrix[i] = matrix[i-1] + vertex;
        }

        // Inicia o grafo sem conexões
        for(int i = 0; i < vertex; i++) {
            for(int j = 0; j < vertex; j++) {
                matrix[i][j] = -1;
            }
        }

        while (getline(file, line)) {
            // Armazena os valores dos vertices e aresta
            int values[3];
            extractIntegers(line, values);

            //cout << values[0] - 1 << " -> " << values[1] - 1 << ": " << values[2] << endl;
            
            // Seta os valores lidos do arquivo 
            matrix[values[0] - 1][values[1] - 1] = values[2];
        }

        file.close();
 
    } else 
        cout << "Erro ao abrir o arquivo.\n"; 
    
}

// Class Destructor
GraphMatrix::~GraphMatrix() {
    if(vertex > 0) {
        delete[] matrix[0];
        delete[] matrix;
    }
}

ostream& operator << (ostream &os, GraphMatrix &graph) {
    for(int i = 0; i < graph.vertex; i++) {
        for(int j = 0; j < graph.vertex; j++) {
            cout << setw(3) << graph.matrix[i][j] << " ";
        }
        cout << endl;
    }

    return os;
}