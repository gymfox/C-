#include <iostream>

#include "Gun.h"

using namespace std;

Gun::Gun(const string& model, int capacity) {
    this->amount = 0;
    this->capacity = capacity;
    this->isReady = false;
    this->model = model;
    this->totalShots = 0;
}

Gun::~Gun(){}

int Gun::getAmount() const {
    return this->amount;    //получает количество "патронов" 
}

int Gun::getCapacity() const{
    return this->capacity;  //получает объем обоймы
}

bool Gun::ready() const{
    if ( amount == 0 ) {
        return !(isReady);
    } 
    return isReady;
}

const string& Gun::getModel() const{
    return this->model;     //Получает название модели
}

int Gun::getTotalShots() const{
    return this->totalShots;//Текущее количество выстрелов
}

void Gun::prepare(){
    isReady = !isReady;
}

void Gun::reload(){
    amount = capacity;
}

void Gun::shoot(){
    if ( amount == 0 ) {
        throw OutOfRounds();
    }
    if ( !ready() ) {
        throw NotReady();
    }
    amount -= 1;
    totalShots += 1;
    cout << "Bang!" << endl;
}

ostream& operator<<(ostream& out, const Gun& gun){
    out << "Gun: " << gun.getModel() << endl;
    out << "capacity: " << gun.getCapacity() << endl;
    out << "preparedness: ";
    if ( gun.ready() ) {
        out << "ready" << endl;
    } else {
        out << "not ready" << endl;
    }
    out << "rounds: (" << gun.getAmount();
    out << "/" << gun.getCapacity() << ")" << endl;
    out << "total: " << gun.getTotalShots() << endl;
    
    return out;
}
