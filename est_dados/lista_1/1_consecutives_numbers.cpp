#include <iostream>
using namespace std;

int main() {

	int n;
	cout << "Insira um numero inteiro: ";
	cin >> n;

	int i = n;
	while(i > 0) {
		if(i == i%10) {
			cout << n << " possui digitos consecutivos iguais. \n";
			break;
		}
		else {
			i = i%10;
		}
	}

	return 0;
}
