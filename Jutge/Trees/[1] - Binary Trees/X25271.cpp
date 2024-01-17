#include "arbreBin.hpp"
#include <iostream>
using namespace std;

bool compleix_suma_fills(const arbreBin<int> &a){

	if(a.es_buit()) return true;
	if(a.fe().es_buit() and a.fd().es_buit()) return true; 
	if((!compleix_suma_fills(a.fe())) or (!compleix_suma_fills(a.fd()))) return false;
	int sum = 0;
	if(!a.fe().es_buit()) sum += a.fe().arrel();
	if(!a.fd().es_buit()) sum += a.fd().arrel();
	if(a.arrel() == sum) return true;
	return false;

}

int main(){

	arbreBin<int> ar;
	cin >> ar;
	cout << ar <<endl;
	if(compleix_suma_fills(ar) == true){
		cout << "L'arbre compleix la propietat 'Suma dels fills'."<< endl;
	}
	else{
		cout << "L'arbre no compleix la propietat 'Suma dels fills'."<< endl;
	}



}
