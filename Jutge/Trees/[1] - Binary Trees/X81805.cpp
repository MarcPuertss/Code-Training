#include <iostream>
#include "arbreBin.hpp"
using namespace std;

arbreBin<int> arbresumes(const arbreBin<int> t){
	if(t.es_buit()) return arbreBin<int>();
	
	arbreBin<int> fe = arbresumes(t.fe());
	arbreBin<int> fd = arbresumes(t.fd());

		
	arbreBin<int> af = arbreBin<int>(t.arrel() + (!fe.es_buit() ? fe.arrel() : 0)+ (!fd.es_buit() ? fd.arrel() : 0), fe,fd);
	return af;
}
int main(){

	arbreBin<int> t;
	cin >> t;
	arbreBin<int> tm = arbresumes(t);
	cout << tm << endl;
}
