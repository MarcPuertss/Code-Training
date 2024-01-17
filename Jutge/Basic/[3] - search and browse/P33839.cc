#include <iostream>

using namespace std;


int suma_digits(int n, int s = 0){
 
    while (n>0){
        s = s+ n%10;
        n = n/10;
        }
        return s;
}
int main()
{
    int n,res;

   
   while(cin >> n)
   {
    res = suma_digits(n);
    cout << "La suma dels digits de " << n << " es " << res << "." <<endl;
	}
    return 0;
}

