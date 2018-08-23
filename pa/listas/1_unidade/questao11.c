#include <stdio.h>
#include <string.h>

int main() {
    char   v[4];
    int    x[4];
    float  y[4];
    double z[4];

    printf("v = [\n");    
    for(int i = 0; i < 4; i++) {
        printf("  %p\n", v + i);
    }
    printf("]\n\n");

    printf("x = [\n");    
    for(int i = 0; i < 4; i++) {
        printf("  %p\n", x + i);
    }
    printf("]\n\n");

    printf("y = [\n");    
    for(int i = 0; i < 4; i++) {
        printf("  %p\n", y + i);
    }
    printf("]\n\n");
    
    printf("z = [\n");    
    for(int i = 0; i < 4; i++) {
        printf("  %p\n", z + i);
    }
    printf("]\n\n");
}

/*
Exemplo de saída :

// char ocupa 1 byte
v = [
  0x7ffd5149bf20
  0x7ffd5149bf21
  0x7ffd5149bf22
  0x7ffd5149bf23
]

// int ocupa 4 byte
x = [
  0x7ffd5149bee0
  0x7ffd5149bee4
  0x7ffd5149bee8
  0x7ffd5149beec
]

// float ocupa 4 bytes
y = [
  0x7ffd5149bef0
  0x7ffd5149bef4
  0x7ffd5149bef8
  0x7ffd5149befc
]

// double ocupa 8 bytes
z = [
  0x7ffd5149bf00
  0x7ffd5149bf08
  0x7ffd5149bf10
  0x7ffd5149bf18
]
*/