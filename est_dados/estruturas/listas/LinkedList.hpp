#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <fstream>
#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        
};

class LinkedList {
    private:
        int length;
        Node *head;

    public:
        LinkedList();
        ~LinkedList();

        void search(int key, Node *ant, Node *pont);

        bool insert(int element);
        bool remove(int element);

        friend ostream& operator << (ostream &os, LinkedList &list);
};

#endif  // LINKEDLIST_H