#include <cstdlib>
#include <vector>
#include <queue>
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

  // Col·loca l’Arbre donat com a darrer fill de l’arrel de l’arbre sobre el que s’aplica el mètode i l’arbre a queda invalidat; després de fer b.afegir_fill(a), a no és un arbre vàlid.
  void afegir_darrer_fill(Arbre<T> &a);

  static const int ArbreInvalid = 400;

  // Retorna un vector amb les sumes de tots els elements de cada nivell.
  vector<T> sumes_nivells() const;

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
};
// Aquí va la implementació del mètode sumes_nivells
template<typename T>
vector<T> Arbre<T>:: sumes_nivells() const{
  vector<T> sumes;
  if(_arrel == nullptr) return sumes;

  queue<node*> cua;
  cua.push(_arrel);
  while(!cua.empty()){
    int n_size = cua.size();
    T suma = 0;

    for(int i = 0; i < n_size; ++i){
      node *actual = cua.front();
      cua.pop();
      suma += actual->info;

      node *fill = actual->primf;
      while(fill != nullptr){
        cua.push(fill);
        fill = fill->seggerm;
      }
    }

    sumes.push_back(suma);
  }  
  return sumes;
}