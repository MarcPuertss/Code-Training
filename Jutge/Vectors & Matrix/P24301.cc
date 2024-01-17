#include <iostream>
#include <vector>

using namespace std;

vector<int> concatenation(const vector<int>& v1, const vector<int>& v2){

	vector <int> c(v1.size() + v2.size());
	
	for(int i = 0; i < v1.size(); ++i) c[i] = v1[i];
	for(int i = 0; i < v2.size(); ++i) c[i+ v1.size()] = v2[i];

	return c;

}
