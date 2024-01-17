#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void sort_sequence(const vector<int>& input_sequence) {
    // Priority queue for non-decreasing order
    priority_queue<int, vector<int>, greater<int>> min_heap;
    
    // Priority queue for non-increasing order
    priority_queue<int, vector<int>, less<int>> max_heap;
    
    // Push each element into both heaps
    for (int num : input_sequence) {
        min_heap.push(num);
        max_heap.push(num);
    }
    
    // Output in non-decreasing order
    while (!min_heap.empty()) {
        cout << min_heap.top();
        min_heap.pop();
        if (!min_heap.empty()) {
            cout << " ";
        }
    }
    cout << endl;
    
    // Output in non-increasing order
    while (!max_heap.empty()) {
        cout << max_heap.top();
        max_heap.pop();
        if (!max_heap.empty()) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    // Input sequence of integer numbers
    vector<int> v;
    int n;

    // Read integers until there is no more input
    while (cin >> n) {
        v.push_back(n);
    }

    // Sorting the sequence using priority queues
    sort_sequence(v);

    return 0;
}
