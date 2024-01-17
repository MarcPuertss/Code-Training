#include "reverseTree.hpp"

void reverse(const BinaryTree<int> &t, BinaryTree<int> &r) {
    if (t.isEmpty()) {
        r = BinaryTree<int>();
        return;
    }
    int root = t.getRoot();

    r = BinaryTree<int>(root, BinaryTree<int>(), BinaryTree<int>());

    reverse(t.getLeft(), r.getRight());
    reverse(t.getRight(), r.getLeft());
}

BinaryTree<int> reverseTree(BinaryTree<int> t) {
    BinaryTree<int> r = BinaryTree<int>();
    reverse(t, r);
    return r;
}
