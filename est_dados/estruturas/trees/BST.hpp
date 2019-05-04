#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

struct Node { 
    int key; 
    Node *left, *right; 
}; 

class BST {
    private:
        Node *root;

        void insert(Node *node, int key);
        void inOrderPrint(Node *node);
        void postOrderPrint(Node *node);
        void preOrderPrint(Node *node);
        void deleteTree(Node *node);
        Node* search(Node *node, int target);
        Node* remove(Node *node, int target);

    public:
        BST();
        ~BST();

        // Operações

        // Insere um novo nó na árvore
        void insert(int key);
        // Deleta um nó da árvore
        void remove(int target);
        // Procura um nó na árvore
        Node* search(int target);

        // Percursos
        
        // Percurso em pré ordem
        void preOrder();
        // Percurso em ordem simétrica
        void inOrder();
        // Percurso em pos ordem
        void postOrder();
    
};

#endif // BST_H