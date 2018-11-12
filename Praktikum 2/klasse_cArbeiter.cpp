#include <iostream>

using namespace std;

class CAngestellter{
	
	private:
		int alter;
		int dienstzeit;
		int gehalt;
		
	public:
		CAngestellter() :alter(24), dienstzeit(4), gehalt(1500) {};
		CAngestellter(int a, int d, int g) : alter(a), dienstzeit(d), gehalt(g) {};
		
		int getAlter(){
			return alter;
		}
		void setAlter(int a){
			alter = a;
		}
		
		int getDienstzeit(){
			return dienstzeit;
		}
		void setDienstzeit(int d){
			dienstzeit = d;
		}
		
		int getGehalr(){
			return gehalt;
		}
		void setGehalt(int g){
			gehalt = g;
		}
		
		void printInfo(){
			std::cout << "Alter: " << alter << " Jahre" << std::endl;
			std::cout << "Dienszeit: " << dienstzeit << " Jahre" << std::endl;
			std::cout << "Gehalt: " << gehalt << " Euro" << endl;
		}
		
		void printInfo_gehalt(){
			int a, b;
			a = gehalt / 1000;
			b = gehalt - (a*1000);
			std::cout << a << " " << b << " Euro" << std::endl;
		}
};



int main(){
	CAngestellter angestellter1;
	angestellter1.printInfo();
	angestellter1.printInfo_gehalt();
	
	CAngestellter angestellter2(32, 12, 3550);
	angestellter2.printInfo();
	angestellter2.printInfo_gehalt();
	
	
	
	
}


