#include <iostream>
#include "Factorial.h"

using namespace std;

int main() {
    int index;
    int first;

    cout << "Set first value: ";
    cin >> first;

    Factorial seq(first);

    cout << "Enter Index: ";
    cin >> index;
    cout << "At index: " << index << " is " << seq.getValueAtIndex(index) << endl;

    for ( ; !seq.over(); seq++ ) {
        cout << seq.getIndex() << " - " << *seq << endl;
    }

    // seq.reset();
    // cout << seq.getIndex() << " - " << *seq << endl;

    // seq.next();
    // cout << seq.getIndex() << " - " << *seq << endl;

    
    // cout << *seq << endl;

    cout << "Enter Index: ";
    cin >> index;
    cout << "At index: " << index << " is " << seq.getValueAtIndex(index) << endl;

    return 0;
}