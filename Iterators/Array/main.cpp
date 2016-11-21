#include <iostream>
#include "NaturalIterator.h"

#define SIZE 10

using namespace std;

int main() {
    int array[SIZE] = {101, 202, 303, 404, 505, 606, 707, 808, 909, 1001};
    NaturalIterator seq(array, SIZE);

    for ( ; !seq.over(); seq++ ) {
        cout << seq.value() << endl;
    }

    cout << seq.getValue(4) << endl;

    cout << endl;

    return 0;
}