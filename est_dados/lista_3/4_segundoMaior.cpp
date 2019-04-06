#include <iostream>
#include <limits>
using namespace std;

// O(n)
int findSegundoMaior(int *arr, int n) {
    int first = numeric_limits<int>::min(), second = first;

    for(int i = 0; i < n; i++) {
        if(arr[i] > first) {
            second = first;
            first = arr[i];
        }
    }  

    return second;  
}

int main(int argc, char **argv) {

    int arr[10] = {42, 17, 7, 10, 50, 20, 15, 9, 0, 13};
    
    int num = findSegundoMaior(arr, 10);

    cout << "\nSegundo maior elemento da sequencia e " << num << "\n\n";

    return 0;
}