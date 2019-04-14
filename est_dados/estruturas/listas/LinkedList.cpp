#include "LinkedList.hpp"

// Class Constructor
LinkedList::LinkedList() {
    this->length = 0;
    this->head = NULL;
}

// Class Destructor
LinkedList::~LinkedList() {
    Node* next = head;
    Node* cur = NULL;

    while (next != NULL) {
        cur = next;
        next = next->next;
        delete cur;
    }
}

bool LinkedList::insert(int element) {
    if (this->head == NULL) {
        Node* newNode = new Node();

        newNode->data = element;
        newNode->next = this->head;

        this->head = newNode;
        this->length++;

    } else {
        Node* node = this->head;
        while (node->next != NULL) node = node->next;

        Node* newNode = new Node();
        newNode->data = element;
        newNode->next = NULL;

        node->next = newNode;
        this->length++;
    }
}

void LinkedList::search(int key, Node *ant, Node *pont) {
    ant = this->head;
    pont = NULL;

    Node *ptr = this->head->next;
    while(ptr != NULL){
        if(ptr->data == key) {
            pont = ptr;
            break;
        }

        ant = ptr;
        ptr = ptr->next;
    }
    
}

// Sobrecarga para mostrar a lista com cout
ostream& operator<<(ostream& os, LinkedList& list) {
    for (Node* it = list.head; it != NULL; it = it->next) {
        os << it->data << "(" << it << ") -> ";

        if (it->next == NULL) os << "NULL\n";
    }

    return os;
}