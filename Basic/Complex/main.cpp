#include <iostream>
#include "Complex.h"

using namespace std;

int main() {
    int x, y;
    Complex result;
    
    cout << "real:      ";
    cin >> x >> y;
    Complex real(x, y);
    cout << "imaginary: ";
    cin >> x >> y;
    Complex imaginary(x, y);

    result = real+imaginary;
    cout << "summary: " << result << endl;

    result = real-imaginary;
    cout << "difference: " << result << endl;

    // result = real * imaginary;
    // cout << "Multiple: " << result << endl;

    // real += real;

    cout << real << endl;

    return 0;
}