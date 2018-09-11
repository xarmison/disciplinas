#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NCOLUNAS 32

unsigned char sentArray[8][NCOLUNAS] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0}
};

unsigned char receivedBytes[NCOLUNAS];
unsigned char receivedArray[8][NCOLUNAS];

void transmitByte(unsigned char byte);

void encodeArray(unsigned char dados[8][32]){
    unsigned char aux, byte;

    for(int i = 0; i < NCOLUNAS; i++) {
        // Reinicia aux e byte para cada coluna 
        aux = 128;
        byte = 0;
        // Percorre todas as colunas 
        for(int j = 0; j < 8; j++) {
            if(sentArray[j][i] == 1) {
                // Compara todas as posições de byte com aux 
                byte = byte | aux;
            }
            // Desloca o aux
            aux = aux >> 1; 
        }
        // Escreve o byte no array
        receivedBytes[i] = byte;
    }
}

void decodeArray(unsigned char array[NCOLUNAS]){
    unsigned char aux, byte;

    for(int i = 0; i < NCOLUNAS; i++) {
        byte = array[i];
        aux = 128;
        for(int j = 0; j < 8; j++) {
            if((aux & byte) > 0) {
                receivedArray[j][i] = 1;
            } else {
                receivedArray[j][i] = 0;
            }
            aux = aux >> 1;
        }
    }
}


void transmitByte(unsigned char byte){
  static int index=0;
  receivedBytes[index]=byte;
  index++;
}

void printReceived(){
  int i, j;
  for(i=0; i<8; i++){
    for(j=0; j<NCOLUNAS; j++){
      printf("%d",receivedArray[i][j]);
    }
    printf("\n");
  }
}

int main() {
    encodeArray(sentArray);
    decodeArray(receivedBytes);
    printReceived();
}