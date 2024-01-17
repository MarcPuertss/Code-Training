#include "sumAtDepthEven.hpp"

using namespace std;

int sumAtDepthEvenRec(const BinaryTree<int> &t) {
    if(t.isEmpty()) return 0;
    int i = 0;
    if (!t.getLeft().isEmpty()) {
        i += sumAtDepthEvenRec(t.getLeft().getLeft());
        i += sumAtDepthEvenRec(t.getLeft().getRight());
    }
    if (!t.getRight().isEmpty()) {
        i += sumAtDepthEvenRec(t.getRight().getLeft());
        i += sumAtDepthEvenRec(t.getRight().getRight());
    }
     i += t.getRoot();

    return i;
}
// Pre:
// Post: Retorna la suma dels valors de t a profunditat parell
int sumAtDepthEven(BinaryTree<int> t){
    return sumAtDepthEvenRec(t);
 }
