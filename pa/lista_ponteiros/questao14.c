#include <stdio.h>
#include <stdlib.h>

void printArray(float *arr, int n) {
    printf("\n[ ");
    for(int i=0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf(" ]\n\n");
}

// Implementação do algoritmo insertion sort
void insertionSort(float *arr, int n) {
    if(n > 0) {
        insertionSort(arr, n-1);
        float x = arr[n];
        int j = n-1;

        while(j >= 0 && arr[j] > x){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = x;
    }
}

int main() {
    int n;
    printf("Insira a quantiade de itens: ");
    scanf("%d", &n);

    float *arr = (float *)malloc(n * sizeof(float));

    printf("Preencha o array (insira espaço entre os itens): ");
    for(int i = 0; i < n; i++) {
        scanf("%f", arr + i);
    }

    printf("\nArray inserido: ");
    printArray(arr, n);

    printf("Array ordenado: ");
    insertionSort(arr, n-1);
    printArray(arr, n);

    free(arr);

    return 0;
}
