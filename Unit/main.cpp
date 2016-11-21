#include <iostream>
#include "Unit.h"

using namespace std;

int main() {
	Unit knight("Knight", 30, 10);
	Unit barbarian("Barbarian", 50, 10);

	cout << knight << endl;
	cout << barbarian << endl;

	cout << "\t\t\tFIGHT" << endl;
	cout << endl;

	for ( int i = 0; i < 5; i++ ) {
		knight.attack(barbarian);
		// barbarian.attack(knight);
		cout << "\tBarbarian: " << barbarian.getHitPoints() << endl;
		cout << "\tKnight: " << knight.getHitPoints() << endl;
		cout << "***" << endl;
	}

	cout << knight << endl;
	cout << barbarian << endl;

	return 0;
}
