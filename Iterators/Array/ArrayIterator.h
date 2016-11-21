#ifndef ARRAYITERATOR_H
#define ARRAYITERATOR_H

#include <iostream>

class OutOfArrayBoundException{};

template <typename T>
class ArrayIterator {
    private:
        int* array;
        int limit;
        int current;

    public:
    ArrayIterator(int* array, int limit);
    void next();
    void prev();
    void operator++();
    void operator++(int);
    bool over();
    bool less();
    int value();
    int getValue(int index);
    int operator*();
};

#endif //ARRAYITERATOR_H