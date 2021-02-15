#include <iostream>
#include <string>

using namespace std;

class SpaceShip {
public:
	int fuelLeft, fuelMax;
	string name;
	void printStatus() {
		cout << fuelLeft << " fuel left from " << fuelMax << " at the ship " << name << endl;
	}
	void prepare() {
		cin >> name >> fuelLeft >> fuelMax;
	}
	void flight(int distance) {
		fuelLeft -= distance;
		if (fuelLeft < 0) fuelLeft = 0;
	}
};

class SpaceStation {
public:
	string name;
	int dist;
	void prepare() {
		cin >> name >> dist;
	}
	void printStatus() {
		cout << "Space station " << name << " is ready for work" << endl;
	}
	void fillupShip(SpaceShip &sp) {
		int was = sp.fuelLeft;
		sp.fuelLeft = sp.fuelMax;
		cout << "Ship " << sp.name << " filled " << sp.fuelMax - was << " tn fuel on station " << name << endl;
	}
};

int main() {
	SpaceStation station;
	SpaceShip ship;
	station.prepare();
	ship.prepare();
	ship.flight(station.dist);
	station.fillupShip(ship);
	ship.printStatus();
	return 0;
}
