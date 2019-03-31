#include <iostream>
using namespace std;

// O(2^n)
int fiboRecursive(int n) {
    if(n <= 1)
        return n;
    
    return fiboRecursive(n-1) + fiboRecursive(n-2);
}

// O(n)
int fiboVector(int n) {
    int fibo[n];
    fibo[0] = 0;
    fibo[1] = 1;

    if (n < 1 ) return fibo[n];

    for(int i = 2; i <= n; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    return fibo[n];
}

// O(n)
int fiboVariaveis(int n) {
    int a = 0, b = 1, next;

    for(int i = 1; i < n; i++) {
        next = a + b;
        
        a = b;
        b = next;
    }

    return next;
}

int main(int argc, char **argv) {
    int n;
    cout << "Insira o termo desejado: ";
    cin >> n;

    cout << "\nUtilizando o algoritmo iterativo com vetor...\n";
    cout << "Finobacci(" << n << "): " << fiboVector(n) << "\n\n";

    cout << "\nUtilizando o algoritmo iterativo com variaveis...\n";
    cout << "Finobacci(" << n << "): " << fiboVariaveis(n) << "\n\n";

    cout << "\nUtilizando o algoritmo recursivo...\n";
    cout << "Finobacci(" << n << "): " << fiboRecursive(n) << "\n\n";

    return 0;
}