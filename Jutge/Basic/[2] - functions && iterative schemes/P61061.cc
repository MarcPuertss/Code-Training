#include <iostream>    
using namespace std;

int productDigits(int n)
{	
	if( n == 0 ) return 0;
	int p = 1;
	while (n > 0) {
		p *= n%10;
		n /= 10; 
	}
	return p;
}

void escriu(int n,int p) {
	cout << "The product of the digits of " << n << " is " << p << "." << endl;
}

int main()
{
	int n;
	while (cin >> n) {
		int p= productDigits(n);
		while (p >= 10) {
			escriu(n, p);
			n = p;
			p = productDigits(n);
		} 
		escriu (n, p);
		cout << "----------" << endl;
	}
}

