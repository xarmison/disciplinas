#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int key;
    Node *next, *previous;
};

int calculate(Node *headPolinomio, int x) {
    int i = 0 , ans = 0;
    for(Node *it = headPolinomio->next; it != NULL; it = it->next) {
        ans += it->key * pow(x, i);
        i++;        
    }

    return ans;
}

Node* sumPolinomios(Node *headA, Node *headB) {
    Node *headC = new Node();
    
    Node *itA = headA->next, *itB = headB->next;
    while(itA != NULL && itB != NULL) {
        cout << "Sum " << itA->key  << " and " << itB->key << endl;


        itA = itA->next;
        itB = itB->next;
    }

}

int main(int argc, char **argv) {

    Node *headP = new Node();
    Node *no1P = new Node();
    Node *no2P = new Node();
    Node *no3P = new Node();
    Node *no4P = new Node();

    headP->previous = NULL;
    headP->next = no1P;

    no1P->key = 2;
    no1P->previous = headP;
    no1P->next = no2P;

    no2P->key = 5;
    no2P->previous = no1P;
    no2P->next = no3P;

    no3P->key = 7;
    no3P->previous = no2P;
    no3P->next = no4P;

    no4P->key = 3;
    no4P->previous = no3P;
    no4P->next = NULL;

    cout << "Chaves no polinomio P(x): ";
    int i = 0;
    for(Node *it = headP->next; it != NULL; it = it->next) {
        cout << it->key << "x^" << i << "  ";
        i++;
    }
    cout << "\n";

    cout << "Valor de P(10): " << calculate(headP, 10) << endl;

    Node *headQ = new Node();
    Node *no1Q = new Node();
    Node *no2Q = new Node();
    Node *no3Q = new Node();
    Node *no4Q = new Node();

    headQ->previous = NULL;
    headQ->next = no1Q;

    no1Q->key = 5;
    no1Q->previous = headQ;
    no1Q->next = no2Q;

    no2Q->key = 2;
    no2Q->previous = no1Q;
    no2Q->next = no3Q;

    no3Q->key = 9;
    no3Q->previous = no2Q;
    no3Q->next = no4Q;

    no4Q->key = 7;
    no4Q->previous = no3Q;
    no4Q->next = NULL;

    int j = 0;
    cout << "\nChaves no polinomio Q(x): ";
    for(Node *it = headQ->next; it != NULL; it = it->next) {
        cout << it->key << "x^" << j << "  ";
        j++;
    }
    cout << "\n";
    
    sumPolinomios(headP, headQ);

    return 0;
}