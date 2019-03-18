#include <iostream>
using namespace std;

int main(int argc, char **argv) {

    int n;
    cout << "Digite um numero natural: ";
    cin >> n;

    int a = 1, b = 2, c = 3;
    while(c < n){
        if(a*b*c == n) {
            cout << n << " e triangular\n";
            return 0;
        }    

        a = b;
        b = c;
        c++;
    }

    cout << n << " nao e triangular!\n";
    return 0;
}
