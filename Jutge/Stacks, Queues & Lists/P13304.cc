#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

int main() {
    string s;
    while(getline(cin, s)) {
        istringstream stream(s);
        int n;

        stack <int> par;
        stack <int> impar;
        while(stream >> n) {
            if(n % 2 == 0) par.push(n);
            else impar.push(n);
        }

        while(!par.empty()) {
            cout << par.top();
            par.pop();
            if((impar.empty() and !par.empty()) or !impar.empty()) cout << " ";
        }

        while(!impar.empty()) {
            cout << impar.top();
            impar.pop();
            if(!impar.empty()) cout << " ";
        }

        cout << endl;
    }
    return 0;
}
