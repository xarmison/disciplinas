#include <iostream> 
#include "BST.hpp"
using namespace std;

int main(int argc, char **argv) {

    BST tree;
    /* 
              50 
           /     \ 
          35      70 
         /  \    /  \ 
       25   40  65   90 
        \            /
        30          80   
    */
    tree.insert(50);
    tree.insert(35); 
    tree.insert(25); 
    tree.insert(30); 
    tree.insert(40); 
    tree.insert(70); 
    tree.insert(65); 
    tree.insert(90);
    tree.insert(80);

    cout << "\nArvore em pre ordem: ";
    tree.preOrder();

    int n;
    cout << "\n\nProcurar por: ";
    cin >> n;

    Node *searchResult = tree.search(n);
    if(searchResult != NULL)
        cout << searchResult->key << " esta na arvore." << endl;
    else
        cout << n << " nao esta na arvore." << endl;
    
    cout << "\nInserir 100";
    tree.insert(100);
    cout << "\nArvore apos insercao: ";
    tree.preOrder();
    cout << "\n\n";

    /* 
              50 
           /     \ 
          35      70 
         /  \    /  \ 
       25   40  65   90 
        \           /  \
        30         80  100 
    */

    cout << "Remover 70";
    tree.remove(70);
    cout << "\nArvore apos remocao: ";
    tree.preOrder();
    cout << "\n\n";

    /* 
              50 
           /     \ 
          35      80 
         /  \    /  \ 
       25   40  65   90 
        \             \
        30           100 
    */

    return 0;
}