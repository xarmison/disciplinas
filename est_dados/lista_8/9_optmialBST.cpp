#include <iostream>
#include <iomanip>
#define N 5
#define INT_MAX 2147483647
using namespace std;

int minimum(int i, int j, int &k, int cost[N][N]) {
    int min = INT_MAX;

    for(int l = i+1; l <= j ; l++) {
        if(cost[i][l-1] + cost[l][j] < min) {
            k = l;
            min = cost[i][l-1] + cost[l][j];
        }
    }

    return min;
}

void printMatrix(int matrix[N][N]) {    

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i > j) 
                cout << setw(2) << "-" << "  ";
            else
                cout << setw(2) << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "\n";
}

void printMatrixK(int matrix[N][N]) {    

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i > j || i == j) 
                cout << setw(2) << "-" << "  ";
            else
                cout << setw(2) << matrix[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "\n";
}

void printVector(int *arr) {
    cout << "[ ";
    for(int i = 0; i < N; i++) {
        cout << setw(2) << arr[i] << " ";
    }
    cout << "]\n";
}

int main(int argc, char **argv) {

    int keys[N] = { 20, 42, 13, 10, 19 };   
    int internalFreqs[N] = { -1, 10, 1, 3, 2 };
    int externalFreqs[N] = { 2, 1, 1, 1, 1 };
    
    int cost[N][N]; // Custo da arvore
    int prob[N][N]; // A soma das probabilidades relativas as chave
    int k[N][N];    // Matriz das posições k dos nós  

    for(int j = 0; j < N; j++) {
        k[j][j] = 0;
        cost[j][j] = 0;
        prob[j][j] = externalFreqs[j];
    }

    int j;
    for(int d = 1; d < N; d++) {
        for(int i = 0; i < N-d; i++) {
            j = i + d;
            prob[i][j] = prob[i][j-1] + internalFreqs[j] + externalFreqs[j];
            cost[i][j] = minimum(i, j, k[i][j], cost) + prob[i][j];
        }
    }

    cout << "\nArvore construidas com as chaves: ";
    printVector(keys);
    
    cout << "\nMatrix de probabilidades, P:\n";
    printMatrix(prob);

    cout << "\nMatrix de custo, C:\n";
    printMatrix(cost);

    cout << "\nMatriz de chaves, k:\n";
    printMatrixK(k);

    cout << "\nCusto da arvore otima: " << cost[0][N-1] << "\n\n";

    return 0;
}