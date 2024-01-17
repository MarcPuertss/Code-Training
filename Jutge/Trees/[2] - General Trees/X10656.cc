#include <cstdlib>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename T>
 class Arbre {
 
 public:
   // Construeix un Arbre format per un únic node que conté a x.
   Arbre(const T &x);
 
   // Tres grans.
   Arbre(const Arbre<T> &a);
   Arbre& operator=(const Arbre<T> &a);
   ~Arbre() throw();
 
   // Col·loca l’Arbre donat com a primer fill de l’arrel de l’arbre sobre el que s’aplica el mètode i l’arbre a queda invalidat; després de fer b.afegir_fill(a), a no és un arbre vàlid.
   void afegir_fill(Arbre<T> &a);
 
   static const int ArbreInvalid = 400;
 
   // Indica quants nodes de grau n té.
   nat quants_grau(nat n) const;
 
 private:
   Arbre(): _arrel(NULL) {};
   struct node {
     T info;
     node* primf;
     node* seggerm;
   };
   node* _arrel;
   static node* copia_arbre(node* p);
   static void destrueix_arbre(node* p) throw();
 
   // Aquí va l’especificació dels mètodes privats addicionals
   void qgraus(const node* p, const nat grau, nat& quant) const;
 };
 template<typename T>
 nat Arbre<T>::quants_grau(nat n) const{
 	if(_arrel == nullptr) return 0;
 	nat quant = 0;
 	qgraus(_arrel, n, quant);
 	return quant;
 }
 template<typename T> 
 void Arbre<T>::qgraus(const node* p, const nat grau, nat& quant) const{
 	if(p->primf == nullptr){
 		if(grau == 0) ++quant;
 		return;
 	}
  	int d = 0;
 	node* aux = p->primf;
 	while(aux != nullptr){
 		++d;
 		qgraus(aux, grau, quant);
 		aux = aux->seggerm;
 	}
 	if(d == grau) ++quant;
 }
