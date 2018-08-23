#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void matrixMultiply(int **a, int **b, int **c, int nl_a, int nc_a, int nc_b) {
    
    for(int i = 0; i < nl_a; i++) {
        for(int j = 0; j < nc_b; j++) {
            int sum = 0;
            for(int k = 0; k < nc_a; k++) {
                sum += a[i][k] * b[k][j];
            }
            
            c[i][j] = sum;
        }
    }


}

void printMatrix(int **matrix, int nl, int nc) {
    printf("[\n");
    for(int i=0; i < nl; i++) {
        printf("  [");
        for(int j=0; j < nc; j++) {
            printf(" %4d ", matrix[i][j]);
        }
        printf("]\n");
    }
    printf("]\n\n");
}

int** allocMatrix(int nl, int nc) {
    int **matrix = malloc(nl * sizeof(int *));

	matrix[0] = malloc(nl * nc * sizeof(int));

	for(int i = 1; i < nl; i++)
		matrix[i] = matrix[0] + i * nc;

    return matrix;    
}

void populateMatrix(int **matrix, int nl, int nc) {

    for(int i = 0; i < nl; i++) {
        for(int j = 0; j < nc; j++){
            matrix[i][j] = rand() % 100;
        }
    }
}

int main() {
    int nl_a, nc_a, nl_b, nc_b;
    printf("Insira as dimensoes das matrizes(linhas colunas): ");
    scanf("%d %d %d %d", &nl_a, &nc_a, &nl_b, &nc_b);

    int **a = allocMatrix(nl_a, nc_a);
    int **b = allocMatrix(nl_b, nc_b);
    int **c = allocMatrix(nl_a, nc_b);
    

    srand(time(0));
    populateMatrix(a, nl_a, nc_a);
    populateMatrix(b, nl_b, nc_b);

    clock_t start_t = clock();
    matrixMultiply(a, b, c, nl_a, nc_a, nc_b);   
    clock_t end_t = clock();

    printf("\nA: ");
    printMatrix(a, nl_a, nc_a);

    printf("B: ");
    printMatrix(b, nl_b, nc_b);

    printf("C: ");
    printMatrix(c, nl_a, nc_b);

    printf("Multiplicação pelo metodo interativo(naive) levou %fs\n\n", (double)(end_t - start_t) / CLOCKS_PER_SEC);

    free(a);
    free(b);
    free(c);

    return 0;
}