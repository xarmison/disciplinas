#include <iostream>
#define LENGTH 5
using namespace std;

struct Aluno {
    char nome[50];
    float nota1, nota2;
};

float calcMean(Aluno *a) {
    return ((2*a->nota1)+(3*a->nota2))/5 ;
}

bool compareMean(Aluno *a, Aluno *b) {
    if(calcMean(a) > calcMean(b))
        return true;
    else 
        return false;
}

bool alfabeticalOrder(Aluno *a, Aluno *b) {
    if(a->nome[0] < b->nome[0])
        return true;
    else 
        return false;
}

void insertionSort(struct Aluno *arr, bool (*compare)(Aluno*, Aluno*)) {

    int i = 1;

    do {
        Aluno x = arr[i];
        int j = i-1;

        while((j >= 0) && compare(&x, &arr[j])){
            arr[j+1] = arr[j];
            j--;   
        }

        arr[j+1] = x;
        i++;
        
    } while (i < LENGTH);
}

void oredemCrescenteMedia(Aluno *arr) {
    insertionSort(arr, compareMean);

    for(int i = 0; i < LENGTH; i++) {
        cout << "Aluno: "  << arr[i].nome << ", Media: " << calcMean(&arr[i]) << endl;
    }
}

void aprovados(Aluno *arr) {
    insertionSort(arr, alfabeticalOrder);

    float mean = 0;
    for(int i = 0; i < LENGTH; i++) {
        mean = calcMean(&arr[i]);
        if(mean >= 7)
            cout << "Aluno: " << arr[i].nome << ", Media: " << mean << endl;
    }
}

int main(int argc, char **argv) {

    Aluno alunos[LENGTH] = {
        {"Richard", 8.5, 9.3},
        {"William", 7.5, 6.9},
        {"Stephen",  3.2, 5.8},
        {"Philipe", 1.6, 4.3},
        {"Andreas", 7.2, 6.9}
    };

    cout << "\n__________Ordem Crescente das Medias__________\n";    
    oredemCrescenteMedia(alunos);
    cout << "\n\n";

    cout << "\n__________Alunos Aprovados__________\n";    
    aprovados(alunos);
    cout << "\n\n";

    return 0;
}