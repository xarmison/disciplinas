#ifndef ORDEREDSEQUENTIALLIST_H
#define ORDEREDSEQUENTIALLIST_H

#include <fstream>
#include <cstdlib>
#include <iostream>
using namespace std;

class OrderedSequentialList {
    private:
        int size, length, *arr;

    public:
        OrderedSequentialList(int _size);
        ~OrderedSequentialList();

        int search(int key);
        int bsq(int key);

        int insert(int element);
        int remove(int element);

        int getLength();

        friend ostream& operator << (ostream &os, OrderedSequentialList &list);
};

#endif  // ORDEREDSEQUENTIALLIST_H