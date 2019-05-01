#ifndef STACK_H
#define STACK_H

#include <fstream>
#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *next;
};

class Stack {
    private:
        Node *top;

    public:
        Stack();
        ~Stack();

        void push(int key);
        void pop();

        Node* getTop();

        friend ostream& operator << (ostream &os, Stack &stack);
};

#endif // STACK_H