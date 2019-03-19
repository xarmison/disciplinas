#include <iostream>
using namespace std;

int factorial(int n) {
    int fact = 1;
    while(n > 0) {
        fact *= n;
        n--;
    } 

    return fact;
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

    cout << "\nFatorial dos numeros na sequencia: \n";
    for(int i = 0; i < n; i++) {
        cout << seq[i] << "! = " << factorial(seq[i]) << endl;
    }
    cout << endl;

    return 0;
}