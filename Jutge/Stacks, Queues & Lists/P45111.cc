#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    stack<int> s;
    while (cin >> n) {
        if (n != -1) s.push(n);
        else {
            while (!s.empty()) {
                cout << s.top();
                s.pop();
                if (!s.empty()) cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
