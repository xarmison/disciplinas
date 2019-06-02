/*
    Compilar com c++ 11 e.g g++ -std=c++11 4_labirinto.cpp -o mazeSolver
*/
#include <iostream>
#define N 6
#include <iomanip>
using namespace std;

struct Point {
    int x, y;
};

struct Node {
    Point p;
    Node *next;
};

// Aloca um novo nó
Node* newNode(Point p) { 
    Node* node = new Node;

    node->p = p;
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
            this->head->p = { -1, -1 }; 

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

        void push(Point p) {
            Node *previous = this->tail;
            Node *node = newNode(p);

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

        bool isQueued(Point p) {
            if(!this->empty())
                for(Node *it = this->head->next; it != NULL; it = it->next) {
                    if(it->p.x == p.x && it->p.y == p.y)
                        return true;
                }

            return false;
        }

        Node* getHead() {
            return this->head;
        }

        friend ostream& operator << (ostream &os, Queue &queue) {
            for(Node *it = queue.head->next; it != NULL; it = it->next) {
                cout << "(" << it->p.x << ", " << it->p.y << ")";
                
                if(it->next != NULL) 
                    cout << " -> ";
                else
                    cout << " -> NULL\n";
            }

            return os;
        } 
};

// Abstração das operações a serem realizadas na pilha
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

        void push(Point p) {
            Node *node = newNode(p);
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

        Point getTop() {
            Point p = this->top->p;
            this->pop();

            return p;
        }

        friend ostream& operator << (ostream &os, Stack &stack) {
            for(Node *it = stack.top; it != NULL; it = it->next) {
                os << "(" << it->p.x << ", " << it->p.y << ") -> ";
            }
            os << "NULL\n";

            return os;
        }
        
};

// Verifica se um ponto está nos limites do labirinto
bool isInLimits(int x, int y) {
    if(x > N-1 || x < 0)
        return false;
    else if(y > N-1 || y < 0)
        return false; 
    
    return true;
}

// Verifica quais movimentos são validos 
void checkAllowedMoves(int maze[N][N], Point pos, Stack &stack, bool &addFlag) {

    if(isInLimits(pos.x - 1, pos.y) && maze[pos.x -1][pos.y] != -1) {
        stack.push(Point{pos.x - 1, pos.y});
        addFlag = true;
    }

    if(isInLimits(pos.x, pos.y + 1) && maze[pos.x][pos.y + 1] != -1) {
        stack.push(Point{pos.x, pos.y + 1});
        addFlag = true;
    }

    if(isInLimits(pos.x, pos.y - 1) && maze[pos.x][pos.y - 1] != -1) {
        stack.push(Point{pos.x, pos.y - 1});
        addFlag = true;
    }

    if(isInLimits(pos.x + 1, pos.y) && maze[pos.x + 1][pos.y] != -1) { 
        stack.push(Point{pos.x + 1, pos.y});
        addFlag = true;
    }

    // Define a posição atual como visitada usando mesma flag de movimento invalido
    maze[pos.x][pos.y] = -1;
}

// Imprime o labirinto
void printMaze(int maze[N][N], Point p) {
    cout << "\nMaze: \n";
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == p.x && j == p.y)
                cout << setw(2) << maze[i][j] << "*  ";
            else  
                cout << setw(2) << maze[i][j] << "   ";
        }
        cout << endl;
    }
    cout << "\n";

}

int main(int argc, char **argv) {

    int maze[N][N] = {
        { 0, -1, 0, 0, 0, -1 },
        { 0, 0, -1, 0, -1, 0 },
        { 0, 0, 0, 0, 0, -1  },
        { 0, -1, -1, 0, 0, 0 },
        { -1, 0, 0, 0, -1, -1},
        { 0, 0, -1, 0, 0, 0  }
    };

    Queue queue;
    Stack stack;
    Point start = { 0, 0 }, end = { N-1, N-1 };
    bool addedToStack, debug;

    cout << "Mostar passos de exploracao? (0:nao, 1:sim): ";
    cin >> debug;

    checkAllowedMoves(maze, start, stack, addedToStack);

    queue.push(start);

    if(debug) {
        cout << "\nExplored: (" << start.x << ", " << start.y << ")";
        printMaze(maze, start);
        cout << "Pilha: " << stack;  
        cout << "Fila: " << queue; 
    }

    while(!queue.empty()) {
        
        Point nextPoint = stack.getTop();

        if(nextPoint.x == end.x && nextPoint.y == end.y)
            break;

        addedToStack = false;
        checkAllowedMoves(maze, nextPoint, stack, addedToStack);

        if(addedToStack) 
            queue.push(nextPoint);

        if(debug) {
            cout << "\nExplored: (" << nextPoint.x << ", " << nextPoint.y << ")";
            printMaze(maze, nextPoint);
            cout << "Pilha: " << stack;  
            cout << "Fila: " << queue; 
        }
        
    }
    queue.push(end);

    cout << "\nSolucao: ";
    for(Node *it = queue.getHead()->next; it != NULL; it = it->next) {
        cout << "(" << it->p.x << ", " << it->p.y << ")";
        
        if(it->next != NULL) 
            cout << " -> ";
        else
            cout << " \n\n";
    }

    return 0;
}