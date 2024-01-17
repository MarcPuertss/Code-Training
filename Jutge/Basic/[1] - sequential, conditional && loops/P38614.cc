#include <iostream>
using namespace std;

int main(){

int x;
int padre = 0;
cin >> x;
	int upc = x;
	int e = x%10;
	while (x > 0){
		
		padre += e;									
		x =x / 100;
		e = x % 10;
		
	}
	if(padre%2 == 0 ) cout << upc << " ES TXATXI" << endl;
	else cout << upc << " NO ES TXATXI" << endl;
}
