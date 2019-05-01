#include <iostream>
#include "Queue.hpp"
using namespace std;

int main(int argc, char **argv) {

    Queue queue;

    for(int i = 0; i < 5; i++) {
        queue.push(2*i);
    } 

    cout << "\nQueue inicial: " << queue << endl;

    cout << "\nEnfileirar 666.";
    queue.push(666);
    cout << "\nQueue apos adicao: " << queue << endl;

    cout << "\nRemover o primeiro." ;
    queue.pop();
    cout << "\nQueue apos remocao: " << queue << "\n\n";

    return 0;    
}