#include <iostream>
using namespace std;

int main(int argc, char **argv) {

    int m, n;
    cout << "Digite dois numeros naturais: ";
    cin >> m >> n; 

    int val, max = 0, pair_x, pair_y;
    for(int x = 1; x <= m; x++) {
        for(int y = 1; y <= n; y++) {
            
            val = x*y - (x*x) + y;

            if(val > max) {
                max = val;
                pair_x = x;
                pair_y = y;
            }
        } 
    } 

    cout << "\n(" << pair_x << ", " << pair_y << ") e o par com valor maximo (" << max << ") para a expressao.\n\n"; 

    return 0;
}