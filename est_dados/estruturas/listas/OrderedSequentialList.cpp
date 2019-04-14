#include "OrderedSequentialList.hpp"

// Construtor da classe
OrderedSequentialList::OrderedSequentialList(int _size = 0) : size(_size) {
    if (size > 0) {
        arr = new int[size];
        length = 0;

        if (arr == NULL) {
            delete[] arr;
            cout << "Error allocating the List!\n";
            exit(0);
        }
    }
}

// Destrutor da classe
OrderedSequentialList::~OrderedSequentialList() { delete[] arr; }

// Busca binaria na lista
int OrderedSequentialList::search(int key) {
    int first = 0, last = length, middle;

    while (first < last) {
        middle = (first + last) / 2;

        if (arr[middle] == key)
            return middle;
        else {
            if (arr[middle] < key)
                first = middle + 1;
            else
                last = middle - 1;
        }
    }

    return -1;
}

// Busca a posição onde um novo elemento deve ser inserido na lista
int OrderedSequentialList::bsq(int key) {
    int i = 0;

    while((i < length) && (key > arr[i])) i++;

    return i;
}

// Insere uma elemento na lista
int OrderedSequentialList::insert(int element) {

    if (!length) {
        arr[0] = element;
        length++;

        return 1;
    }else if (length < size) {
        int i = bsq(element);
        
        if (arr[i] != element) {
            int j = length - 1;
            
            while (j >= i) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[i] = element;
            length++;

            return 1;
        } else {
            cout << "\nThe element is already in the list.\n";
            return -1;
        }

    } else {
        cout << "\nThe list is already filled!\n";
        return -1;
    }
}

// Remove um elemento da lista
int OrderedSequentialList::remove(int element) {

    if (length) {
        int i = bsq(element);
        
        if (arr[i] == element) {
            for (int j = i; j < length - 1; j++) {
                arr[j] = arr[j + 1];
            }

            length--;
        } else {
            cout << "THe element is not in the list!\n";
            return -1;
        }
    } else {
        cout << "The list is alread empty!\n";
        return -1;
    }
}

// Retorna o tamanho da lista
int OrderedSequentialList::getLength() {
    return length;
}

// Sobrecarga para mostrar a lista com cout
ostream& operator << (ostream &os, OrderedSequentialList &list) {
    for(int i = 0; i < list.length; i++) {
        os << list.arr[i];

        if(i != list.length-1)
            os << ", ";
    }
    os << "\n";
}
