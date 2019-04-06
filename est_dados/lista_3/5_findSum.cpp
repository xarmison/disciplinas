#include <iostream>
#include <cstdlib>
using namespace std;

int compare (const void *a, const void *b) {
    return ( *(int*)a - *(int*)b );
}

bool findSum(int *arr, int n, int sum) {

    // Quick Sort -> O(nlog n)
    qsort(arr, n, sizeof(int), compare); 

    int i = 0, j = n - 1;

    // O(n)
    while(i < j) { 
        if(sum == (arr[i] + arr[j]))
            return true;
        else if(sum < (arr[i] + arr[j]))
            j--;
        else 
            i++;
    }

    return false;
}

int main(int argc, char **argv) {

    int arr[10] = {42, 17, 7, 10, 50, 20, 15, 9, 0, 13};

    int sum;
    cout << "Insira a soma a ser buscada: ";
    cin >> sum;

    bool found = findSum(arr, 10, sum);

    const char *str = found ? "possui" : "nao possui";

    cout << "\n\nO array " << str << " a soma " << sum << "\n\n";

    return 0;
}