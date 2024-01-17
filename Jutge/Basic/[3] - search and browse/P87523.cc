#include <iostream>

using namespace std;

int main(){

	char a;
	bool trobat = false;
	cin >> a;
	while (a != '.' and not trobat){
		if (a == 'h') {
			cin >> a;
			if (a == 'e') {
				cin >> a;
				if (a == 'l') {
					cin >> a;
					if (a == 'l') {
						cin >> a;
						if (a == 'o') {
							cin >> a;
							trobat = true;
						}
					}
				}
			}
		} else {
			cin >> a;
		}
	}	
	if (trobat) {
		cout << "hello" << endl;
	} else {
		cout << "bye" << endl;
	}


}

