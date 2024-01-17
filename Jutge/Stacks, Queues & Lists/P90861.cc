#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){

	int n;
	cin >> n;
	cin.ignore();
	vector<queue<string>> q(n);	
	queue<string> sortides;
	for(int i = 0; i < n; ++i){
		string line;
        getline(cin, line);
        istringstream stream(line);
		string s;
		while(stream >> s)	q[i].push(s);
	}
	
    cin.ignore();
    
	string command;
	while(cin >> command){
	if(command == "SURT") {
		int z;
		cin >> z;
		if ((z > 0 and z <= n) and !q[z-1].empty()){sortides.push(q[z-1].front());
		q[z-1].pop();
	}
	}else if(command == "ENTRA") {
		int z;
		string elnuevo;
		cin >> elnuevo >> z;
		if (z > 0 and z <= n)  q[z-1].push(elnuevo);	
	
	}else{}
	}
	cout << "SORTIDES" << endl << "--------" << endl;
	while(!sortides.empty()){
		cout << sortides.front()<< endl;
		sortides.pop();
		
	}
	cout << endl;
	cout << "CONTINGUTS FINALS" << endl << "-----------------" << endl;
	for(int i = 0; i < n; ++i){
		cout << "cua " << i +1<< ":";
		while(!q[i].empty()){
		cout << " "<<q[i].front();
		q[i].pop();
		
		}
		cout << endl;
}
}
