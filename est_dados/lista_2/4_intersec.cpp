#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#define MAX 100
using namespace std;

// O(n^2)
void intersec(int A[MAX+1], int B[MAX+1], int C[MAX+1]) {

    int size = 0, k = 1;
    for(int i = 1; i < A[0] + 1; i++) {
        for(int j = 1; j < B[0] + 1; j++) {
            if(A[i] == B[j]) {
                C[k] = A[i];
                size++;
                k++;
            }
        }
    }
    C[0] = size;
}

void printArray(int arr[MAX+1], int len) {
    cout << "[\n    ";
    for(int j = 1; j < len+1; j++) {
        cout << arr[j] << " ";
    }
    cout << "\n]\n";
}

int main(int argc, char **argv) {

    int A[MAX+1] = {5, 3, 5, 6, 2, 9}, B[MAX+1] = {5, 3, 9, 2, 4, 6}, C[MAX+1];

    cout << "\nlen(A) = " << A[0] << "\nA = ";
    printArray(A, A[0]);

    cout << "\nlen(B) = " << B[0] << "\nB = ";
    printArray(B, B[0]);

    intersec(A, B, C);
    cout << "\nlen(C) = " << C[0] << "\nC = ";
    printArray(C, C[0]);  

    return 0;
}