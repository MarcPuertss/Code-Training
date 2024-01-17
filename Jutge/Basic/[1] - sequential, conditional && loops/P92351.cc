 #include <iostream>
using namespace std;

int main(){
	int a,b;
	
	cin >> a >> b;
	int d = a/b;
	int r = a%b;
	if (r < 0){
		d = d-1;
		int s = d*b;
		r = -s+a;
		}
	cout << d << " " << r << endl;
}
