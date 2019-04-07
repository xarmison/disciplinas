#include <iostream>
#include <limits>
using namespace std;

// ALgoritmos mais simples possivies
void findBiggest(int *arr, int n, int &largest, int &repeat) {
    largest = numeric_limits<int>::min();
    repeat = 0;
    
    for(int i = 0; i < n; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }

    for(int i = 0; i < n; i++) {
        if(largest == arr[i])
            repeat++;
    }
}

void findSmallest(int *arr, int n, int &smallest, int &repeat) {
    smallest = numeric_limits<int>::max();
    repeat = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    for(int i = 0; i < n; i++) {
        if(smallest == arr[i])
            repeat++;
    }
}

int main(int argc, char **argv) {

    int n;
    cout << "Insira a quantidade de elementos do vetor: ";
    cin >> n;

    int arr[n];
    cout << "Insira os elementos do vetor: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int largest, amountL;
    findBiggest(arr, n, largest, amountL);

    cout << "\nMaior numero na sequencia e " << largest << " que se repete " << amountL << " veze(s)\n\n";

    int smallest, amountS;
    findSmallest(arr, n , smallest, amountS);

    cout << "\nMenor numero na sequencia e " << smallest << " que se repete " << amountS << " veze(s)\n\n";


    return 0;
}