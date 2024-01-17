#include <iostream>
#include <vector>
using namespace std;

typedef vector < vector <int> > Matrix;

void transpose(Matrix& v)
{
	int n = int (v.size());
	for(int i = 0; i < n; ++i)
		for(int j = i+1; j < n; ++j)
			swap(v[i][j], v[j][i]);
}

int main()   
{
	int n;
	cin >> n;
	Matrix v(n, vector<int> (n));
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
		cin >> v[i][j];
	transpose(v);
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j)
			cout << v[i][j] << " ";
		cout << endl;
}
}
