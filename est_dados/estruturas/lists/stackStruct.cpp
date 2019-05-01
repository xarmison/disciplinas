#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *next;
};

// Aloca um novo nó
Node* newNode(int _key) { 
    Node* node = new Node;

    node->key = _key; 
    node->next = NULL; 

    return node; 
}

Node* push(Node *top, int key) {
    Node *node = newNode(key);
    node->next = top;
    top = node;
}

Node* pop(Node *top) {
    if (top != NULL) {
        Node *tmp = top;
        top = top->next;
        delete tmp;
        return top;
    } else {
        cout << "\nStack already empty!\n";
        return NULL;
    }
}

void printStack(Node *top) {
    cout << "\nStack: ";
    for(Node *it = top; it != NULL; it = it->next) {
        cout << it->key;
        
        if(it->next != NULL) 
            cout << " -> ";
        else
            cout << " -> NULL\n";
    }
}

void deleteStack(Node *top) {
    while (top != NULL) {
        Node *tmp = top;
        top = top->next;
        delete tmp;
    }
}

int main(int argc, char **argv) {
    Node *top = newNode(40);

    top = push(top, 32);
    top = push(top, 23);
    top = push(top, 100);

    printStack(top);
    
    top = pop(top);

    printStack(top);
    
    deleteStack(top);
    return 0;
}