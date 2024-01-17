#include <iostream>
#include <string>

using namespace std;

bool wellBracketed(const string &s, int &i){

	if(i == int(s.size())) return true;
	if(s[i] == ')') return true;
	if(s[i] == '('){
	 ++i;
	if(not wellBracketed(s, i)) return false;
	if(i>= int(s.size())) return false;
	if(s[i] != ')') return false;
	++i;
	if(not wellBracketed(s, i)) return false;
	}
	return true;
}

// Pre: s està format per parèntesis d'obrir i tancar (,).
// Post: Retorna cert si i només si s representa una seqüència ben parentitzada.
bool wellBracketed(string s){

	int i = 0;
	if(not wellBracketed(s, i)) return false;
	if(i < int(s.size())) return false;
	return true;
}
int main(){

	string x;
	cin >> x;
	cout << wellBracketed(x) << endl;

}
