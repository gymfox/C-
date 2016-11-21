#include <iostream>
#include <cstdlib>

using namespace std;

class OutOfMemoryException {};
class ZeroLenException {};

template <typename T>
class List {
    private:
        T* array;
        
        int capacity;
        double multiplier;
        int current;
    public:
        List(int capacity=100, double multiplier=1.05);
        ~List();

        int size() const;
        int max_size() const;

        void erase(int index);
        void insert(T value, int index);
        T find(T value) const;
        void push_back(T value);
        T pop_back();
        void sort();

        T operator[](int index) const;
        bool operator==(const List<T>& other) const;
        bool operator!=(const List<T>& other) const;
};

template <typename T>
List<T>::List(int capacity, double multiplier) {
    this->capacity = capacity;
    this->current = 0;
    this->multiplier = multiplier;

    array = (T*) malloc(capacity * sizeof(T));

    if ( array == NULL ) {
        throw OutOfMemoryException();
    }
}


template <typename T>
List<T>::~List() {
    free(array);
}

template <typename T>
int List<T>::size() const {
    return current;
}

template <typename T>
int List<T>::max_size() const {
    return capacity;
}

template <typename T>
void List<T>::erase(int index) {
    if ( current == 0 ) {
        throw ZeroLenException();
    }

    if ( current > index && index > 0 ) {
        current -= 1;

        for ( int i = index, j = index + 1; i < current; i++, j++ ) {
            array[i] = array[j];
        }
    }
}

template <typename T>
void List<T>::insert(T value, int index) {
    if ( current >= index && index >= 0 ) {
        push_back(value);

        for ( int i = current - 1, j = current - 2; i > index; i--, j-- ) {
            array[i] = array[j];
        }
        array[index] = value;
    }
}

template <typename T>
T List<T>::find(T value) const {
    for ( int i = 0; i < current; i++ ) {
        if ( array[i] == value ){
            return i;
        }
    }
    return -1;
}

template <typename T>
void List<T>::push_back(T value) {
    int newCurrent = current + 1;

    if ( newCurrent > capacity ) {
        int newCapacity = capacity * multiplier;
        T* newArray = (T*)realloc(array, newCapacity * sizeof(T));
        if ( newArray == NULL ) {
            throw OutOfMemoryException();
        }

        capacity = newCapacity;
        array = newArray;
    }
    array[current] = value;
    current = newCurrent;
}


template <typename T>
T List<T>::pop_back() {
    if ( current == 0 ) {
        throw ZeroLenException();
    }
    current -= 1;

    return array[current];
}

template <typename T>
void List<T>::sort() {
    int last = this->current - 1;
    
    for ( int i = 0; i < last; i++ ) {
        for ( int j = i; j < current; j++ ) {
            if ( array[j] < array[i] ) {
                T temp = array[i];
                
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

template <typename T>
T List<T>::operator[](int index) const {
    return array[index];
}


template <typename T>
bool List<T>::operator==(const List<T>& other) const {
    if ( current != other.size() ) {
        return false;
    }

    for ( int i = 0; i < current; i++ ) {
        if ( array[i] != other[i] ) {
            return false;
        }
    }

    return true;
}

template <typename T>
bool List<T>::operator!=(const List<T>& other) const {
    return !operator==(other);
}

template <typename T>
ostream& operator<<(std::ostream& out, const List<T>& list) {
    T last = list.size() - 1;

    for ( int i = 0; i < last; i++ ) {
        out << list[i] << " ";
    }
    out << list[last];
    
    return out;
}

int main() {
    List<int>* array1 = new List<int>;
    List<int>* array2 = new List<int>;
    int count,value;
    int index;

    cout << "Set size of array: ";
    cin >> count;

    cout << "Added " << count << " elems: " << endl;
    for ( int i = 0; i < count; i++ ) {
        array1->push_back(10*i);
        array2->push_back(12*i);
    }
    cout << *array1 << endl;
    cout << *array2 << endl;

    // cout << "Enter erase index of array1: ";
    // cin >> index;
    // cout << "erase "<< index <<" index: " << endl;
    // array1->erase(index);
    // cout << *array1 << endl;

    // cout << "Enter erase index of array2: ";
    // cin >> index;
    // cout << "erase "<< index <<" index: " << endl;
    // array2->erase(index);
    // cout << *array2 << endl;

    // cout << "Set value and insert index of array1: ";
    // cin >> value >> index;
    // array1->insert(value, index);
    // cout << *array1 << endl;

    // cout << "Set value and insert index of array2: ";
    // cin >> value >> index;
    // array2->insert(value, index);
    // cout << *array2 << endl;

    // cout << "Find element of array1: ";
    // cin >> value;
    // cout << "Index of element " << value << " is: " << array1->find(value) << endl;

    // cout << "Find element of array2: ";
    // cin >> value;
    // cout << "Index of element " << value << " is: " << array2->find(value) << endl;

    // array1->sort();
    // cout << "Array sorted: " << endl;
    // cout << *array1 << endl;

    // array2->sort();
    // cout << "Array sorted: " << endl;
    // cout << *array2 << endl;

    // cout << (*array1 == *array2) << endl;
    // cout << (*array1 != *array2) << endl;

    return 0;
}
