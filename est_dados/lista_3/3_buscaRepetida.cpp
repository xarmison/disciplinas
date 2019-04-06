#include <iostream>
#define MAX 100
using namespace std;

void sequentialSearch(int *arr, int n, int key, int *positions, int &amount) {
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            positions[j] = i;
            
            j++;
        }
    }
    amount = j;
}

void binarySearch(int *arr, int n, int key, int *positions, int &amount) {
    int i = 0, first = 0, last = n, middle;
    while(first < last) {
        middle = (first+last)/2;

        if(arr[middle] == key) {
            positions[i] = middle;
            
            i++;
        }

        if(arr[middle] < key)
            first = middle + 1;
        else 
            last = middle - 1;
    }

    amount = i;
}

int main(int argc, char **argv) {

    int v[MAX] = {0, 1, 1, 2, 3, 4, 5, 5, 5, 6, 7, 8, 8, 9};
    
    int key, positions[MAX], amount;
    cout << "Insira a chave a ser buscada: ";
    cin >> key;

    sequentialSearch(v, 14, key, positions, amount);

    if(amount > 0) {
        cout << "\nChave encontrada nas posicoes: ";
        for(int i = 0; i < amount; i++) {
            cout << positions[i] << " ";
        }
        cout << "\n\n";
    }else 
        cout << "\nChave nao encontrada no array.\n\n";

    int positionsBinary[MAX], amountBinary;

    binarySearch(v, 14, key, positionsBinary, amountBinary);

    if(amountBinary > 0) {
        cout << "\nChave encontrada nas posicoes: ";
        for(int i = 0; i < amountBinary; i++) {
            cout << positionsBinary[i] << " ";
        }
        cout << "\n\n";
    }else 
        cout << "\nChave nao encontrada no array.\n\n";

    return 0;
}