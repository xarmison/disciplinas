#include <iostream>
#include <vector>
using namespace std;

void sumSeq(int &sum) {
    int x;
    cin >> x;
    if (x == 0)
        return;
    if (x % 2 == 0)
        sum += x;

    sumSeq(sum);
}

int main(int argc, char **argv) {

    int n;
    cout << "Digite um numero natural: ";
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        
        cout << endl << "Insira a sequencia " << i+1 <<" (0 para terminar): ";

        int sum = 0;
        sumSeq(sum);

        cout << "--> Soma dos pares da sequencia " << i+1 << ": " << sum << endl;
    }
    cout << endl;
    
    return 0;
}