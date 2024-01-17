#include <iostream>
using namespace std;

// x (inicial): 3154
// x: 3154	
// r: 4513

int reverse(int x)
{

		int r = 0;
		while ( x > 0) {
			r =10*r + x%10;
			x /= 10;
			
		}
		return r;
}


bool is_palindromic(int n)
{
	
	return n == reverse(n);
}


int main(){
 	int n;
 		while (cin >> n)
 		 	if (is_palindromic(n))
 		 	
 		 	cout << "yes" << endl;
 		 	
 		 	else 
 		 	
 		 	cout << "no" << endl;

	
		

}
