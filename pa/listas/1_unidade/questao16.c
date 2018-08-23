/*
    Entendi que a inplementação solicitada foi 
    usar a função qsort através de um ponteiro 
    para ela
*/

#include <stdio.h>
#include <stdlib.h>

void printArray(float *arr, int n) {
    printf("\n[ ");
    for(int i=0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf(" ]\n\n");
}

int compare(const void *a, const void *b) {
  return ( *(float*)a - *(float*)b );
}


int main() {
    // Recebe do úsuario a quantiade de itens que serão inseridos no array
    int n;
    printf("Insira a quantiade de itens: ");
    scanf("%d", &n);

    // Aloca o array na memória
    float *arr = (float *)malloc(n * sizeof(float));

    // Recebe do úsuario os elementos do array
    printf("Preencha o array (insira espaço entre os itens): ");
    for(int i = 0; i < n; i++) {
        scanf("%f", arr + i);
    }

    // Mostra o array inserido
    printf("\nArray inserido: ");
    printArray(arr, n);

    /*
        Ponteiro para a função qsort utilizando
        um ponteiro para a função de comparação 
        definida
    */
    void (*ptr_qsrot)(void *arr, size_t n, size_t size, int(*compar)(const void *, const void *));
    ptr_qsrot = qsort;

    // Ordena e mostra o array ordenado
    printf("\nArray ordenado: ");
    ptr_qsrot(arr, n, sizeof(float), compare);
    printArray(arr, n);
    
    free(arr);
    
    return 0;
}