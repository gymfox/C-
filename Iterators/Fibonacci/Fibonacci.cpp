#include <iostream>
#include "Fibonacci.h"

using namespace std;

Fibonacci::Fibonacci(int value, int last) {
    this->value = value;
    this->last = last;
    this->maxSize = abs(value) + abs(last);
    this->currentIndex = 2;

    array = (int*)malloc(maxSize * sizeof(int));

    if ( array == NULL ) {
        throw OutOfMemoryException();
    }
    array[0] = 0;
    array[1] = 1;
}

Fibonacci::~Fibonacci() {}

void Fibonacci::ensureIsNotOver() {
    if ( over() ) {
        throw OutOfBoundException();
    }
}

void Fibonacci::next() {
    ensureIsNotOver();

    currentIndex += 1;
}

void Fibonacci::prev() {
    ensureIsNotOver();

    currentIndex -= 1;
}

bool Fibonacci::over() {
    return currentIndex > last || currentIndex < 1;
}

void Fibonacci::resetToBegin() {
    currentIndex = 0;
}

void Fibonacci::resetToLast() {
    currentIndex = last;
}

int Fibonacci::getIndex() {
    return currentIndex;
}

int Fibonacci::getValue() {
    if ( value < last ) {
        return array[currentIndex] = array[currentIndex - 1] + array[currentIndex - 2];
    }
    if ( value > last ) {
        return array[currentIndex] = array[currentIndex + 2] - array[currentIndex + 1];
    }
}

int Fibonacci::getValueAtIndex(int index) {
    if ( index < 1 || index > last ) {
        throw InvalidIndexException();
    }

    return array[index];
}

void Fibonacci::operator++() {
    next();
}

void Fibonacci::operator++(int) {
    operator++();
}

void Fibonacci::operator--() {
    prev();
}

void Fibonacci::operator--(int) {
    operator--();
}

int Fibonacci::operator*() {
    return getValue();
}