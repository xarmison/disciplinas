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

Node* push(Node *tail, int key) {
    Node *previous = tail;
    Node *node = newNode(key);
    
    previous->next = node;
    tail = node;
}

Node* pop(Node *head) {
    if (head != NULL) {
        Node *tmp = head;
        head = head->next;
        delete tmp;
        return head;
    } else {
        cout << "\nQueue already empty!\n";
        return NULL;
    }
}

void printQueue(Node *head) {
    cout << "Queue: ";
    for(Node *it = head->next; it != NULL; it = it->next) {
        cout << it->key;
        
        if(it->next != NULL) 
            cout << " -> ";
        else
            cout << " -> NULL\n";
    }
}

void deleteQueue(Node *head) {
    while (head != NULL) {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main(int argc, char **argv) {

    Node *begin = new Node, *end = begin;
    begin->key = -1;  
	begin->next = begin; 

    end = push(end, 42);
    end = push(end, 20);
    end = push(end, 13);

    printQueue(begin);

    begin = pop(begin);

    printQueue(begin);

    deleteQueue(begin);
    return 0;
}