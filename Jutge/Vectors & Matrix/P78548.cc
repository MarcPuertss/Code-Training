#include <iostream>
#include <vector>
using namespace std;

int main(){
	
	 string x;
	 while( cin >> x){
	 	for(int i =int(x.size())-1; i >= 0; --i)
	 		cout << x[i];
	 	cout << endl;
	 }	
}
