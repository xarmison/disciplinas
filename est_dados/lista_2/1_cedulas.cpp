#include <iostream>
using namespace std;

void cedulas(float v, int &um, int &cinco, int &dez, int &vin) {

    if(v/20 > 0) {
        vin = int(v/20);
        v = v - int(v/20)*20;
    }

    if(v/10 > 0) {
        dez = int(v/10);
        v = v - int(v/10)*10;
    }

    if(v/5 > 0) {
        cinco = int(v/5);
        v = v - int(v/5)*5;
    }

    um = int(v);    
    
}

int main() {
    cout << "\n\t_______ATM_______\n\n";

    float v = 25;
    cout << "Insira um valor em dinheiro: ";
    cin >> v;

    int um = 0, cinco = 0, dez = 0, vin = 0;
    cedulas(v, um, cinco, dez, vin);

    cout << endl 
        << v << " sera pago com:\n"
        << um << " ceulas de um.\n"
        << cinco << " ceulas de cinco.\n"
        << dez << " ceulas de dez.\n"
        << vin << " ceulas de vinte.\n\n";

    return 0;
}