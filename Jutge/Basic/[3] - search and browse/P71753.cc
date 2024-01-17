#include <iostream>
using namespace std;

int main()
{
	int x;
	while ( cin >> x) {
		int z, max;
		cin >> z;
		max = z;
		for (int i = 0; i < x-1; ++i) {
			cin >> z;
			if ( z > max ) {
				max = z;
			}
		}
		cout << max << endl;
	}			
			
			
}
