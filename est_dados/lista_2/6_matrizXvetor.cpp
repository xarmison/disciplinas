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
void multiplica(int A[MAX][MAX], int n, int *B, int m, int *C) {
    int sum;
    for(int i = 0; i < m; i++) {
        sum = 0;
        for(int j = 0; j < m; j++) {
            sum += A[i][j] * B[j];
        }
        C[i] = sum;
    }

}

int main(int argc, char **argv) {

    int A[MAX][MAX] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int B[MAX] = {10, 11, 12};

    int C[MAX];
    multiplica(A, 3, B, 3, C);

    cout << "\nResult = ";
    printArray(C, 3);
    cout << endl;

    return 0;
}