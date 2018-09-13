#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void* myrealloc(void *old, int newBytes, int oldBytes){
    void *ptr = (void *)malloc(newBytes * sizeof(void));

    memcpy(ptr, old, oldBytes);

    return ptr;
}

void printArray(float *arr, int n) {
    printf("[");
    for(int i=0; i < n; i++) {
        printf(" %f ", arr[i]);
    }
    printf("]\n");
    printf("\n\n");
}

int main() {

    int n = 10;

    
    float *x = (float *)malloc(n * sizeof(float));
    printf("Original x position: %p\n", x);

    printf("\nSize of Void: %zu\n", sizeof(void));
    printf("Size of int: %zu\n", sizeof(int));

    srand(time(NULL));
    for(int i=0; i < n; i++) {
        x[i] = rand() % 10;
    }

    printf("x: ");
    printArray(x, n);

    x = myrealloc(x, 5 * sizeof(float), 10 * sizeof(float));
    printf("New x position: %p\n", x);

    printf("x: ");
    printArray(x, 5);

    return 0;
}