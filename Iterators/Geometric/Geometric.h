#ifndef GEOMETRIC_H
#define GEOMETRIC_H

#include <iostream>

class InvalidFirstNumberException {};
class InvalidMultiplierException {};
class OutOfBoundException {};
class InvalidIndexException {};

class Geometric {
    private:
        int first;
        int last;
        int mult;
        int currentIndex;
        void ensureIsNotOver();

    public:
        Geometric(int first, int last, int mult);
        ~Geometric();

        void next();
        void prev();
        bool over();

        void resetToFirst();
        void resetToLast();

        int lastMember();
        int sum();

        int getIndex();
        int getValue();
        int getValueAtIndex(int index);

        void operator++();
        void operator++(int);
        void operator--();
        void operator--(int);

        int operator*();
};

#endif //GEOMETRIC_H