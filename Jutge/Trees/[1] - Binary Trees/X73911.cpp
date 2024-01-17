#include "maxOfTree.hpp"

using namespace std;

int max(const BinaryTree<int> &t) {
    if (t.isEmpty()) return -2147483648;
    int n1 = t.getRoot(), n2 = max(t.getLeft()), n3 = max(t.getRight());
    if (n2 >= n3) {
        if (n1 >= n2) return n1;
        else return n2;
    }
    else {
        if (n1 >= n3) return n1;
        else return n3;
    }
}

int maxOfTree(BinaryTree<int> t) {
    return max(t);
}
