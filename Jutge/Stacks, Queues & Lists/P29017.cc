#include <iostream>
#include <stack>

using namespace std;

void escriu_de_cim_a_base(stack<int>& s){

	bool space = false;
	while(not s.empty()){
		if(space) cout << " ";
		space = true;
		cout<< s.top();
		s.pop();
	}
	cout<< endl;
} 
stack<int> reverse(stack<int> &s){
	stack<int> r;
	while(not s.empty()){
	  r.push(s.top());
	  s.pop();
	}
return r;
}
void escriu_de_base_a_cim(stack<int>& s){
	s =reverse(s);
    escriu_de_cim_a_base(s);
}
int main(){

	stack<int> s;
	int x;
	while(cin >> x)s.push(x);
	stack<int> s1,s2;
	s1 = s2 = s;
	escriu_de_base_a_cim(s1);
	escriu_de_cim_a_base(s2);

}
