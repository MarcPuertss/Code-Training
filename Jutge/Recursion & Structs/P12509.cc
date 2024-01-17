#include <iostream>

using namespace std;

	
int factorial(int n){

	int f = 1 , i = 0;
		while ( i < n ) {

		i = i + 1 ;
		f = f * i ;
		}
	return f ;
	
}
