#include <iostream>
using namespace std;

struct Employee {
    char nome[50];
    float salario;
};

bool biggerSalary(Employee *a, Employee *b) {
    if(a->salario > b->salario) 
        return true;
    else 
        return false;
}

bool smallerSalary(Employee *a, Employee *b) {
    if(a->salario < b->salario)
        return true;
    else 
        return false;
}

bool alfabeticalOrder(Employee *a, Employee *b) {
    if(a->nome[0] < b->nome[0])
        return true;
    else 
        return false;
}

void insertionSort(struct Employee *arr, bool (*compare)(Employee*, Employee*)) {

    int i = 1;

    do {
        Employee x = arr[i];
        int j = i-1;

        while((j >= 0) && compare(&x, &arr[j])){
            arr[j+1] = arr[j];
            j--;   
        }

        arr[j+1] = x;
        i++;
        
    } while (i < 5);
}

void ordemCrescenteSalario(struct Employee *arr) {
    
    insertionSort(arr, smallerSalary);
    
    for(int i = 0; i < 5; i++) {
        cout << "\n\t" << arr[i].nome << "  " << arr[i].salario << endl;
    }
}

void ordemDecrescenteSalario(struct Employee *arr) {
    
    insertionSort(arr, biggerSalary);
    
    for(int i = 0; i < 5; i++) {
        cout << "\n\t" << arr[i].nome << "  " << arr[i].salario << endl;
    }
}

void ordemAlfabetica(struct Employee *arr) {
    
    insertionSort(arr, alfabeticalOrder);
    
    for(int i = 0; i < 5; i++) {
        cout << "\n\t" << arr[i].nome << "  " << arr[i].salario << endl;
    }
}

int main(int argc, char **argv) {

    struct Employee employees[5] = {
        {"Richard", 3200.57},
        {"William", 1500.45},
        {"Nelson", 2500.56},
        {"Philipe", 5000.23},
        {"Andreas", 1234.56}
    };

    cout << "\nOrdem crescente de salarios: ";
    ordemCrescenteSalario(employees);

    cout << "\n\nOdem decrescente de salarios: ";
    ordemDecrescenteSalario(employees);

    cout << "\n\nOrdem alfabetica: ";
    ordemAlfabetica(employees);

    return 0;
}