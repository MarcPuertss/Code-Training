#include <iostream>
#include <vector>
#include <string>

using namespace std; 

typedef vector < vector <int> > Matriu;

 Matriu suma(const Matriu& a, const Matriu& b){
	int x;
	x = a.size();
	Matriu v(x,vector <int> (x));
	
	for(int i = 0; i < x; ++i){
		for(int j = 0; j < x; ++j) {
		
		v[i][j]= a[i][j]+b[i][j];
	}
}
return v;
}
