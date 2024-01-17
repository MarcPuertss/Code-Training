#include <cstdlib>
#include <iostream>
using namespace std;
typedef unsigned int nat;

template <typename T>
class Abin {
  public:
    Abin(): _arrel(NULL) {};
    // Pre: cert
    // Post: el resultat és un arbre sense cap element

    Abin(Abin<T> &ae, const T &x, Abin<T> &ad);
    // Pre: cert
    // Post: el resultat és un arbre amb un element i dos subarbres

    // Les tres grans
    Abin(const Abin<T> &a);
    ~Abin();
    Abin<T>& operator=(const Abin<T>& a);

    // operador << d’escriptura
    template <class U> friend std::ostream& operator<<(std::ostream&, const Abin<U> &a);

    // operador >> de lectura
    template <class U> friend std::istream& operator>>(std::istream&, Abin<U> &a);

    Abin(nat n);
    // Pre: cert
    // Post: Crea un arbre binari complert amb n nivells, on la informació
    // de cada node de l’arbre és el nivell a on està situat

  private:
    struct node {
      node* f_esq;
      node* f_dret;
      T info;
    };
    node* _arrel;
    static node* copia_nodes(node* m);
    static void esborra_nodes(node* m);
    static void print_nodes(node* m, ostream &os, string d1);
    node* creatree(nat n, nat i);
    // Aquí va l’especificació dels mètodes privats addicionals
};
template<typename T>
Abin<T>:: Abin(nat n){
  _arrel = creatree(n, 1);
}
// Aquí va la implementació del mètode Abin(nat n) i privats addicionals
template<typename T>
typename Abin<T>::node* Abin<T>::creatree(nat n, nat i){
  if(n == 0) return nullptr;
  node *nounode = new node;
  nounode->info = i;
  if(n > 1){
    nounode->f_esq = creatree(n-1, i+1);
    nounode->f_dret = creatree(n-1, i+1);
  }else{
    nounode->f_esq = nullptr;
    nounode->f_dret = nullptr;
  }
  return nounode;
}