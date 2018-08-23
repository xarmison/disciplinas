#include <stdio.h>

int soma(int a, int b){
    return a + b;
}

int main() {
    int x, y, z;

    // Ponteiro para funções que retornam int e tem dois int como argumentos
    int (*ptr)(int, int);

    printf("Insira dois numeros: ");
    scanf("%d %d", &x, &y);

    // aponta para o endereço da função
    ptr = soma;
    z = ptr(x, y);

    printf("Soma = %d\n", z);

    return 0;
}
