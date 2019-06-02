/*
    Construir uma heap com a razão entre o valor e o peso da barra,
    remover a raiz da heap até que a mochila esteja cheia
*/

#include <iostream>
using namespace std;

// Estrutura para armazenar a valor e o peso de uma barra de ouro
struct GoldBar {
    int value, weight;
};

// Estrutura para armazenar a chave e a antiga posição no vetor
struct Element {
    int rate, pos;
};

// Indice do filho esquerdo de i
int left(int i) { return (2 * i + 1); }

void swap(Element *x, Element *y) {
    Element temp = *x;
    *x = *y;
    *y = temp;
}

void descer(Element *heap, int i, int n) {
    int j = left(i);
    if (j <= n) {
        if (j < n) 
            if (heap[j + 1].rate > heap[j].rate) j++;
            
        if (heap[i].rate < heap[j].rate) {
            swap(&heap[i], &heap[j]);
            descer(heap, j, n);
        }
    }
}

/*
    Percorre os nós que não são trivialmente folhas
    e os desce na árvore que a heap representa
*/
void heapify(Element *heap, int n) {
    for (int i = (n-1) / 2; i >= 0; i--) {
        descer(heap, i, n);
    }
}

int main(int argc, char **argv) {
    // Barras de ouro no cofre
    GoldBar bars[10] = {
        {60, 10},  {120, 30}, {100, 20}, {273, 30}, {803, 45},
        {905, 67}, {283, 53}, {701, 35}, {725, 56}, {750, 43}
    };
    
    // Pesso máximo a se levado
    int maximumWeight = 100;

    // Cria-se um vetor com o razão do valor pelo peso das barras
    Element valueRate[10];
    for(int i = 0; i < 10; i++) {
        valueRate[i] =  {
            // Valor da razão
            bars[i].value / bars[i].weight,
            // Posição no vetor de barras
            i
        };
    }
    // Transforma o array de razões em uma max heap
    heapify(valueRate, 10);
    cout << "Heap: [";
    for(Element elem : valueRate) {
        cout << "(" << elem.rate << ", " << elem.pos << ") ";
    }
    cout << "]\n\n";

    cout << "Hesit result\n";
    int sum = 0;
    for(auto i : valueRate) {
        if(sum < maximumWeight) {
            if(sum + bars[i.pos].weight > maximumWeight) { 
                double rate = (maximumWeight-sum)/(double)bars[i.pos].weight;

                cout << rate << " of (" << bars[i.pos].value << ", " << bars[i.pos].weight << ")"
                    << " amounting to ("
                    << rate * bars[i.pos].value << ", "
                    << rate * bars[i.pos].weight 
                << ")\n"; 

                break;
            } else {
                cout << "Full: (" << bars[i.pos].value << ", " << bars[i.pos].weight << ")\n";
                sum += bars[i.pos].weight;
            }
        }

    }   

    return 0;
}