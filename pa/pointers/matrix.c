#include <stdio.h>
#include <stdlib.h>

int** allocMatrix(int nl, int nc) {
    int **matrix = (int **)malloc(nl * sizeof(int *));

    for(int i=0; i < nl; i++) {
       matrix[i] = (int *)malloc(nc * sizeof(int));
    }

    return matrix;
}

void freeMatrix(int **matrix, int nl) {
    for(int i=0; i < nl; i++) {
        free(matrix[i]);
    }

    free(matrix);
}

void printMatrix(int **matrix, int nl, int nc) {
    printf("[\n");
    for(int i=0; i < nl; i++) {
        printf("  [");
        for(int j=0; j < nc; j++) {
            printf(" %d ", matrix[i][j]);
        }
        printf("]\n");
    }
    printf("]\n");
}

int main() {
    int **y, **z, nl = 3, nc = 4;

    y = allocMatrix(nl, nc);

    for(int i=0; i < nl; i++) {
       for(int j=0; j < nc; j++) {
           y[i][j] = rand() % 10;          
       }
    }

    z = allocMatrix(nc, nl);

    for(int i=0; i < nc; i++) {
       for(int j=0; j < nl; j++) {
           z[i][j] = y[j][i];          
       }
    }

    printf("\nOriginal Matrix:\n");
    printMatrix(y, nl, nc);

    printf("\nTransposed Matrix:\n");
    printMatrix(z, nc, nl);

    freeMatrix(y, nl);
    freeMatrix(z, nc);

    return 0;
}
