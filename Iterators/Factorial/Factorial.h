#ifndef FACTORIAL_H
#define FACTORIAL_H

#include <iostream>

class InvalidValueException {};
class InvalidIndexException {};
class OutOfMemoryException {};
class OutOfBoundException {};

class Factorial {
    private:
        int value;
        int currentIndex;
        int* array; 
        void ensureIsNotOver();

    public:
        Factorial(int value);
        ~Factorial();

        void next();
        bool over();

        void reset();

        int getIndex();
        int getValue();
        int getValueAtIndex(int index);

        void operator++();
        void operator++(int);

        int operator*();

};

#endif //FACTORIAL_H