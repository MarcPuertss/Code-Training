#include "sumOfTree.hpp"
using namespace std;

// Pre:
// Post: Retorna la suma dels valors de t
int sumOfTreeRec(BinaryTree<int>& t){

	if(t.isEmpty()) return 0;
	return sumOfTreeRec(t.getLeft()) + sumOfTreeRec(t.getRight())+ t.getRoot();
}

// Pre:
// Post: Retorna la suma dels valors de t
int sumOfTree(BinaryTree<int> t){

	return sumOfTreeRec(t);

}
