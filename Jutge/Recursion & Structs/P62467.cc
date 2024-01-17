#include <iostream>
#include <string>

using namespace std;
void barres(int n){

	if(n == 0) return;
	barres(n-1);
	cout << string(n, '*')<< endl;
	barres(n-1);
}
int main(){

	int n;
	cin >> n;
	barres(n);
	
	}
//(-1)^(n+1)*n)
