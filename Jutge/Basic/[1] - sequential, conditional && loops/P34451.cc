#include <iostream>
using namespace std;

int main(){

int x, y;
int upc = 0;
cin >> x;
	while(cin >> y){		
	
		if(y % x == 0){
		upc += 1;
		}
	}
	cout << upc << endl;
return 0;
}
