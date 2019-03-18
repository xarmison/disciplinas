#include <iostream>
using namespace std;

int mdc(int a, int b) {
    if(a == 0)
        return b;
    
    return mdc(b%a, a);
}

int main(int argc, char **argv) {

    int a, b;
    cout << "Insira dois numeros: " ;
    cin >> a >> b;

    cout << endl << "MDC(" << a << ", " << b << ") = " << mdc(a,b) << "\n\n"; 

    return 0;
}