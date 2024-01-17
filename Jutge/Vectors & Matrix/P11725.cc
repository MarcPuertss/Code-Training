#include <iostream>
#include <vector>
using namespace std;

bool exists(int x, const vector<int>& v)
{
	for(unsigned int i = 0; i < v.size(); i++){
		if(x == v[i]) return true;
	}	
	return false;
}
