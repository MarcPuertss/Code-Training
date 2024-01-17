#include <iostream>
using namespace std;

int main(){

int x;
cin >> x;

	for(int i = 0; i < x; ++i){
		if(i%2 == 0){
			for(int j = 0; j < x; ++j){
				if(j%2 == 0) cout << ".";
				else cout << "*";
			
			}
			cout << endl;
		}
		if(i%2 == 1){
			for(int j = 0; j < x; ++j){
				if(j%2 == 1) cout << ".";
				else cout << "*";
			}
			cout << endl;
		}
	}
}

