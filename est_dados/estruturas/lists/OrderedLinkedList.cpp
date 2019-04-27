#include "OrderedLinkedList.hpp"
/*
    // Class Constructor
    OrderedLinkedList::OrderedLinkedList() {

        head->data = 0;
        head->next = NULL;

    }

    // Class Destructor
    OrderedLinkedList::~OrderedLinkedList() {
        
        Node *tmp;
        while(head) {
            tmp = head->next;
            delete head;
            head = tmp;
        }

    }

    int OrderedLinkedList::search(int key, Node *ant, Node *pont) {

    }

    int OrderedLinkedList::insert(int element) {
        cout << "--------------------------\n";
        cout << "Inserir: " << element << endl;

        cout << "\nAlocar novos nodes\n";
        Node *node1 = new Node();
        Node *node2 = new Node();
        Node *node3 = new Node();

        node1->data = element;
        node1->next = node2;

        node2->data = 4;
        node2->next = node3;

        node3->data = 6;
        node3->next = NULL;

        cout << "Node1: \n\tAddress:" << node1 << "\n\tData: " << node1->data << "\n\tNext: " << node1->next<< "\n";
        cout << "Node2: \n\tAddress:" << node2 << "\n\tData: " << node2->data << "\n\tNext: " << node2->next<< "\n";
        cout << "Node3: \n\tAddress:" << node3 << "\n\tData: " << node3->data << "\n\tNext: " << node3->next<< "\n\n";


        cout << "\nMudar o ponteiro da head e aumentar o tamanho.\n";
        head->data += 3;
        head->next = node1;
        cout << "Head: \n\tAddress:" << head << "\n\tData: " << head->data << "\n\tNext: " << head->next<< "\n\n";

        cout << "--------------------------\n";
        
        if (head->next == NULL) {
            Node *newNode = new Node;
            newNode->data = element;
            newNode->next = NULL;

            head->next = newNode;
            head->data++;
        }else {
            cout << "\n\nVerificar onde inserir.\n\n";
        }
        

        Node *newNode = new Node;
        newNode->data = element;
        newNode->next = NULL;    

        if(head == NULL) {
            head = newNode;
            tail = newNode;

            newNode = NULL;
        }else {
            tail->next = newNode;
            tail = newNode;
        }
        
    }

    int OrderedLinkedList::remove(int element) {}

    int OrderedLinkedList::size() {
        return head->data;
    }

    Node* OrderedLinkedList::getHead() {
        return head;
    }
*/

// Class Constructor
OrderedLinkedList::OrderedLinkedList() {
    
    this->length = 0;
    this->head = NULL;

}

// Class Destructor
OrderedLinkedList::~OrderedLinkedList() {}

// Sobrecarga para mostrar a lista com cout
ostream& operator <<(ostream &os, OrderedLinkedList &list) {
    if(list.head->next == NULL)
        os << "Head -> NULL\n";
    else
        os << "Head -> ";
    
    for (Node *it = list.head->next; it != NULL; it = it->next) {
        os << it->data << " -> ";

        if (it->next == NULL) os << "NULL\n";
    }

    return os;
}
