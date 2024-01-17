#include <iostream>
using namespace std;

int main(){

    int x, n, y=0, cnt = 0;
	cin >> x;
	while (cin >> n){
	    cnt ++;
		if (n == -1) break; 
		if (cnt == x){
		    y = n;
		}
	}
	cout << "At the position " << x << " there is a(n) " << y << "." << endl;		
	
	
}
	
	
	
	
