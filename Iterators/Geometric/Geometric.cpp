#include <iostream>
#include <cmath>
#include "Geometric.h"

using namespace std;

Geometric::Geometric(int first, int last, int mult) {
    if ( first == 0 ) {
        throw InvalidFirstNumberException();
    }
    if ( mult == 0 ) {
        throw InvalidMultiplierException();
    }
    this->first = first;
    this->last = last;
    this->mult = mult;
    this->currentIndex = 1;
}

Geometric::~Geometric() {}

void Geometric::ensureIsNotOver() {
    if ( over() ) {
        throw OutOfBoundException();
    }
}

void Geometric::next() {
    ensureIsNotOver();

    currentIndex += 1;
}

void Geometric::prev() {
    ensureIsNotOver();

    currentIndex -= 1;
}

bool Geometric::over() {
    return currentIndex > last || currentIndex < 1;
}

void Geometric::resetToFirst() {
    currentIndex = 1; 
}

void Geometric::resetToLast() {
    currentIndex = last;
}

int Geometric::lastMember() {
    return first * pow(mult, last-1);
}

int Geometric::sum() {
    return (first - lastMember() * mult) / (1 - mult);
}

int Geometric::getIndex() {
    return currentIndex;
}

int Geometric::getValue() {
    return first * pow(mult, currentIndex - 1);
}

int Geometric::getValueAtIndex(int index) {
    if ( index < 1 || index > last ) {
         throw InvalidIndexException();
    }

    return first * pow(mult, index - 1);
}

void Geometric::operator++() {
    next();
}

void Geometric::operator++(int) {
    operator++();
}

void Geometric::operator--() {
    prev();
}

void Geometric::operator--(int) {
    operator--();
}

int Geometric::operator*() {
    return getValue();
}
