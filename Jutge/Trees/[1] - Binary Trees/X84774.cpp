#include <iostream>
#include <string>
#include "utils.hpp"
using namespace std;

#include "BinaryTree.hpp"

int evaluateR(const BinaryTree<string>& t, int& result){

	if(t.getRoot() == "+") result = evaluateR(t.getLeft(), result) + evaluateR(t.getRight(), result);
	else if(t.getRoot() == "-") result = evaluateR(t.getLeft(), result) - evaluateR(t.getRight(), result);
	else if(t.getRoot() == "*") result = evaluateR(t.getLeft(), result) * evaluateR(t.getRight(), result);
	
	else result = mystoi(t.getRoot());
	return result;

}
// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre els naturals i els operadors +,-,*.
//       Les operacions no produeixen errors d'overflow.
// Post: Retorna l'avaluació de l'expressió representada per t.
int evaluate(const BinaryTree<string> &t)
{
	int result = 0;
	evaluateR(t, result);
	return result;

}

