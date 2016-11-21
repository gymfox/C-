#include <iostream>
#include <cstdlib>
#include "Factorial.h"

#define FIRST_VALUE 1

using namespace std;

Factorial::Factorial(int value) {
    if ( value < 0 ) {
        throw InvalidValueException();
    }
    this->value = value;
    this->currentIndex = 1;

    array = (int*)malloc(value*sizeof(int));
    if ( array == NULL ) {
        throw OutOfMemoryException();
    }
    array[0] = FIRST_VALUE;
}

Factorial::~Factorial() {
}

void Factorial::ensureIsNotOver() {
    if ( over() ) {
        throw OutOfBoundException();
    }
}

void Factorial::next() {
    ensureIsNotOver();

    currentIndex += 1;
}

bool Factorial::over() {
    return currentIndex > value;
}

void Factorial::reset() {
    currentIndex = 1;
}

int Factorial::getIndex() {
    return currentIndex;
}

int Factorial::getValue() {
    return array[currentIndex] = array[currentIndex - 1] * currentIndex;
}

int Factorial::getValueAtIndex(int index) {
    if ( index < 1 /*|| index > value */) {
        throw InvalidIndexException();
    }

    for ( int i = FIRST_VALUE; i <= index; i++ ) {
        array[i] = array[i - 1] * i;

        if ( i == index ) {
            return array[i];
        }
    }
}

void Factorial::operator++() {
    next();
}

void Factorial::operator++(int) {
    operator++();
}

int Factorial::operator*() {
    return getValue();
}