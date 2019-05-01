#include "Queue.hpp"

// Class Constructor
Queue::Queue() {
    this->head = new Node;
    this->tail = this->head;
    this->head->key = -1;  
	this->head->next = this->head; 
}

// Class Destructor
Queue::~Queue() {
    while (this->head != NULL) {
        Node *tmp = this->head;
        this->head = this->head->next;
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

void Queue::push(int key) {
    Node *previous = this->tail;
    Node *node = newNode(key);

    previous->next = node;
    this->tail = node;
}

void Queue::pop() {
    if (this->head != NULL) {
        Node *tmp = this->head;
        this->head = this->head->next;
        delete tmp;
    } else {
        cout << "\nQueue already empty!\n";
        return;
    }
}

bool Queue::empty() {
    if(this->head == NULL)
        return true;
    else
        return false;
}

Node* Queue::getHead() {
    return this->head;
}

ostream& operator << (ostream &os, Queue &queue) {
    for(Node *it = queue.head->next; it != NULL; it = it->next) {
        cout << it->key;
        
        if(it->next != NULL) 
            cout << " -> ";
        else
            cout << " -> NULL\n";
    }

    return os;
}

