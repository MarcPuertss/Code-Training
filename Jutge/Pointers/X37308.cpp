#include "sumOfValuesEvenPosition.hpp"
// Pre:  pitem apunta al primer element d'una seqüència correcta d'items encadenats.
//       L'últim element de la seqüència apunta a NULL. El propi pitem podria ser NULL,
//       cas en el qual no hi hauria elements a la seqüència.
// Post: retorna la suma dels valors guardats en els items a posició parell en la seqüència.
int sumOfValuesEvenPosition(Item *pitem){
	if(pitem == NULL) return 0;
	if(pitem->next == NULL) return pitem->value;
	else  return pitem->value + sumOfValuesEvenPosition(pitem->next->next);

}
