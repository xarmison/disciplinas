#include <iostream>
using namespace std;

struct Node { 
    int key; 
    Node *left, *right; 
}; 

// Aloca um novo nó
Node* newNode(int _key) { 
    Node* node = new Node;

    node->key = _key; 
    node->left = NULL; 
    node->right = NULL; 

    return node; 
}

/*
    Busca um nó na árvore.
    Situações:
    0: Árvore vazia;
    1: Chave encontrada e curNode 
    aponta para o nó da chave;
    2: Chave não encontrada e curNode
    aponta para para o nó com a árvore
    esquerda vazia;
    3: Chave não encontrada e curNode
    aponta para para o nó com a árvore
    direita vazia; 
*/
void search2(Node *curNode, int target, int &situation) {

    if (curNode != NULL) {
        if (curNode->key == target)  
            situation = 1;
        else {
            if (target < curNode->key) {
                if (curNode->left == NULL) situation = 2;
                else {
                    curNode = curNode->left;
                    cout << "\nVou pra esquerda!\n";
                    search2(curNode, target, situation);
                }
            } else {
                if (curNode->right == NULL) situation = 3;
                else {
                    curNode = curNode->right;
                    cout << "\nVou pra direita!\n";
                    search2(curNode, target, situation);
                }
            }
        }

    }
}

// Percurso em pré ordem
void preOrder(Node *curNode) {
    if (curNode != NULL) {
        cout << curNode->key << "  ";
        preOrder(curNode->left);
        preOrder(curNode->right);
    }
}

// Percurso em ordem simétrica
void inOrder(Node *curNode)  { 
    if (curNode != NULL) { 
        inOrder(curNode->left); 
        cout << curNode->key << "  ";
        inOrder(curNode->right); 
    } 
} 

// Percurso em pos ordem
void postOrder(Node *curNode) {
    if (curNode != NULL) {
        postOrder(curNode->left);
        postOrder(curNode->right);
        cout << curNode->key << "  ";
    }
}

// Procura um nó na árvore
Node* search(Node *curNode, int target) { 
    // Casos base: curNode é null ou target está em curNode
    if (curNode == NULL || curNode->key == target) 
       return curNode; 
     
    // target é maior que key do curNode 
    if (curNode->key < target) 
       return search(curNode->right, target); 
  
    // target é menor que key do curNode 
    return search(curNode->left, target); 
} 

// Insere um novo nó na árvore
Node* insert(Node *node, int key)  { 
    // Se a árvore está vazia retorna um novo nó
    if (node == NULL) return newNode(key); 
  
    // Caso contrário, percorrer a árvore
    if (key < node->key) 
        // Inserir nó a esquerda
        node->left = insert(node->left, key); 
    else
        // Inserir nó a direita
        node->right = insert(node->right, key);    
  
    return node; 
} 

// Encontra o menor filho de um nó
Node* minValueNode(Node *node) { 
    Node* curNode = node; 
  
    // Percorre os filhos da esquerda para encontrar o menor
    while (curNode->left != NULL) 
        curNode = curNode->left; 
  
    return curNode; 
} 

// Deleta o nó e retorna quem ocupa seu lugar 
Node* deleteNode(Node *root, int target)  { 
    // Árvore vazia
    if (root == NULL) return root; 
  
    // Se target é menor que root, target está a esquerda
    if (target < root->key) 
        root->left = deleteNode(root->left, target); 
  
    // Se target é maior que root, target está a direita
    else if (target > root->key) 
        root->right = deleteNode(root->right, target); 
  
    // Se target é igual root, então root deve ser deletado
    else { 
        // Nó com apenas um filho
        if (root->left == NULL)  { 
            Node *temp = root->right; 
            delete root;
            return temp; 
        } 
        else if (root->right == NULL) { 
            Node *temp = root->left; 
            delete root;
            return temp; 
        } 

        // Nó com dois filhos: encontrar o menor filho na subarvore direita
        Node* temp = minValueNode(root->right); 

        // Coloca o menor filho no lugar do nó
        root->key = temp->key; 

        // Deleta o menor filho
        root->right = deleteNode(root->right, temp->key); 
    } 

    return root; 
} 

void deleteTree(Node *root) {
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main(int argc, char **argv) {
    /* 
              50 
           /     \ 
          35      70 
         /  \    /  \ 
       25   40  65   90 
        \            /
        30          80   
    */
    Node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 35); 
    insert(root, 25); 
    insert(root, 30); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 65); 
    insert(root, 90);
    insert(root, 80);  

    cout << "\nArvore em pre ordem: ";
    preOrder(root);

    cout << "\n\nProcurar por 40"; 

    Node *target = search(root, 40);
    if(target != NULL) {
        cout << "\nEncontrado " << target->key << " em " << target;
        cout << "\nDeveria ser " << root->left->right->key << " em " << root->left->right << endl;
    }

    cout << "\nInserir 100";
    insert(root, 100);
    cout << "\nArvore apos insercao: ";
    preOrder(root);
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
    deleteNode(root, 70);
    cout << "\nArvore apos remocao: ";
    preOrder(root);
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

    deleteTree(root);
    return 0;
}