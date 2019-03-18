#include <iostream>
#include <iomanip> 
using namespace std;

int main(int argc, char **argv) {

    int numDays, startDay;
    cout << "Insira a quantidade de dias do mes e a dia da semana de inicio: ";
    cin >> numDays >> startDay;

    numDays = numDays + startDay;
    
    int month[numDays], day = 1;
    for(int i = 0; i < numDays; i++) {
        if(i < startDay) {
            month[i] = 0;
            continue;
        }
        month[i] = day;
        day++;
    }

    cout << "\n________Month________\n\n";

    for(int i = 0; i < numDays; i++) {
        if(month[i] == 0) {
            cout << setw(2) << "  ";
            continue;
        }
        cout << setw(2) << month[i] << " ";

        if(i%7 == 0) 
            cout << endl;
    }
    cout << "\n\n";

    return 0;
}