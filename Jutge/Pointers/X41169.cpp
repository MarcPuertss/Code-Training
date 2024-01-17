#include "copy.hpp"

// Pre:  pitem apunta al primer element d'una seqüència correcta d'items encadenats.
//       L'últim element de la seqüència apunta a NULL. El propi pitem podria ser NULL,
//       cas en el qual no hi hauria elements a la seqüència.
// Post: Retorna un Item* que representa una seqüència d'items nous tals que la seva
//       corresponent seqüència de valors és una còpia de la original.
//       La seqüència de valors original no ha canviat.
Item* copy(Item* pitem){
		if(pitem == NULL) return NULL;
		Item *pcopy= new Item();
		pcopy->value = pitem->value;
		pcopy->next = copy(pitem->next); 
		return pcopy;
}
