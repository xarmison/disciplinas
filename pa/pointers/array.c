#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printArray(int *arr, int n) {
    for(int i=0; i < n; i++) {
        printf("arr[%d] = %d ", i, arr[i]);
    }
    printf("\n\n");
}

int main() {\

    int n = 10;

    int *x = (int *)malloc(n * sizeof(int)), *y = (int *)malloc(n * sizeof(int));

    srand(time(NULL));

    for(int i=0; i < n; i++) {
        x[i] = rand() % 30 + 10;
    }

    memcpy(y, x, n * sizeof(int));

    printf("Array x: \n");
    printArray(x, n);

    printf("Array y: \n");
    printArray(y, n);

    free(x);
    free(y);

    return 0;
}
