#include <iostream>


using namespace std;
void escinvers(int &n){
	
	string s;
	if(not (cin >> s)) return;
	escinvers(n);
	if(n > 0){
	cout << s << endl;
	--n;
	}
}
int main(){
	int n;
	cin >> n;
	escinvers(n);

}
