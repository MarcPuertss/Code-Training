#include "sizeOfTree.hpp"
using namespace std;

// Pre:
// Post: Retorna la suma dels valors de t
int sizeOfTreeRec(BinaryTree<int>& t){

	if(t.isEmpty()) return 0;
	return sizeOfTreeRec(t.getLeft()) + sizeOfTreeRec(t.getRight())+ 1;
}

// Pre:
// Post: Retorna la mida de t;
int sizeOfTree(BinaryTree<int> t){

	return sizeOfTreeRec(t);

}
