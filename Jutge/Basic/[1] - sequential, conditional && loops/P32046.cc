#include <iostream>
using namespace std;

int main(){

int x, resx;
int y, resy;
int cnt = 0;
cin >> x;
resx = x % 1000;
	cout << "nombres que acaben igual que " << x <<":"<< endl;
	while(cin >> y){
	resy = y % 1000;
		if(resy == resx){
			cout << y << endl;
			cnt += 1;
			
		}
	}
	cout << "total: " << cnt << endl;
}
