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
 
     // Modifica el contingut de l’arbre per tal de guardar a cada node la suma dels
     // nodes del seu subarbre.
     void arbre_sumes();
 
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
 
     // Aquí va l’especificació dels mètodes privats addicionals
     static void treesums(node *n, int &suma);
 };
 template<typename T>
 void Abin<T>:: arbre_sumes(){
  int suma = 0;
  treesums(_arrel, suma);
 }  
 template<typename T>
 void Abin<T>:: treesums(node *n, int &suma){
  if(n == nullptr) return;
    treesums(n->f_esq, suma);
    treesums(n->f_dret, suma);
    suma = (!(n->f_esq == nullptr ) ? n->f_esq->info : 0) + (!(n->f_dret == nullptr) ? n->f_dret->info : 0);
    n->info += suma;
 }