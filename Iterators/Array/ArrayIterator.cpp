#include <iostream>
#include "ArrayIterator.h"

using namespace std;

ArrayIterator::ArrayIterator(int* array, int size) :array(array), limit(size - 1), current(0) {
    cout << "Creating..." << endl;
}

void ArrayIterator::next() {
    if ( over() ) {
        return;
    }
    current += 1;
}

void ArrayIterator::prev() {
    if ( less() ) {
        return;
    }
    current -= 1;
}

void ArrayIterator::operator++() {
    next();
}

void ArrayIterator::operator++(int) {
    operator++();
}

bool ArrayIterator::over() {
    return current > limit;
}

bool ArrayIterator::less() {
    return current < limit;
}

int ArrayIterator::value() {
    return array[current];
}

int ArrayIterator::getValue(int index) {
    if ( limit < index ) {
        throw OutOfArrayBoundException();
    }
    return array[index];
}

int ArrayIterator::operator*() {
    return array[current];
}
