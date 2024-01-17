#include <iostream>
#include <vector>
#include <string>

using namespace std;
void escinvers(int n){
	
	if(n == 0) return;
	string s;
	if(not (cin >> s)) return;
	escinvers(n-1);
	cout << s << endl;

}
int main(){
	int n;
	cin >> n;
	escinvers(n);

}
