#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Solução recursiva para a torre de Hanoi
void recursiveHanoi(int n, string p1, string p2, string p3) {
    if (n == 1)
        cout << "\tMover o disco do topo de " << p1 << " para " << p2 << endl;
    else {
        recursiveHanoi(n-1, p1, p3, p2);
        cout << "\tMover o disco do topo de " << p1 << " para " << p2 << endl;
        recursiveHanoi(n-1, p3, p2, p1);
    }
}

// Solução iterativa para a torre de Hanoi utilizando uma pilha
struct Node {
    int n;
    string p1, p2, p3;
    Node *next;
};

// Aloca um novo nó
Node* newNode(int n, string p1, string p2, string p3) { 
    Node* node = new Node;

    node->n = n;
    node->p1 = p1;
    node->p2 = p2;
    node->p3 = p3;
    node->next = NULL; 

    return node; 
}

class Stack {
    private:
        Node *top;

    public:
        Stack() {
            this->top = new Node;
            this->top = NULL;
        }

        ~Stack() {
            while (this->top != NULL){
                Node *tmp = top;
                top = top->next;
                delete tmp;
            }
        }

        void push(int n, string p1, string p2, string p3) {
            Node *node = newNode(n, p1, p2, p3);
            node->next = this->top;
            this->top = node;
        }

        void pop() {
            if (this->top != NULL) {
                Node *tmp = this->top;
                this->top = this->top->next;
                delete tmp;
            } else {
                cout << "\nStack already empty!\n";
            }
        }

        bool empty() {
            if (this->top == NULL) 
                return true;
            else 
                return false;
        }

        Node* getTop() {
            return this->top;
        }

        friend ostream& operator << (ostream &os, Stack &stack) {
            for(Node *it = stack.top; it != NULL; it = it->next) {
                os << "(" 
                    << it->n  << ", " 
                    << it->p1 << ", " 
                    << it->p2 << ", " 
                    << it->p3 
                << ") -> ";
            }
            os << "NULL";

            return os;
        }
        
};

void swap(string &a, string &b) {
    string tmp = a;
    a = b;
    b = tmp;
}

void hanoi(int n, string p1, string p2, string p3) {
    Stack pilha;
    
    while(true) {
        // Simula a chamada recursiva
        while(n > 0) {
            pilha.push(n ,p1, p2, p3);
            swap(p2, p3);
            n--;
        }

        //cout << "\nPilha:\n\t" << pilha << endl;

        if(pilha.empty()) 
            break;
        else {
            n = pilha.getTop()->n;
            p1 = pilha.getTop()->p1;
            p2 = pilha.getTop()->p2; 
            p3 = pilha.getTop()->p3; 

            pilha.pop();
        }

        cout << "\tMover o disco do topo de " << p1 << " para " << p2 << endl;

        swap(p3, p1);
        n--;
    }

}

int main(int argc, char **argv) {
    int n;
    clock_t start, end;

    do {
        cout << "Insira o numero de discos: ";
        cin >> n;
    } while(n <= 0);

    cout << "\nSolucao recursiva:\n";
    start = clock();
    recursiveHanoi(n, "P1", "P2", "P3");
    end = clock();
    cout << "Foram gastos " << (double)(end - start) / CLOCKS_PER_SEC << "s\n";

    cout << "\nSolucao iterativa:\n";
    start = clock();
    hanoi(n, "P1", "P2", "P3");
    end = clock();
    cout << "Foram gastos " << (double)(end - start) / CLOCKS_PER_SEC  << "s\n";

    return 0;
}