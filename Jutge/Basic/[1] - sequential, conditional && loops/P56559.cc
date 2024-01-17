#include <iostream>

using namespace std;

int main(){

	int x, y, a, b;
	
	cin >> x >> y >> a >> b;
	
	if (x <= y and a <= b and a < y and b < y and x < a and x < b){
	
		cout << "2" <<endl;
	}
	else if (x <= y and a <= b and a <= y and b <= y and x < a and x < b){
	
		cout << "2" <<endl;
	}
	else if (x <= y and a <= b and a < y and b < y and x <= a and x <= b){
	
		cout << "2" <<endl;
	}
	
	else if (x <= y and a <= b and a < y and y <= b and a < x and x <= b){
	
		cout << "1" <<endl;
	}
	else if (x <= y and a <= b and a > y and b <= y and x < a and x <= b){
	
		cout << "1" <<endl;
	}
	else if (x <= y and a <= b and a <= y and b > y and x >= a and x < b){
	
		cout << "1" <<endl;
	}
	
	else if (x <= y and a <= b and x == a and y == b){
	
		cout << "=" <<endl;
	
	}else{
	
		cout << "?" << endl;
	
	}
	
return 0;	
	
}
