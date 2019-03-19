#include <iostream>
#include <iomanip>
using namespace std;

int getHipotenusa(int a, int b) { 
    return ((a*a) + (b*b));
}

int main(int argc, char **argv) {

    int n;
    cout << "Digite o tamanho maximo da hipotenusa: ";
    cin >> n;    

    cout << "\nTriangulos com valores de hipotenusa menos que " << n << ": \n";
    int c = 1, soma = 0, trigs = 0;
    while(c <= n) {
        int temp_c = (c*c), a = 1, b = 1;
        while(a < n) {
            while(b < n) {
                if(temp_c == getHipotenusa(a, b)) {
                    cout << setw(3) << a << " - " << setw(3) << b << " - " << setw(3) << c << endl;
                    soma = soma + c;
                    a = n;
                    trigs++;
                    break;
                }
                b++;
            }
            a++;
            b = a;
        }
        c++;
    }
    cout << "\nTotal: " << trigs << " triangulos.\n\n";

    return 0;
}