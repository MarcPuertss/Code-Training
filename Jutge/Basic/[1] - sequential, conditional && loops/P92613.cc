#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){

	double x;
	cin >> x;
	
	cout << fixed << setprecision(0);
	cout << floor( x) << " " << ceil( x) << " " << round( x) << endl;


}
