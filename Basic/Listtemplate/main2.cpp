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
        template <typename T>
        List(): capacity(100), current(0), multiplier(1.05){
            array = (T*) malloc(capacity * sizeof(T));

            if ( array == NULL ){
                throw OutOfMemoryException();
            }
        }

        template <typename T>
        ~List(){
            free(array);
        }

        template <typename T>
        int size() const{
            return current;
        }

        template <typename T>
        int max_size() const{
            return capacity;
        }

        template <typename T>
        void push_back(T value){
            int newCurrent = current + 1;

            if ( newCurrent > capacity ){
                int newCapacity = capacity * multiplier;
                T* newArray = (T*)realloc(array, newCapacity * sizeof(T));

                if ( newArray == NULL ){
                    throw OutOfMemoryException();
                }
                capacity = newCapacity;
                array = newArray;
            }
            array[current] = value;
            current = newCurrent;
        }

        template <typename T>
        T operator[](int index) const{
            return array[index];
        }
};

template <typename T>
ostream& List<T>::operator<<(std::ostream& out, const List<T>& list){
    T last = list.size() - 1;

    for ( int i = 0; i < last; i++ ){
        out << list[i] << " ";
    }
    out << list[last];
    
    return out;
}

int main() {
    List<float>* array = new List<float>;
    float element, value;
    int index;
    
    cout << "Set size of array: ";
    cin >> element;
    
    cout << "Added " << element << " elems: " << endl;
    for ( int i = 0; i < element; i++ ) {
        array->push_back(10*i);
    }
    
    cout << *array << endl;
    
    return 0;
}