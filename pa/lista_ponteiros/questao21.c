/*
    A seguinte aplicação demostrará a alocação
    e ordenação de arrays utilizando funções 
    nativas da linguagem comparada com funções
    da biblioteca Libgc
*/

#include "gc.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de comparação para o qsort
int compare(const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

void doWithMalloc() {
    int n = 1000;
    int *arr = (int *)malloc(n * sizeof(int));

    srand(time(NULL));
    for(int j = 0; j < n; j++) {
        *(arr + j) = rand() % 100;        
    }

    qsort(arr, n, sizeof(int), compare);
    
    free(arr);

}

void doWithGcMalloc() {
    int n = 1000;
    int *arr = (int *)GC_malloc(n * sizeof(int));

    srand(time(NULL));
    for(int j = 0; j < n; j++) {
        *(arr + j) = rand() % 100;        
    }

    qsort(arr, n, sizeof(int), compare);

}

int main() {

    clock_t start_t, end_t;
    
    int times = 100000;

    printf("Benchmarking...\n");

    start_t = clock();
    for(int i = 0; i < times; i++) {
        doWithMalloc();
    }
    end_t = clock();

    printf("%d ordenações utilizando malloc: %fs\n", times, (double)(end_t - start_t) / CLOCKS_PER_SEC);

    start_t = clock();
    for(int i = 0; i < times; i++) {
        doWithMalloc();
    }
    end_t = clock();

    printf("%d ordenações utilizando GC_malloc: %fs\n", times, (double)(end_t - start_t) / CLOCKS_PER_SEC);

    return 0;
}