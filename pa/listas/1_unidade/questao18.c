#include <stdio.h>
#include <stdlib.h>

int arrayAddition(int *arr1, int *arr2, int *soma, int n){
    for(int i = 0; i < n; i++) {
        soma[i] = arr1[i] + arr2[i];
    }
}

void printArray(int *arr, int n) {
    printf("\n[ ");
    for(int i=0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf(" ]\n\n");
}

int main() {
    // Recebe do úsuario a quantiade de itens que serão inseridos no array
    int n;
    printf("Insira a quantiade de itens dos vetores: ");
    scanf("%d", &n);

    // Aloca 3 arrays com n elementos
    int *arr1 = (int *)malloc(n * sizeof(int)),
    *arr2 = (int *)malloc(n * sizeof(int)),
    *soma = (int *)malloc(n * sizeof(int));

    // Preenche os vetores
    for(int i = 0; i < n; i++) {
        arr1[i] = rand() % 100; 
        arr2[i] = rand() % 100;       
    }

    printf("Array 1: ");
    printArray(arr1, n);

    printf("Array 2: ");
    printArray(arr2, n);

    printf("Soma dos arrays: ");
    arrayAddition(arr1, arr2, soma, n);
    printArray(soma, n);

    return 0;
}