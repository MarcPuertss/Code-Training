#include <iostream>
#include <stack>

using namespace std;

void out(stack<int> &s) {

    if (!s.empty()) {
        int x = s.top();
        s.pop();
        bool b = false;
        if(x == 0 and(s.size()+1) % 2 == 1)  b = true;
        if(x == 1 and (s.size()+1) % 2 == 0) b = true;
        out(s);
        if (!b) s.push(x);
    }
}


stack<int> remove01(stack<int> s) {
    out(s);
    return s;
}
int main(){
	int i;
	stack<int> s;
	
	while(cin >> i){
	s.push(i);
	}	
	remove01(s);
}	
