#include <iostream>

#include "List.h"

using namespace std;

List::List(int capacity, double multiplier) : capacity(capacity), current(0), multiplier(multiplier){
    array = (int*) malloc(capacity * sizeof(int));

    if ( array == NULL ){
        throw OutOfMemoryException();
    }
}

List::~List(){
    free(array);
}

int List::size() const{
    return current;
}

int List::max_size() const{
    return capacity;
}

void List::erase(int index){
    if ( current == 0 ) {
        throw ZeroLenException();
    }

    if ( current > index && index > 0 ) {
        current -= 1;

        for ( int i = index; i < current; i++ ) {
            array[i] = array[i + 1];
        }
    }
}

void List::insert(int value, int index){     //вставить 
    if ( current >= index && index >= 0 ) {
        push_back(value);

        for ( int i = current; i > index; i-- ) {
            array[i] = array[i - 1];
        }
        array[index] = value;
    }
}

int List::find(int value) const{             //найти элемент
    for ( int i = 0; i < current; i++ ){
        if ( array[i] == value ){
            return i;
        }
    }
    return -1;
}

//Добавление элементов в массив:
void List::push_back(int value){
    int newCurrent = current + 1;

    if ( newCurrent > capacity ){
        int newCapacity = capacity * multiplier;
        int* newArray = (int*)realloc(array, newCapacity*sizeof(int));

        if ( newArray == NULL ){
            throw OutOfMemoryException();
        }

        capacity = newCapacity;
        array = newArray;
    }
    array[current] = value;
    current = newCurrent;
}
//удаление элементов из конца массива:
int List::pop_back(){
    if ( current == 0 ){
        throw ZeroLenException();
    }
    current -= 1;

    return array[current];
}

void List::sort(){
    int last = this->current - 1;
    
    for ( int i = 0; i < last; i++ ) {
        for ( int j = i; j < current; j++ ) {
            if ( array[j] < array[i] ) {
                int temp = array[i];
                
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int List::operator[](int index) const{
    return array[index];
}

std::ostream& operator<<(std::ostream& out, const List& list){
    int last = list.size() - 1;

    for ( int i = 0; i < last; i++ ){
        out << list[i] << ' ';
    }
    out << list[last];
    
    return out;
}

bool List::operator==(const List& other) const {
    return current == other.current;
}

bool List::operator!=(const List& other) const {
    return current != other.current;
}