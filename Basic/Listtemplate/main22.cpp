#include <iostream>
#include <cstdlib>

using namespace std;

class OutOfMemoryException {};
class ZeroLenException {};

class List {
    private:
        int* array;
        int capacity;
        double multiplier;
        int current;

    public:
        List() : capacity(100), current(0), multiplier(1.05){
            array = (int*) malloc(capacity * sizeof(int));

            if ( array == NULL ){
                throw OutOfMemoryException();
            }
        }

        ~List(){
            free(array);
        }

        int size() const{
            return current;
        }

        int max_size() const{
            return capacity;
        }

        void erase(int index){
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

        void insert(int value, int index){ 
            if ( current >= index && index >= 0 ) {
                push_back(value);

                for ( int i = current; i > index; i-- ) {
                    array[i] = array[i - 1];
                }
                array[index] = value;
            }
        }

        int find(int value) const{
            for ( int i = 0; i < current; i++ ){
                if ( array[i] == value ){
                    return i;
                }
            }
            return -1;
        }

        void push_back(int value){
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

        int pop_back(){
            if ( current == 0 ){
                throw ZeroLenException();
            }
            current -= 1;

            return array[current];
        }

        void sort(){
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

        int operator[](int index) const{
            return array[index];
        }

};

ostream& operator<<(ostream& out, const List& list){
    int last = list.size() - 1;

    for ( int i = 0; i < last; i++ ){
        out << list[i] << " ";
    }
    out << list[last];
    
    return out;
}

int main() {
    List* array = new List;
    int element;
    int index;
    int value;

    cout << "Set size of array: ";
    cin >> element;

    cout << "push_back " << element << " elems: " << endl;
    for ( int i = 0; i < element; i++ ) {
        array->push_back(10*i);
    }
    cout << *array << endl;

    cout << "Enter erase index: ";
    cin >> index;
    cout << "erase "<< index <<" index: " << endl;
    array->erase(index);
    cout << *array << endl;

    cout << "Set value and insert index: ";
    cin >> value >> index;
    array->insert(value, index);
    cout << *array << endl;

    cout << "Find element: ";
    cin >> element;
    cout << "Index of element " << element << " is: " << array->find(element) << endl;

    array->sort();
    cout << "Array sorted: " << endl;
    cout << *array << endl;


    return 0;
}