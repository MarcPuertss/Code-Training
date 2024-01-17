#include <iostream>

using namespace std;

struct Item {
	int value;
	Item* next;
};

void pantera(Item *pitem, int& cont){

	if(pitem == NULL) return;
	cont += pitem->value;
	pitem = pitem->next;	
	pantera(pitem,cont);
}

// Pre:  pitem apunta al primer element d'una seqüència correcta d'items encadenats.
//       L'últim element de la seqüència apunta a NULL. El propi pitem podria ser NULL,
//       cas en el qual no hi hauria elements a la seqüència.
// Post: retorna la suma dels valors guardats a la seqüència.
int sumOfValues(Item *pitem){

	int cont = 0;
	pantera(pitem, cont);
	return cont;

}
