#include "posInTree.hpp"

using namespace std;

list<int> pos(const BinaryTree<int> &t, const int &x) {
    if (t.isEmpty()) return {};
    if (t.getRoot() == x) return {t.getRoot()};

    list<int> l2 = pos(t.getLeft(), x);
    list<int> l3 = pos(t.getRight(), x);

    if (!l2.empty() && l2.back() == x) {
        l2.push_front(t.getRoot());
        return l2;
    }
    if (!l3.empty() && l3.back() == x) {
        l3.push_front(t.getRoot());
        return l3;
    }

    return {};
}

list<int> posInTree(const BinaryTree<int> t, int x) {
    return pos(t, x);
}
