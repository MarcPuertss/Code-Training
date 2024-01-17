#include <sstream>
#include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename Clau>
 class dicc {
 
   public:
     // Constructora per defecte. Crea un diccionari buit.
     dicc();
 
     // Destructora
     ~dicc();
 
     // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
     void insereix(const Clau &k);
 
     // Retorna quants elements (claus) té el diccionari.
     nat quants() const;
 
     // Retorna la segona clau.
     // Pre: El diccionari té com a mínim 2 claus.
     Clau segona() const;
 
   private:
     struct node {
       Clau _k;      // Clau
       node* _esq;   // fill esquerre
       node* _dret;  // fill dret
       nat _n;       // Nombre de nodes del subarbre
       node(const Clau &k, node* esq = NULL, node* dret = NULL);
     };
     node *_arrel;
 
     static void esborra_nodes(node* m);
     static node* insereix_bst(node *n, const Clau &k, bool &ins);
     static Clau segona_rec(node *n, int &c);
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };

template <typename Clau>
Clau dicc<Clau>::segona() const{
  int c = 0;
  return segona_rec(_arrel, c);
}
template <typename Clau>
Clau dicc<Clau>::segona_rec(node *n, int &c) {
  if(n == nullptr){
    return Clau();
  }
  Clau esq = segona_rec(n->_esq, c);
  if(c == 2){
    return esq;
  }
  c++;
  if(c == 2){
    return n->_k;
  }

  Clau drt = segona_rec(n->_dret, c);
  return drt; 
}
