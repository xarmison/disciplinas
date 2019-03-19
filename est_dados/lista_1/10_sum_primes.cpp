#include <iostream>
using namespace std;

bool isPrime(int n) {
    int divs = 0;
    for(int i = 1; i <= n; i++) {
        if(n%i == 0) {
            divs++;
        }
    }

    if(divs == 2) 
        return true;
    else 
        return false;
}

int sumPrimes(int len, int *seq) {
    int sum = 0;
    for(int i = 0; i < len; i++) {
        if(isPrime(seq[i]))
            sum += seq[i];
    }

    return sum;
}

int main(int argc, char **argv) {

    int n;
    cout << "Digite o comprimento da sequencia de numeros: ";
    cin >> n;

    int *seq = new int[n];
    cout << "Digite a sequencia: ";
    for(int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    cout << "\nSoma dos numeros primos na sequencia: " << sumPrimes(n, seq) << "\n\n";

    return 0;
}