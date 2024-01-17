#include <iostream>
using namespace std;

void writeSequence (int spaces, int asteriscs) {

		for (int i = 0; i < spaces; ++i) cout << " ";
		for (int i = 0; i < asteriscs; ++i) cout << "*";
		cout << endl; 

}



int main (){

	int x;
	cin >> x;
	int spaces, asteriscs;
	for (spaces = x-1, asteriscs = 1; spaces > 0; --spaces, asteriscs += 2) 	
		writeSequence (spaces, asteriscs);	
	writeSequence (spaces, asteriscs);
	
	for (++spaces, asteriscs -=2; asteriscs >= 1; ++spaces, asteriscs -= 2)
			writeSequence( spaces, asteriscs);
	
}
