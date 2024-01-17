#include "esborraSenars.hpp"

using namespace std;

void esborraSenars(stack<int> &s) {
    if(s.empty()) return;
    int n = s.top();
    s.pop();
    esborraSenars(s);
    if (n % 2 == 0) s.push(n);
}
