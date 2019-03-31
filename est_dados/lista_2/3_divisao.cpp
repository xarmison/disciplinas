#include <iostream>
using namespace std;

bool divisao(int &m, int &n, int d) {
    if(m%d == 0 || m%d == 0) {
        m /= d;
        n /= d;

        return true;
    }else {
        return false;
    }
}

int main(int argc, char **argv) {

    int m = 50, n = 25, d = 10;

    bool ans = divisao(m, n, d);

    cout << "Ans: " << ans << "\nm: " << m << "\nn: " << n << "\n\n";
    

    return 0;
}