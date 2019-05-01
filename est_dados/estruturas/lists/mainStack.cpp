#include <iostream>
#include "Stack.hpp"
using namespace std;

int main(int argc, char **argv) {

    Stack stack;

    for(int i = 0; i < 5; i++) {
        stack.push(2*i);
    }    

    cout << "\nStack inicial: " << stack << endl;

    cout << "\nEmpilhar 666.";
    stack.push(666);
    cout << "\nStack apos adicao: " << stack << endl;

    cout << "\nRemover o topo." ;
    stack.pop();
    cout << "\nStack apos remocao: " << stack << "\n\n";

    return 0;
}