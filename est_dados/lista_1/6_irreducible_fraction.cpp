#include <iostream>
using namespace std;

int MDC(int a, int b) {
    if(a == 0)
        return b;
    
    return MDC(b%a, a);
}

int main(int argc, char **argv) {

    int a, b;
    cout << "Insira a fracao a/b no formato a b: ";
    cin >> a >> b;
   
    cout << endl << "Fracao irredutivel de " << a << "/" << b << " e: "
        << a/MDC(a, b) << "/" << b/MDC(a, b) << "\n\n"
    ;  

    return 0;
}