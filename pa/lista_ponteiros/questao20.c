#include "gc.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função de comparação para o qsort
int compare(const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

int main() {
    int n = 100;

    /*
        A memória utilizada para armazenar o array será 
        liberada entre as repetições do for
    */
    for (int i = 0; i < 100000; i++) {

        if (i % 10000 == 0) printf("\n\nHeap size before = %d\n", GC_get_heap_size());

        int *arr = (int *)GC_malloc(n * sizeof(int));

        srand(time(NULL));
        for(int j = 0; j < n; j++) {
            *(arr + j) = rand() % 100;        
        }

        qsort(arr, n, sizeof(int), compare);

        if (i % 10000 == 0) printf("Heap size after = %d\n\n", GC_get_heap_size());
    }
    
    return 0;
}