#include <iostream>
#include <fstream> 
#include <sstream> 
#include <vector>
#include "Screen.hpp"
#include "GeometricFigure.hpp"
#include "Line.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"

using namespace std;

int main(int argc, char** argv) {
    if(argc < 2) {
        cout << "Argumentos faltando!\nUso: ./output <caminho_para_instruções>\n";
        return -1;
    }

    ifstream file;
    Screen tela(0, 0);
    vector<GeometricFigure *> figs;

    file.open(argv[1]);
    if(!file.is_open()) {
        cout << "Error ao abrir o arquivo de instruções!\n";
        return -1;
    }

    while(file.good()) {
        string instruction, cmd;

        getline(file, instruction);
        instruction += " ";   

        if(!file.good()) break;
        
        stringstream ss(instruction);
        
        ss >> cmd;
        if(cmd.compare("dim") == 0) {
            int rows, cols;
            
            ss >> rows >> cols;

            tela = Screen(rows, cols);

        }else if(cmd.compare("line") == 0) {
            int x0, y0, x1, y1;
            char brush;

            ss >> x0 >> y0 >> x1 >> y1 >> brush;

            if(ss.good()){
                figs.push_back(new Line(x0, y0, x1, y1, brush));
            }else {
                figs.push_back(new Line(x0, y0, x1, y1, ' '));
            }

        }else if(cmd.compare("rectangle") == 0) {
            int x0, y0, width, height, fillMode;
            char brush;

            ss >> x0 >> y0 >> width >> height >> fillMode >> brush;

            if(ss.good()){
                figs.push_back(new Rectangle(x0, y0, width, height, fillMode, brush));
            }else {
                figs.push_back(new Rectangle(x0, y0, width, height, fillMode, ' '));
            }

        }else if(cmd.compare("circle") == 0) {
            int xc, yc, radius, fillMode;
            char brush;

            ss >> xc >> yc >> radius >> fillMode >> brush;

            if(ss.good()){
                figs.push_back(new Circle(xc, yc, radius, fillMode, brush));
            }else {
                figs.push_back(new Circle(xc, yc, radius, fillMode, ' '));
            }

        }
    }
    file.close();

    for(GeometricFigure* fig : figs) {
        fig->draw(tela);
    }

    cout << endl << tela << endl;

    ofstream out_file;
    out_file.open("output.txt");

    if(!out_file.is_open()) {
        cout << "Error ao abrir o arquivo de saida!\n";
        return -1;
    }

    out_file << tela;

    out_file.close();

    return 0;
}