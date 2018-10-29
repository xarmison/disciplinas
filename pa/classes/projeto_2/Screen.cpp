#include "Screen.hpp"

// Bob o construtor 
Screen::Screen(int _rows, int _cols) {
    rows = _rows;
    cols = _cols;
    mat = vector<vector<char>>(rows, vector<char>(cols, ' '));
}

void Screen::setPixel(int x, int y) {
    mat[x][y] = brush;
}

void Screen::clear() {
    for(auto &line : mat) {
        for(auto &element : line) {
            element = ' ';
        }
    }
}

void Screen::setBrush(char _brush) {
    brush = _brush;
}

ostream& operator << (ostream &os, Screen &t) {
    for(auto &line : t.mat) {
        for(auto &element : line) {
            os << element;
        }
        os << '\n';
    }
    os << '\n';

    return(os);
}