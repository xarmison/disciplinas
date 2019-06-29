#include <iostream>
//#include "OrderedSequentialList.hpp"
//#include "OrderedLinkedList.hpp"
#include "LinkedList.hpp"

using namespace std;
/*
void testOrderedSequentialList() {
    // Cria uma lista com 10 elementos
    OrderedSequentialList lista(10);

    for (int i = 0; i < 9; i++) {
        lista.insert(2*i);
    }

    lista.insert(1);

    cout << "\nLista Ordenada: \n" << lista << endl;

    cout << "Remover 1.\n";
    lista.remove(1);

    cout << "\nLista apos remocao: \n" << lista << endl;

    int key;
    cout << "Digite a chave a ser buscada: ";
    cin >> key;

    cout << "Buscar " << key << endl;
    int pos = lista.search(key);
    if(pos == -1)
        cout << "A chave " << key << " nao esta na lista!\n";
    else
        cout << "A chave " << key << " esta na posicao " << pos << endl;
}
*/
/*
void testOrderedLinkedList() {
    OrderedLinkedList lista;

    lista.insert(2); 
    //lista.insert(2);
    //lista.insert(4);
    
    //Node *temp = lista.getHead();
    //cout << "\nTemp: \n\tAddr: " << temp << "\n\tData: " << temp->data << "\n\tNext: " << temp->next << endl;

    cout << "\nLinked List: \n" << lista;

}
*/

void testLinkedList() {
    LinkedList lista;

    for(int i = 0; i < 10; i++) {
        lista.insert(2*i);
    }

    cout << "Lista: \n" << lista << endl;

    cout << "\nProcurando 10 na lista\n";
    Node *anterior, *procurado;
    lista.search(10, anterior, procurado);
    
    cout << "10 esta na posicao " << procurado << " precedido por " << anterior;

}

int main(int argc, char **argv) {

    testLinkedList();

    cout << "\nSeguindo a vida na main\n\n";

    int a = 10;
    int b = a;

    return 0;
}