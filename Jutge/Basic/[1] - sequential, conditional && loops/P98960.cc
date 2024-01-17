#include <iostream>
using namespace std;

int main()
{
	char c;
	cin >> c;
	if ('a' <= c and c <= 'z') {
		cout << char(c - 'a' + 'A') << endl;
	} else {
		cout << char(c - 'A' + 'a') << endl;
	}
}

