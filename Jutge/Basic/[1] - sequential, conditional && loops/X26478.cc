#include <iostream>
using namespace std;

int main() {

	double x;
	cin >> x;

	for(int i = x; i > 0; --i){
	
	cout << i << endl;
		if(i % 5 == 0) cout << "Beep" << endl;
	}

}
