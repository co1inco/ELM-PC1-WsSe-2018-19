#include <iostream>

using namespace std;

enum arbeitstag {
	montag,
	dienstag,
	mittwoch,
	donnerstag,
	freitag
};

int arbeitstag[5] = {7, 9, 0, 4, 5};

int arbeitszeitausgabe(enum arbeitstag as){
	return arbeitstag[as];
}

int main(){
	std::cout << "Donnerstag: " << arbeitstag[donnerstag] << endl;
	std::cout << arbeitszeitausgabe(dienstag);
}




