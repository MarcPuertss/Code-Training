#include "heightOfTree.hpp"

using namespace std;

int heightOfTreeRec(const BinaryTree<int> &t) {
   
    if(t.isEmpty()) return 0;
    int l = heightOfTreeRec(t.getLeft());
    int r = heightOfTreeRec(t.getRight()); 
    if(l > r){
    	return 1 + l;
    }else{
    	return 1 + r;
	}
}

int heightOfTree(BinaryTree<int> t) {
    return heightOfTreeRec(t);
}
