/*
    Criar uma heap max com os k primeiros elementos da diferença de x e V,
    verificar a partir de k+1 se os elementos podem ser inseridos na heap
    (se são menores que a raiz da heap) e descer o elemento inserido.
*/

#include <iomanip>
#include <iostream>
using namespace std;

// Estrutura para armazenar a chave e a antiga posição no vetor
struct Element {
    int key, pos;
};

// Indice do filho esquerdo de i
int left(int i) { return (2 * i + 1); }

void swap(Element *x, Element *y) {
    Element temp = *x;
    *x = *y;
    *y = temp;
}

void print(int *heap, int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << setw(2) << heap[i] << " ";
    }
    cout << "]\n";
}

void printElements(Element *arr, int n) {
    cout << "[";
    for(int i = 0; i < n; i++) {
        cout << "(" 
            << setw(2) << arr[i].key << ", " 
            << setw(2) << arr[i].pos 
        << ") ";
    }
    cout << "]\n";
}

void descer(Element *heap, int i, int n) {
    int j = left(i);
    if (j <= n) {
        if (j < n) 
            if (heap[j + 1].key > heap[j].key) j++;
            
        if (heap[i].key < heap[j].key) {
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
    int x = 5, k = 3, v[6] = { 10, 2, 14, 4, 7, 6 };

    /*
        Cria-se um vetor com o modulo da diferença entra x e os elementos de v
        e salva os k primeiros em uma array para ser transformado na heap max
    */
    Element difference[6], heap[k];
    for(int i = 0; i < 6; i++) {
        difference[i] = { 
            // Valor absoluto da diferença 
            v[i] - x > 0 ? v[i] - x : -1 * (v[i] - x) , 
            // Posição no vetor
            i
        };
        
        if(i < k) 
            heap[i] = difference[i];
        
    } 

    // Transforma os k primeiros elementos em uma max heap
    heapify(heap, k);

    /*
        Percorre os elementos que não estão na heap e verifica 
        se devem ser inseridos e o procedimento descer é realizado 
        caso seja inserido 
    */
    for(int i = k; i < 6; i++) {
        if(heap[0].key > difference[i].key) {
            heap[0] = difference[i];
            descer(heap, 0, k-1);
        }
    }

    cout << "V:    "; print(v, 6);
    cout << "Diff: "; printElements(difference, 6);
    cout << "Heap: "; printElements(heap, 3);

    cout << "\n\nElementos de V mais proximos de " << x << ": ";
    for(Element elem : heap) {
        cout << v[elem.pos] << " ";
    }
    cout << "\n\n";


    return 0;
}