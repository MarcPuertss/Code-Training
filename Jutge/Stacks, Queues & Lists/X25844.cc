 #include <iostream>
 #include <vector>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename T>
 class pila { // pila en memòria dinàmica
   public:
     pila();
     // Crea pila buida
 
     ~pila();
     // Destrueix el p.i.
 
     pila(const vector<int> &v);
     // Crea pila amb els elements de v amb el mateix ordre.
 
     nat longitud() const;
     // Retorna el nombre d’elements del p.i.
 
     void mostra() const;
     // Mostra el p.i. pel canal estàndard de sortida.
 
     void duplica_amb_sumes();
     // Pre: true
     // Post: S’han duplicat els elements de la pila, a sobre de cada element hi ha un
     // nou element que conté la suma dels elements restants de la pila original
 
   private:
     struct node {
       T info;
       node* seg;
     };
     node* _cim; // Apunta al cim de la pila
     nat _mida;  // Nombre d’elements de la pila
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació del mètode duplica_amb_sumes i dels privats addicionals
template<typename T>
 void pila<T>:: duplica_amb_sumes(){
  node *p = _cim;
  int sum = 0;
  while(p != nullptr){
    sum += p->info;
    p = p->seg;
  }
  if(_cim != nullptr){
    bool prim = true;
    node * aux = _cim;
    node * aux2 = aux->seg;
    while(aux2 != nullptr){
      node *nounode = new node;
      if(prim){
        nounode->info = sum;
        nounode->seg = aux;
        _cim = nounode;
        prim = false;
      }
      else{
        sum -= aux->info;
        nounode->info = sum;
        aux->seg = nounode;
        nounode->seg = aux2;
        aux = aux2;
        aux2 = aux2->seg;
      }
      ++_mida;
    }
    aux->seg = nullptr;
    if(_mida == 1){
      node *nounode = new node;
      nounode->info == sum;
      _cim->seg = nounode;
      nounode->info = sum;
      nounode->seg = nullptr;
      ++_mida;
    }
  }
}
