#include <iostream>

using namespace std;

int main()
{
	
	int i, x = 1 ;
	
	while(cin >> i){
		
		if(i % 2 != 0)
		
		++x;
		
		else 
		
		break;
	}

	cout << x << endl;
}

