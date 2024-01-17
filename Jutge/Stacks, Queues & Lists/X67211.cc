// Add or remove includes
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

#ifndef IOSTACKFUNCTIONS
#define IOSTACKFUNCTIONS

struct Test {
    queue<int> q1,q2;
};

//Pre: Introdueix dos cues d'enters q1 i q2; 
//Post: Retorna una cua on compara quin es el nombre més gran entre q1 i q2 de totes les posicions.
queue<int> maximumQueue(queue<int> q1,queue<int> q2){
	
	queue <int> q3;
	
	while (!q1.empty() or !q2.empty()) {
	//Inv: Tracta tots els valors de una de les cues o les dues q1, q2. fins que una de les dues o les dues estigui buida.
        if (!q1.empty() and !q2.empty()) {
            if (q1.front() >= q2.front()) q3.push(q1.front());
            else q3.push(q2.front());
        q1.pop(); 
        q2.pop();
        }
        else if (q1.empty() and !q2.empty()) {
			q3.push(q2.front());
			q2.pop();
        }
        else if (!q1.empty() and q2.empty()) {
            q3.push(q1.front());
            q1.pop();
        }
    }
    return q3;
}

queue<int> readQueue(string s)
{
    istringstream mycin(s);
    queue<int> q;
    int x;
    while (mycin >> x)
        q.push(x);
    return q;
}

void writeQueue(queue<int> q)
{
    bool writespace = false;
    while (not q.empty()) {
        if (writespace) cout << " ";
        cout << q.front();
        q.pop();
        writespace = true;
    }
    cout << endl;
}
#endif

int main()  {
	vector<Test> v;
    string s;
    while (getline(cin, s)) {
        Test t;
        t.q1=readQueue(s);
        getline(cin, s);
        t.q2=readQueue(s);
        v.push_back(t);
    }
    for (int i = 0; i < int(v.size()); ++i) {
        writeQueue(maximumQueue(v[i].q1,v[i].q2));
    }
}

