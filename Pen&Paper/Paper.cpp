#include <iostream>
#include "Paper.h"

using namespace std;

Paper::Paper(int maxSymbols): maxSymbols(maxSymbols), symbols(0), content(""){

}

Paper::~Paper(){

}

int Paper::getMaxSymbols() const{
    return this->maxSymbols;
}

int Paper::getSymbols() const{
    return this->symbols;
}

void Paper::addContent(const string& message){
    int total = content.length() + message.length();

    if ( total > maxSymbols ) {
        content += message.substr(0, maxSymbols);
        symbols = maxSymbols;
        throw OutOfSpaceException();
    }
    content += message;
    symbols = total;
}

void Paper::show() const{
    cout << content << endl;
}