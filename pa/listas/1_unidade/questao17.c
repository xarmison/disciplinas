#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Implementação do algoritmo insertion sort
void insertionSort(int *arr, int n) {
    if(n > 0) {
        insertionSort(arr, n-1);
        int x = arr[n];
        int j = n-1;

        while(j >= 0 && arr[j] > x){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = x;
    }
}

// Função de comparação para o qsort
int compare(const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

int main() {
    clock_t start_t, end_t;
    int n = 100000;
    
    // Aloca 3 arrays com n elementos
    int *arr1 = (int *)malloc(n * sizeof(int)),
    *arr2 = (int *)malloc(n * sizeof(int)),
    *arr3 = (int *)malloc(n * sizeof(int));

    // Preenche um array com numeros aleatórios
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        *(arr1 + i) = rand() % 100;        
    }

    // Copia o array deseordenado para ser utilizado pelas outras funções de ordenação
    memcpy(arr2, arr1, n * sizeof(int));
    memcpy(arr3, arr1, n * sizeof(int));

    // Benchmark das implementações
    printf("Benchmarking...\n");

    start_t = clock();
    insertionSort(arr1, n-1);
    end_t = clock();
    printf("Insertion sort levou: %fs\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);
    // Libera o array ordenado
    free(arr1);

    start_t = clock();
    qsort(arr2, n, sizeof(int), compare);
    end_t = clock();
    printf("Qsort levou: %fs\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);
    free(arr2);

    void (*ptr_qsrot)(void *arr, size_t n, size_t size, int(*compar)(const void *, const void *));
    ptr_qsrot = qsort;

    start_t = clock();
    ptr_qsrot(arr3, n, sizeof(int), compare);
    end_t = clock();
    printf("Qsort pelo ponteiro levou: %fs\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);
    free(arr3);

    return 0;
}