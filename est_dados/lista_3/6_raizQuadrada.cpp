#include <iostream>
using namespace std;

// Simula o calculo da raiz quadrada com uma busca binaria
double raizQuadrada(double n, double eps) {
    if(n < 0)
        return 0;

    // Realiza a busca binaria
    double first = 0, last = n, middle, ans;

    while(first <= last) {
        middle = (first+last)/2;

        if((middle*middle) == n) {
            ans = middle;
            break;
        }else {
            if((middle * middle) < n) {
                first = middle + 1;
                ans = middle;
            }else 
                last = middle - 1;
        }
    }

    float inc = 0.1;
    for(int i = 0; i < eps; i++) {
        while((ans*ans) <= n)
            ans += inc;

        // ans^2 > n
        ans -= inc;
        inc /= 10;
    }

    return ans;
}

int main(int argc, char **argv) {

    int num, eps;
    cout << "Insira o numero para o calculo da raiz quadrada e a precisao desejada: ";
    cin >> num >> eps;

    double raiz = raizQuadrada(num, eps);

    cout << "\nRaiz de " << num << " por busca binaria e " << raiz << "\n\n";

    return 0;
}