#include <iostream>

using namespace std;

	
 int double_factorial(int n){
 
 	int f = n-2;
	if( f <= 0 and n <= 0 ) {
		return 1;

}
	else return n*double_factorial(f);
 
 
 
}

int main (){

	int x;
	cin >> x;
	cout << double_factorial(x) << endl;

}
