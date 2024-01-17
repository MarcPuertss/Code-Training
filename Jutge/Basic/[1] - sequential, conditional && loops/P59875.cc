#include <iostream>

using namespace std;

int main(){

	int x, z;
	
	cin >> x >> z;
	
	
	while(x > z){
	
	cout << x << endl;
	
	--x;
	}
	while(z > x){
	
	cout << z << endl;
	
	--z;
	}
	if(z == x){
	
	cout << z <<endl;
	
	
	}
}



