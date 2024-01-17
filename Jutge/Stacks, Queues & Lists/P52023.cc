#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int evaluate(string line){

	istringstream mycin(line);
	string elem;
	stack<int> s;
	while(mycin >> elem){
		if(elem == "+" or elem == "-" or elem == "*"){
		int x2 = s.top();
		s.pop();
		int x1 = s.top();
		s.pop();
		
		if(elem == "+") s.push(x1 + x2);
		if(elem == "-") s.push(x1 - x2);
		if(elem == "*") s.push(x1 * x2);
		}
		else {
		s.push(atoi(elem.c_str()));
		}
		}
	
	return s.top();
}

int main(){

string line;
	while(getline(cin, line)){
	cout <<evaluate(line) << endl;
	}
}
