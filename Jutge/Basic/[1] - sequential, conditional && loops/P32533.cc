#include <iostream>
using namespace std;

void barras(int suma, int multis) {

		for (int i = 1; i < suma; ++i)cout << "+";
		if (suma == suma) cout << "/";
		for (int i = 1; i < multis; ++i) cout << "*";
		cout << endl; 

}

int main (){

	int x;
	cin >> x;
	int suma, multis;
	for (suma = x, multis = 1; suma > 0; --suma, multis += 1) 	
		barras (suma, multis);	
	
	
	
}

