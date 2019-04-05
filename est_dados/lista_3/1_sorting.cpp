/*
    Compilar com C++11 e.g. g++ --std=c++11 1_sorting.cpp -o exe.out
*/

#include <iostream>
#include <limits>
#define LENGHT 10
using namespace std;

void printArray(int *arr, int len) {
    cout << "[ ";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << "]\n";
}

// O(n^2)
void insertionSort(int *arr, int len) {
    int i = 1;

    do {
        int x = arr[i], j = i - 1;

        while ((j >= 0) && (x < arr[j])) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = x;
        i++;

    } while (i < len);
}

// O(n^2)
void selectionSort(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        int min = i;

        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[min]) min = j;
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

// O(n^2)
void bubbleSort(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void merge(int *arr, int first, int middle, int last) {
    int n1 = middle - first + 1;
    int n2 = last - middle;

    int leftHalf[n1], rightHalf[n2];
    for (int i = 0; i < n1; i++) leftHalf[i] = arr[first + i];
    for (int j = 0; j < n2; j++) rightHalf[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = first;
    while (i < n1 && j < n2) {
        if (leftHalf[i] <= rightHalf[j]) {
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
void mergeSort(int *arr, int first, int last) {
    if (first < last) {
        int middle = first + (last - first) / 2;

        mergeSort(arr, first, middle);
        mergeSort(arr, middle + 1, last);

        merge(arr, first, middle, last);
    }
}

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int first, int last) {
    int pivot = arr[last], i = (first - 1);

    for (int j = first; j <= last - 1; j++) {
        
        if (arr[j] <= pivot) {
            i++;  
            troca(&arr[i], &arr[j]);
        }
    }
    troca(&arr[i + 1], &arr[last]);
    return (i + 1);
}

void quickSort(int arr[], int first, int last) {
    if (first < last) {
        int pivot = partition(arr, first, last);

        quickSort(arr, first, pivot - 1);
        quickSort(arr, pivot + 1, last);
    }
}

int main(int argc, char **argv) {
    int arr[LENGHT] = {42, 17, 7, 10, 50, 20, 15, 9, 0, 13};

    cout << "\n_________Insertion Sort_________\n\n";
    int insertion_arr[LENGHT];
    copy(begin(arr), end(arr), begin(insertion_arr));

    cout << "Unordered Array: ";
    printArray(insertion_arr, LENGHT);

    insertionSort(insertion_arr, LENGHT);

    cout << "Ordered Array: ";
    printArray(insertion_arr, LENGHT);

    cout << "\n\n_________Selection Sort_________\n\n";
    int selection_arr[LENGHT];
    copy(begin(arr), end(arr), begin(selection_arr));

    cout << "Unordered Array: ";
    printArray(selection_arr, LENGHT);

    selectionSort(selection_arr, LENGHT);

    cout << "Ordered Array: ";
    printArray(selection_arr, LENGHT);

    cout << "\n\n_________Bubble Sort_________\n\n";
    int bubble_arr[LENGHT];
    copy(begin(arr), end(arr), begin(bubble_arr));

    cout << "Unordered Array: ";
    printArray(bubble_arr, LENGHT);

    bubbleSort(bubble_arr, LENGHT);
    cout << "Ordered Array: ";
    printArray(bubble_arr, LENGHT);
    
    cout << "\n\n_________Merge Sort_________\n\n";
    int merge_arr[LENGHT];
    copy(begin(arr), end(arr), begin(merge_arr));

    cout << "Unordered Array: ";
    printArray(merge_arr, LENGHT);

    mergeSort(merge_arr, 0, LENGHT - 1);
    cout << "Ordered Array: ";
    printArray(merge_arr, LENGHT);

    cout << "\n\n_________Quick Sort_________\n\n";
    int quick_arr[LENGHT];
    copy(begin(arr), end(arr), begin(quick_arr));

    cout << "Unordered Array: ";
    printArray(quick_arr, LENGHT);

    quickSort(quick_arr, 0, LENGHT - 1);
    cout << "Ordered Array: ";
    printArray(quick_arr, LENGHT);

    return 0;
}