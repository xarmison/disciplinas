#include <iostream>
#define MAX 100
using namespace std;

void printArray(int arr[MAX], int len) {
    cout << "[\n    ";
    for(int j = 0; j < len; j++) {
        cout << arr[j] << " ";
    }
    cout << "\n]\n";
}

// O(n^2)
void ordena(int A[MAX], int m) {
    // Insertion Sort
    int i = 1;

    do {
        int x = A[i], j = i-1;

        while((j >= 0) && (x < A[j])){
            A[j+1] = A[j];
            j--;   
        }

        A[j+1] = x;
        i++;
        
    } while (i < m);    
}

// O(n)
void intercala(int A[MAX], int m, int B[MAX], int n, int *C, int &k) {
    
    int i = 0, j = 0;
    while(i < m && j < n) {
        if (A[i] <= B[j]) {
            C[k] = A[i];
            i++;
        } else {
            C[k] = B[j];
            j++;
        }

        k++;
    }

    while (i < m) {
        C[k] = A[i];

        i++;
        k++;
    }

    while (j < n) {
        C[k] = B[j];

        j++;
        k++;
    }
}

int main(int argc, char **argv) {

    int A[MAX] = {2, 7, 4, 1, 8, 9, 0, 6, 5, 3};
    int B[MAX] = {12, 15, 17, 19, 11, 13, 16, 14, 10, 18};

    ordena(A, 10);
    ordena(B, 10);

    cout << "A = ";
    printArray(A, 10);

    cout << "\nB = ";
    printArray(B, 10);

    int C[2*MAX], k = 0;
    intercala(A, 10, B, 10, C, k);
    
    cout << "\nC = ";
    printArray(C, k);

    return 0;
}