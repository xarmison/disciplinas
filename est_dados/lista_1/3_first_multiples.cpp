#include <iostream>
using namespace std;


int main(int argc, char **argv) {
    int n, i, j;
    cout << "Digite um numero inteiro positivo: ";
    cin >> n;
    cout << "Digite dois numeros naturais nao nulos: ";
    cin >> i >> j;

    int cont = 0, fa = 0, fb = 0;
    cout << endl << "Saida: \n";
    while(cont < n) {
        int a = fa * i, b = fb * j;

        if(a == b) {
            cout << a << " ";
            
            fa++;
            fb++;
            cont++;
        }else { 
            cout << a << " " << b << " ";

            fa += 2;
            fb++;
            cont += 2;
        }
    }
    cout << "\n\n";

    return 0;
}