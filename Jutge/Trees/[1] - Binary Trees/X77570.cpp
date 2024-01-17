#include "BinaryTree.hpp"
#include "maximumTree.hpp"
//Pre: Rep 3 arbres binaris d'enters positius t1, t2 i t3.
//Post: Construeix un arbre (t3)des de l'arrel fins al final, comparant les arrels de t1 o t2 i la recursivitat acava cuan s1 i s2 estan buides.
void maximumTreeRec(BinaryTree<int>& t1, BinaryTree<int>& t2,  BinaryTree<int>& t3){

    if(t1.isEmpty() and t2.isEmpty()) {
		t3 = BinaryTree<int>();
		return;
	}
	int root;
	if(t1.isEmpty()) root = t2.getRoot();
	else if(t2.isEmpty()) root = t1.getRoot();
	else{
		int roott1 = t1.getRoot();
		int roott2 = t2.getRoot();
		if(roott1 >= roott2) root = roott1;
		else root = roott2;
	}
	t3 = BinaryTree<int>(root, BinaryTree<int>(), BinaryTree<int>());
	if(t1.isEmpty()){
		maximumTreeRec(t1, t2.getLeft(),t3.getLeft());
		maximumTreeRec(t1, t2.getRight(),t3.getRight());
	
	}else if(t2.isEmpty()){
		maximumTreeRec(t1.getLeft(), t2, t3.getLeft());
		maximumTreeRec(t1.getRight(), t2, t3.getRight());
	
	}else{
		 maximumTreeRec(t1.getLeft(), t2.getLeft(), t3.getLeft());
         maximumTreeRec(t1.getRight(), t2.getRight(), t3.getRight());
	
	}
	
}

// Pre: Rep dos arbres binaris d'enters positius t1 i t2.
// Post: Retorna un arbre, on a la seva arrel hi ha el màxim de les arrels de t1,t2,
// en l'arrel del fill esquerre hi ha el màxim de les arrels dels fills esquerre de t1,t2,
// en l'arrel del fill dret hi ha el màxim de les arrels dels fills drets de t1,t2,
// i així successivament.
// Quan un dels arbres no té valors definits en alguna posició, l'arbre resultant hi té
// el valor de l'altre arbre en aquella posició.
BinaryTree<int> maximumTree(BinaryTree<int> t1,BinaryTree<int> t2){

    BinaryTree<int> t3;
    maximumTreeRec(t1, t2, t3);
    return t3;
}
