#include "Matrix.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>  

using namespace std;

Matrix::Matrix(int _rows, int _cols): rows(_rows), cols(_cols) {
    if(rows > 0 && cols > 0) {
        x = new float*[rows]; 
        
        if(x == NULL) {
            delete[] x;
            cout << "Error allocating the matrix!\n";
            exit(0);
        }
        
        x[0] = new float[rows*cols];

        for(int i = 1; i < rows; i++) {
            x[i] = x[i-1] + cols;
        }
    }
}

Matrix::Matrix(const Matrix& matrix) {
    memcpy(x, matrix.x, rows * sizeof(float));
    memcpy(x[0], matrix.x[0], rows * cols * sizeof(float));
}

Matrix::~Matrix() {
    if(rows > 0 && cols > 0) {
        delete[] x[0];
        delete[] x;
    }
}

void Matrix::print() {
    if(!(rows > 0 && cols > 0)) {
        cout << "[[]]\n";
        return;
    }

    cout << "[\n";
    for(int i = 0; i < rows; i++) {
        cout << "  [";
        for(int j = 0; j < cols; j++) {
            cout << setprecision(2) << setw(4) << x[i][j] << " ";
        }
        cout << " ]\n";
    }
    cout << "]\n";
    
}

void Matrix::randomize() {
    if(!(rows > 0 && cols > 0)) {
        return;
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            x[i][j] = rand() % 20;
        }
    }
}

void Matrix::ones() {
    if(!(rows > 0 && cols > 0)) {
        return;
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            x[i][j] = 1;
        }
    }
}

void Matrix::zeros() {
    if(!(rows > 0 && cols > 0)) {
        return;
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            x[i][j] = 0;
        }
    }
}

float &Matrix::operator()(int i, int j) {
    return x[i][j];
}

void Matrix::operator=(Matrix &matrix) {
    memcpy(x, matrix.x, rows * sizeof(float*));

    for(int i = 1; i < rows; i++) {
        x[i] = x[i-1] + cols;
    }
}

Matrix Matrix::operator*(float scalar) {
    Matrix temp(rows, cols);

    if(!(rows > 0 && cols > 0)){
        exit(0); 
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            temp.x[i][j] = x[i][j] * scalar;
        }
    }

    for(int i = 0; i < rows*cols; i++){
        temp.x[0][i] = x[0][i] * scalar;
    }

    return temp;
}