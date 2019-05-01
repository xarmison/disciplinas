#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <fstream>
using namespace std;

struct Node {
    int key;
    Node *next;
};

class Queue {
    private:
        Node *head, *tail;
    public:
        Queue();
        ~Queue();

        void push(int key);
        void pop();
        bool empty();

        Node* getHead();

        friend ostream& operator << (ostream &os, Queue &queue);  
};

#endif // QUEUE_H