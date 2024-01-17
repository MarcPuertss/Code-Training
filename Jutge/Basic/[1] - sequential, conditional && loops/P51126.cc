#include <iostream>

using namespace std;

int main(){

	int x, y, a, b;
	
	cin >> x >> y >> a >> b;
	
	if (x <= y and a <= b and a <= y and y <= b and x <= a and x <= b){
	
		cout <<"[" << a << "," << y << "]"<<endl;
	}
	
	else if (x <= y and a <= b and a <= y and y <= b and a <= x and x <= b){
	
		cout <<"[" << x << "," << y << "]"<<endl;
	}
	
	else if (x <= y and a <= b and a <= y and b <= y and a <= x and x <= b){
	
		cout <<"[" << x << "," << b << "]"<<endl;
	}
	
	else if (x <= y and a <= b and a <= y and b <= y and x <= a and x <= b){
	
		cout <<"[" << a << "," << b << "]"<<endl;
	
	}else{
	
		cout << "[" << "]" << endl;
	
	}
	
	
	
}

