#include <iostream>
#include <vector>
#include <string>

using namespace std;
void escinvers(){
	
	string s;
	if(not (cin >> s)) return;
	escinvers();
	cout << s << endl;

}
int main(){
	escinvers();

}
