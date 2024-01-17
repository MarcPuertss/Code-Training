#include <iostream>
#include <vector>
using namespace std;

int main(){
	
	 int x;
	while( cin >> x){
		vector<int> v(x);
		for (int i = 0; i < x; ++i)
			cin >> v[i];
	 	for(int i=x-1; i >= 0; --i){
	 		cout << v[i];
	 	if(i > 0)
	 		cout << " "; 	
	 		
	 	}	
	 	cout << endl;	
	 }	
	
}

