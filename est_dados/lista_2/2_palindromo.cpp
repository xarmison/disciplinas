#include <iostream>
#include <cmath>
using namespace std;

void quebra(int n, int &prim, int &ult, int &miolo) {
    int k = 0, i = n;
    while(i > 0) {
        i = i/10;
        k++;
    }
    
    prim = n/pow(10, k-1);
    ult = n%10;
    miolo = (n - prim*pow(10, k-1))/10;

}

bool isPalindrono(int n) {

    int prim, ult, miolo;
    quebra(n, prim, ult, miolo);

    if(prim != ult) {
        return false;
    }

}

int main() {
    cout << "\n\t_______Palindrono_______\n\n";

    int n;
    cout << "Insira um numero natural: ";
    cin >> n;

    if(isPalindrono(n)) 
        cout << n << " e palindrono\n\n";
    else 
        cout << n << " nao e palindrono\n\n";

    return 0;
}