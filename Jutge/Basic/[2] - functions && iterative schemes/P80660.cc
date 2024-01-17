#include <iostream>

using namespace std;

//Si n és parell, dividiu-lo per dos. Altrament, multipliqueu-lo per 3 i sumeu-li 1. Quan arribeu a 1, pareu. Per exemple, començant en 3, s’obté la seqüència 
int main(){

	int x;
		
	while(cin >> x){
		int z = 0;
		while(x != 1){
	
	
			if(x % 2 == 0){
		
			x = x/2;
			++z;
			}
			else{
		
			x = (x*3) + 1;
			++z;
			}		
		}
	
		cout << z << endl;
	}
	
}
