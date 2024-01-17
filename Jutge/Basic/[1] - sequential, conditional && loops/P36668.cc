#include <iostream>

using namespace std;

int main(){

	int x, z, c;
	
	cin >> x;
	
	z = 0;
	c = x*x;
	
	while(x > z){
		
		c = c + (x - 1)*(x - 1);
	
		--x;
	}
	
	cout << c << endl;
	
}



