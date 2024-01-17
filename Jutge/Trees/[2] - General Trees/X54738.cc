#include <cstdlib>
 #include <string>
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
 
   // Comprova que el contingut de cada node coincideix amb el seu grau
   bool es_arbre_compta_graus();
 
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
   bool tree_nodes(node *p);
   // Aquí va l’especificació dels mètodes privats addicionals
 };
 // Aquí va la implementació del mètode es_arbre_compta_graus
  template <typename T>
 //pre: .
 //post Retorna true si la suma de tots els nodes es igual a l'informació dins de l'arrel.
 bool Arbre<T>::es_arbre_compta_graus(){
  if(_arrel== nullptr) return true;
  return tree_nodes(_arrel);
 }
//Pre: L'arrel com a pare dins de l'arbre.
 //post Retorna true si la suma de tots els nodes es igual a l'informació dins de l'arrel.
template <typename T>
bool Arbre<T>::tree_nodes(node *p) {  
  if(p == nullptr) return true;
    int suma = 0; 
    node *germ = p->primf;
    while(germ != nullptr) {
        suma++;
        germ = germ->seggerm;
      }
    if (suma != p->info) return false;

    germ = p->primf;
    while(germ != nullptr){
      if(!tree_nodes(germ)) return false;
      
      germ = germ->seggerm;
    }
  return true;
}