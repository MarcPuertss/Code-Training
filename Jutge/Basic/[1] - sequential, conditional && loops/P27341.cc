#include <iostream>
using namespace std;

void cubitron(int x, int y){

int padre = 0;
int upc = x;
	while(x <= y){
	padre = x*x*x + padre;
	++x;
	}
	cout << "suma dels cubs entre " << upc << " i " << y << ": " << padre << endl;
}
int main(){

int x, y;
	while(cin >> x >> y){
		
		cubitron(x, y);
	}
}
