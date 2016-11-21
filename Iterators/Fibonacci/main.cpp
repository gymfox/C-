#include <iostream>

#include "Fibonacci.h"

using namespace std;

int main() {
    int index;
    int first, last;

    cout << "Set first value: ";
    cin >> first;
    cout << "Set last number of last member: ";
    cin >> last;
    Fibonacci seq(1, last);

    cout << seq.getValueAtIndex(5) << endl;


    for ( ; !seq.over(); seq++ ) {
        cout << seq.getIndex() << " - " << *seq << endl;
    }

    cout << endl;

    return 0;
}