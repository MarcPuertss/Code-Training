#include <iostream>
#include <queue>

using namespace std;

// Pre:
// Post: La cua retornada té els mateixos elements que el valor rebut via el
//       paràmetre q, excepte que tot 0 que inicialment tenia un nombre parell
//       d'elements abans que ell ha estat esborrat, i tot 1 que inicialmente
//       tenia un nombre senar d'elements abans que ell ha estat esborrat.
queue<int> remove01(queue<int> q){
	int h = 0;
	queue<int> p;
	while(!q.empty()){
		if(q.front() == 0 and h % 2 == 0){}
		else if(q.front() == 1 and h % 2 == 1){}
		else p.push(q.front());
	q.pop();
	++h;
	
	}
	while(!p.empty()){
	if(p.size() != 1) cout << p.front() << " ";
	else cout << p.front();
	p.pop();
	}
	return p;
}
int main(){

	int i;
	queue<int> q;
	
	while(cin >> i){
	q.push(i);
	}	
	remove01(q);

}
