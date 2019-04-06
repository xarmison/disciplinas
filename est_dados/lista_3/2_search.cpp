#include <iostream>
#include <time.h>
#define MAX 1000000
using namespace std;

int sequentialSearch(int *arr, int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i;
    }

    return -1;
}

int orderedSequentialSearch(int *arr, int n, int key) {
    int i = 0;

    while((i < n) && (key > arr[i])) 
        i++;

    if(arr[i] == key) 
        return i;
    else
        return -1;
}

int binarySearch(int *arr, int n, int key) {
    int first = 0, last = n, middle;

    while(first < last) {
        middle = (first+last)/2;

        if(arr[middle] == key)
            return middle;
        else {
            if(arr[middle] < key)
                first = middle + 1;
            else 
                last = middle - 1;
        }
    }

    return -1;
}

int recursiveBinarySearch(int *arr, int key, int first, int last) {
    int middle = (first+last)/2;

    if(arr[middle] == key)
        return middle;
    
    if(first >= last)
        return -1;

    else {
        if(arr[middle] < key)
            return recursiveBinarySearch(arr, key, middle+1, last);
        else 
            return recursiveBinarySearch(arr, key, first, middle-1);
    }
}

int main(int argc, char **argv) {

    int arr[MAX];
    for(int i = 0; i < MAX; i++) 
        arr[i] = i;

    cout << endl;
    int key;
    cout << "Insira a chave a ser buscada: ";
    cin >> key;

    clock_t begin = clock();
    int pos = sequentialSearch(arr, MAX, key);
    clock_t end = clock();
    cout << endl << "Chave encontrada na posicao " << pos << endl;
    cout << "Busca sequencial levou " << (double)(end - begin)/CLOCKS_PER_SEC << "s\n\n";

    begin = clock();
    pos = orderedSequentialSearch(arr, MAX, key);
    end = clock();
    cout << endl << "Chave encontrada na posicao " << pos << endl;
    cout << "Busca sequencial ordenada levou " << (double)(end - begin)/CLOCKS_PER_SEC << "s\n\n";

    begin = clock();
    pos = binarySearch(arr, MAX, key);
    end = clock();
    cout << endl << "Chave encontrada na posicao " << pos << endl;
    cout << "Busca binaria levou " << (double)(end - begin)/CLOCKS_PER_SEC << "s\n\n";

    begin = clock();
    pos = recursiveBinarySearch(arr, key, 0, MAX);
    end = clock();
    cout << endl << "Chave encontrada na posicao " << pos << endl;
    cout << "Busca binaria recursiva levou " << (double)(end - begin)/CLOCKS_PER_SEC << "s\n\n";

    return 0;
}