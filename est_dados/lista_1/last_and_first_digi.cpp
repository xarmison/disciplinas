#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Insira um numero inteiro: ";
	cin >> n;

	int i = n;
	int first = n%10;

	while(i > 0) {
		if(i <= 10) {
			int last = i;

			if(first == last)
				cout << "Primeiro e ultimos digito sao iguais.\n";
			else
				cout << "Primeiro e ultimos digito nao sao iguais.\n";

			break;
		}
		else
			i = i/10;
	}

	return 0;
}
