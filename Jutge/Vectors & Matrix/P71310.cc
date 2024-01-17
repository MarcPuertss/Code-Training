#include <iostream>
#include <vector>

using namespace std;

double scalar_product(const vector<double>& u, const vector<double>& v){
	double res = 0;
	
	for(int i = 0; i < u.size(); i++){
		
		res += u[i]*v[i];
	
	}
	
	return res;
}


