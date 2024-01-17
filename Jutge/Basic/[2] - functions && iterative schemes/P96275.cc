#include <iostream>    
using namespace std;

//Valor absolut d'un nombre.
//Entrada x un nombre enter
//Sortida valor absolut d'x

int absolute (int a){

	if(a < 0)
		a = a*-1;
	
	return a;
}



int main ()
{
	int x;
	cin >> x;
	cout<< absolute (x) << endl;
}

