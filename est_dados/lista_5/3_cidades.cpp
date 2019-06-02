#include <iostream>
#include <fstream>
#define SIZE 6
using namespace std;

// Estrutura de para um nó da fila
struct Node {
    int key;
    Node *next;
};

// Aloca um novo nó
Node* newNode(int _key) { 
    Node* node = new Node;

    node->key = _key; 
    node->next = NULL; 

    return node; 
}

// Abstração das operações a serem realizadas na fila 
class Queue {
    private:
        Node *head, *tail;
    public:
        Queue() {
            this->head = new Node;
            this->head->key = -1; 

            this->tail = this->head;   
            this->head->next = this->head; 
        }

        ~Queue() {
            while (this->head != NULL) {
                Node *tmp = this->head;
                this->head = this->head->next;
                delete tmp;
            }
        }

        void push(int key) {
            Node *previous = this->tail;
            Node *node = newNode(key);

            previous->next = node;
            this->tail = node;
        }

        void pop() {
            if (this->head->next != this->head) {
                Node *tmp = this->head;
                this->head = this->head->next;
                delete tmp;
            } else {
                cout << "\nQueue already empty!\n";
                return;
            }
        }

        bool empty() {
            if(this->head == this->tail)
                return true;
            else
                return false;

        }

        bool isQueued(int key) {
            if(!this->empty())
                for(Node *it = this->head->next; it != NULL; it = it->next) {
                    if(it->key == key)
                        return true;
                }

            return false;
        }

        Node* getHead() {
            return this->head;
        }

        friend ostream& operator << (ostream &os, Queue &queue) {
            for(Node *it = queue.head->next; it != NULL; it = it->next) {
                cout << it->key;
                
                if(it->next != NULL) 
                    cout << " -> ";
                else
                    cout << " -> NULL\n";
            }

            return os;
        } 
};

void searchLine(int *connections, int *distances, Queue &fila, int &weight) {
    for(int i = 0; i < SIZE; i++) {
        if(connections[i]) {    
            // Existe uma conexão        
            if(!fila.isQueued(i) && distances[i] == -1) {
                // i não está na fila
                fila.push(i);                
                distances[i] = weight;
            } else 
                // i já está na fila ou possui um caminho menor
                weight--;
        }
    }
}

int main(int argc, char **argv) {

    // Representação das conexões 
    int cityConnections[SIZE][SIZE] = {
        { 0, 1, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 1, 0 },
        { 0, 0, 1, 0, 1, 0 }, 
        { 1, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 0, 0, 0 }
    };

    // Inicialmente adimite-se que não existe caminhos
    int distances[SIZE] = {-1, -1, -1, -1, -1, -1};

    int originCity = 3;
    cout << "Insira a cidade de origiem: ";
    cin >> originCity;

    // Caminho para a cidade de partida é zero
    distances[originCity] = 0;

    // Inicia-se uma fila para guardar os nós a serem procurados
    Queue fila;
    // Peso para as conexões iniciais
    int weight = 1;

    // Procura na linha do nó de origem
    searchLine(cityConnections[originCity], distances, fila, weight);  

    // Enquanto houverem nós com conexões pocura-se em suas repectivas linhas por outras conexões
    while(!fila.empty()) {
        int nextLine = fila.getHead()->next->key;
        weight++;
        fila.pop();

        searchLine(cityConnections[nextLine], distances, fila, weight);;
    }
    
    cout << "\nDistancias a partir do nó " << originCity << " no grafo fornecido: ";
    for(int i = 0; i < SIZE; i++) {
        cout << distances[i] << "  ";
    }
    cout << "\n\n";
    
    return 0;
}