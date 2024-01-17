#include "merge.hpp"
// Pre:  pitem1, pitem2 apunten als primers elements de seqüències correctes d'items encadenats.
//       Els últims elements de les seqüències apunten a NULL. Els propis pitem1,pitem2 podrien
//       ser NULL, cas en el qual no hi hauria elements a les respectives seqüències.
// Post: Retorna un Item* que representa la fusió ordenada de les dues seqüències originals.
//       Les seqüències de valors originals no han canviat.
Item* merge(Item* pitem1, Item* pitem2){
	
	Item *pmer= new Item();
	if(pitem1 == NULL && pitem2 == NULL) return NULL;
	
	else if(pitem1 != NULL && pitem2 == NULL){
		pmer->value=pitem1->value;
		pmer->next = merge(pitem1->next,pitem2);
		
	}	
	else if(pitem1 == NULL && pitem2 != NULL){
		pmer->value=pitem2->value;
		pmer->next = merge(pitem1,pitem2->next);
	}
	else{
		
		if(pitem1->value < pitem2->value){
			pmer->value=pitem1->value;
			pmer->next = merge(pitem1->next,pitem2);
		}
		else{
			pmer->value=pitem2->value;
			pmer->next = merge(pitem1,pitem2->next);
		}	
	}
	return pmer;
}
