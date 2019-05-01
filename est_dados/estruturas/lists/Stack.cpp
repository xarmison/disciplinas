#include "Stack.hpp"

// Class Constructor
Stack::Stack() {
    this->top = new Node;
    this->top->next = NULL;
}

// Class Destructor
Stack::~Stack() {
    while (this->top != NULL){
        Node *tmp = top;
        top = top->next;
        delete tmp;
    }
}

// Aloca um novo nó
Node* newNode(int _key) { 
    Node* node = new Node;

    node->key = _key; 
    node->next = NULL; 

    return node; 
}

// Adiciona um nó no topo da pilha 
void Stack::push(int key) {
    Node *node = newNode(key);
    node->next = this->top;
    this->top = node;
}

// Remove o top da pilha
void Stack::pop() {
    if (this->top != NULL) {
        Node *tmp = this->top;
        this->top = this->top->next;

        delete tmp;
    } else {
        cout << "\nStack already empty!\n";
    }
}

Node* Stack::getTop() {
    return this->top;
}

ostream& operator << (ostream &os, Stack &stack) {
    for(Node *it = stack.top; it != NULL; it = it->next) {
        os << it->key << " -> ";
    }
    os << "NULL";

    return os;
}
