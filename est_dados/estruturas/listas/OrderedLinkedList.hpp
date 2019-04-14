#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H

#include <fstream>
#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class OrderedLinkedList {
    private:
        int length;
        Node *head;

    public:
        OrderedLinkedList();
        ~OrderedLinkedList();

        int search(int element);
        int insert(int element);
        int remove(int element);

        int size();

        Node* getHead();

        friend ostream& operator << (ostream &os, OrderedLinkedList &list);
    
};

#endif // ORDEREDLINKEDLIST_H