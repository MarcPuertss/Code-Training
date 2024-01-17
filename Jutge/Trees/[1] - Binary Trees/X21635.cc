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
 
     bool compleix_suma_fills() const;
     // Pre: true
     // Post: retorna si compleix la propietat ’Suma dels fills’:
     // Per tot node el seu valor és igual a la suma dels valors
     // dels nodes (arrels) del fill esquerre i del fill dret.
 
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
 bool sisumafills(node *n) const;
};

// Aquí va la implementació del mètode compleix_suma_fills i dels privats re_compleix_suma_fillsicionals
template<typename T>
bool Abin<T>::sisumafills(node* n) const{
    bool compleix = true;
        if(n != nullptr){
            if(n->f_dret != nullptr || n->f_esq != nullptr){
                int suma = (!(n->f_esq == nullptr ) ? n->f_esq->info : 0) + (!(n->f_dret == nullptr) ? n->f_dret->info : 0);
                if(suma != n->info) compleix = false;  
            }
            if(compleix) compleix = sisumafills(n->f_esq);
            if(compleix) compleix = sisumafills(n->f_dret);
        }
    return compleix;
}


template <typename T>
bool Abin<T>::compleix_suma_fills() const{

    bool compleix = sisumafills(_arrel);
    return compleix;
} 