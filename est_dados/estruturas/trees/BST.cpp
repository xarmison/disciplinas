#include "BST.hpp"

// Class Constructor
BST::BST() {
    this->root = NULL;
}

// Class Destructor
BST::~BST() {
    this->deleteTree(this->root);
}

void BST::deleteTree(Node *node) {
    if(node != NULL) {
        this->deleteTree(node->left);
        this->deleteTree(node->right);
        delete node;
    }
}

// Aloca um novo nó
Node* newNode(int _key) { 
    Node* node = new Node;

    node->key = _key; 
    node->left = NULL; 
    node->right = NULL; 

    return node; 
}

void BST::insert(Node *node, int key) {
    if(key < node->key){
		if(node->left != NULL)
			this->insert(node->left, key);
		else
			node->left = newNode(key);
		
	}else if(key >= node->key){
		if(node->right != NULL)
			this->insert(node->right, key);
		else
			node->right = newNode(key);
    }
}

void BST::insert(int key) {
    if(this->root == NULL) 
        this->root = newNode(key);
    else 
        this->insert(this->root, key);
}

// Encontra o menor filho de um nó
Node* minValueNode(Node *node) { 
    Node* curNode = node; 
  
    // Percorre os filhos da esquerda para encontrar o menor
    while (curNode->left != NULL) 
        curNode = curNode->left; 
  
    return curNode; 
} 

Node* BST::remove(Node *node, int target) {
    // Se target é menor que node, target está a esquerda    
    if(target < node->key)
        node->left = this->remove(node->left, target);
    
    // Se target é maior que node, target está a direita
    else if(target > node->key)
        node->right = this->remove(node->right, target);
    
    // Se target é igual node, então node deve ser deletado
    else {
        // Nó com apenas um filho        
        if(node->left == NULL) {
            Node *temp = node->right;
            delete node;
            return temp;
        } else if(node->right == NULL) {
            Node *temp = node->left;
            delete node;
            return temp;
        }

        // Nó com dois filhos: encontrar o menor filho na subarvore direita
        Node *temp = minValueNode(node->right);

        // Coloca o menor filho no lugar do nó
        node->key = temp->key;

        // Deleta o menor filho
        node->right = this->remove(node->right, temp->key);
    }
}

void BST::remove(int target) {
    if(this->root == NULL)
        return;

    this->remove(this->root, target);
}

Node* BST::search(Node *node, int target) {
    if(node == NULL || node->key == target)
        return node;
    
    if(node->key < target)
        return this->search(node->right, target);
    
    return this->search(node->left, target);
}

Node* BST::search(int target) {
    return this->search(this->root, target);
}

void BST::preOrderPrint(Node *node) {
    if(node != NULL) {
        cout << node->key << "  ";
        this->preOrderPrint(node->left);
        this->preOrderPrint(node->right);
    }
}

void BST::preOrder() {
    this->preOrderPrint(this->root);
}

void BST::inOrderPrint(Node *node) {
    if(node != NULL) {
        this->inOrderPrint(node->left);
        cout << node->key << "  ";
        this->inOrderPrint(node->right);
    }
}

void BST::inOrder() {
    this->inOrderPrint(this->root);
}

void BST::postOrderPrint(Node *node) {
    if(node != NULL) {
        this->postOrderPrint(node->left);
        this->postOrderPrint(node->right);
        cout << node->key << "  ";
    }
}

void BST::postOrder() {
    this->postOrderPrint(this->root);
}