#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <iostream>
#include <cstdlib>
#include <algorithm>

class InvalidValueException {};
class InvalidIndexException {};
class OutOfMemoryException {};
class OutOfBoundException {};

class Fibonacci {
    private:
        int* array;
        int maxSize;
        int value;
        int currentIndex;
        int last;
        void ensureIsNotOver();

    public:
        Fibonacci(int value, int last);
        ~Fibonacci();

        bool over();
        void next();
        void prev();

        void resetToBegin();
        void resetToLast();

        int getIndex();
        int getValue();
        int getValueAtIndex(int index);

        void operator++();
        void operator++(int);
        void operator--();
        void operator--(int);

        int operator*();

};

#endif //FIBONACCI_H