#include <iostream>
#define LENGTH 5
using namespace std;

struct Employee {
    char nome[50];
    float salario;
};

// Funções de comparação
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

// Algoritmos de ordenação

// O(n^2)
void insertionSort(Employee *arr, bool (*compare)(Employee*, Employee*)) {

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
        
    } while (i < LENGTH);
}

void merge(Employee *arr, int first, int middle, int last, bool (*compare)(Employee*, Employee*)) {
    int n1 = middle - first + 1;
    int n2 = last - middle;

    Employee leftHalf[n1], rightHalf[n2];
    for (int i = 0; i < n1; i++) leftHalf[i] = arr[first + i];
    for (int j = 0; j < n2; j++) rightHalf[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = first;
    while (i < n1 && j < n2) {
        if (compare(&leftHalf[i], &rightHalf[j])) {
            arr[k] = leftHalf[i];
            i++;
        } else {
            arr[k] = rightHalf[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        arr[k] = leftHalf[i];

        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightHalf[j];

        j++;
        k++;
    }
}

// O(nlog n)
void mergeSort(Employee *arr, int first, int last, bool (*compare)(Employee*, Employee*)) {
    if (first < last) {
        int middle = first + (last - first) / 2;

        mergeSort(arr, first, middle, compare);
        mergeSort(arr, middle + 1, last, compare);

        merge(arr, first, middle, last, compare);
    }
}

void troca(Employee *a, Employee *b) {
    Employee t = *a;
    *a = *b;
    *b = t;
}

int partition(Employee *arr, int first, int last, bool (*compare)(Employee*, Employee*)) {
    Employee pivot = arr[last];
    int i = (first - 1);

    for (int j = first; j <= last - 1; j++) {
        
        if (compare(&arr[j], &pivot)) {
            i++;  
            troca(&arr[i], &arr[j]);
        }
    }
    troca(&arr[i + 1], &arr[last]);

    return (i + 1);
}

void quickSort(Employee *arr, int first, int last, bool (*compare)(Employee*, Employee*)) {
    if (first < last) {
        int pivot = partition(arr, first, last, compare);

        quickSort(arr, first, pivot - 1, compare);
        quickSort(arr, pivot + 1, last, compare);
    }
}


void ordemCrescenteSalario(Employee *arr, char *sortingMethod) {
    
    if(sortingMethod == "insertion")
        insertionSort(arr, smallerSalary);
    else if(sortingMethod == "merge")
        mergeSort(arr, 0, LENGTH - 1, smallerSalary);
    else 
        quickSort(arr, 0, LENGTH - 1, smallerSalary);
    
    for(int i = 0; i < 5; i++) {
        cout << "\n\t" << arr[i].nome << "  " << arr[i].salario << endl;
    }
}

void ordemDecrescenteSalario(Employee *arr, char *sortingMethod) {
    if(sortingMethod == "insertion")
        insertionSort(arr, biggerSalary);
    else if(sortingMethod == "merge")
        mergeSort(arr, 0, LENGTH - 1, biggerSalary);
    else 
        quickSort(arr, 0, LENGTH - 1, biggerSalary);

    for(int i = 0; i < 5; i++) {
        cout << "\n\t" << arr[i].nome << "  " << arr[i].salario << endl;
    }
}

void ordemAlfabetica(Employee *arr, char *sortingMethod) {
    if(sortingMethod == "insertion")
        insertionSort(arr, alfabeticalOrder);
    else if(sortingMethod == "merge")
        mergeSort(arr, 0, LENGTH - 1, alfabeticalOrder);
    else 
        quickSort(arr, 0, LENGTH - 1, alfabeticalOrder);
    
    for(int i = 0; i < 5; i++) {
        cout << "\n\t" << arr[i].nome << "  " << arr[i].salario << endl;
    }
}

int main(int argc, char **argv) {

    Employee employees[LENGTH] = {
        {"Richard", 3200.57},
        {"William", 1500.45},
        {"Nelson", 2500.56},
        {"Philipe", 5000.23},
        {"Andreas", 1234.56}
    };

    char sortingMethod[10];
    cout << "Escolha o metodo de ordenacao(insertion, merge, quick): ";
    cin.getline(sortingMethod, 10);

    cout << "\n\n______________Employees______________\n\n";

    cout << "\nOrdem crescente de salarios: ";
    ordemCrescenteSalario(employees, sortingMethod);

    cout << "\n\nOdem decrescente de salarios: ";
    ordemDecrescenteSalario(employees, sortingMethod);

    cout << "\n\nOrdem alfabetica: ";
    ordemAlfabetica(employees, sortingMethod);
    
    return 0;
}