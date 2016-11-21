#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    List<float>* array = new List<float>;
    float count,value;
    int index;

    cout << "Set size of array: ";
    cin >> count;

    cout << "Added " << count << " elems: " << endl;
    for ( int i = 0; i < count; i++ ) {
        array->push_back(1.3*i);
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
    cin >> value;
    cout << "Index of element " << value << " is: " << array->find(value) << endl;

    array->sort();
    cout << "Array sorted: " << endl;
    cout << *array << endl;

    return 0;
}
