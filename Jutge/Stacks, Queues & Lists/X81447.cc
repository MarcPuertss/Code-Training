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
 
     void fusiona(const pila<T> &p2);
     // Pre: Les piles del p.i. i p2 estan ordenades de menor a major
     // Post: Al p.i. se li han afegit els elements de p2 ordenadament. p2 no es modifica
 
   private:
     struct node {
       T info;
       node* seg;
     };
     node* _cim; // Apunta al cim de la pila
     nat _mida;  // Nombre d’elements de la pila
 
     // Aquí va l’especificació dels mètodes privats addicionals
};
template <typename T>
void pila<T>::fusiona(const pila<T> &p2){
	 // Pre: Les piles del p.i. i p2 estan ordenades de menor a major
    // Post: Al p.i. se li han afegit els elements de p2 ordenadament. p2 no es modifica
 	node* actual1 = _cim;
	node* actual2 = p2._cim;
	node* previ = nullptr;
	while(actual2 != nullptr ){
		if(actual1 == nullptr){
			node* nounode = new node;
			nounode->info = actual2->info;
			nounode->seg = actual1;
			_cim = nounode;
			++_mida;
			actual1 = nounode;
			actual2 = actual2->seg;
		}
		else if(actual1->info >= actual2->info){
			if(previ == nullptr){
				node* nounode = new node;
				nounode->info = actual2->info;
				nounode->seg = actual1;
				_cim = nounode;
				previ = nounode;
				++_mida;
				actual2 = actual2->seg;
			}
			else{
				node* nounode = new node;
				nounode->info = actual2->info;
				nounode->seg = actual1;
				previ->seg = nounode;
				previ = nounode;
				++_mida;
				actual2 = actual2->seg;
			}
		 }
		 else{
		 	if(actual1->seg == nullptr){
		 		node* nounode = new node;
				nounode->info = actual2->info;
				actual1->seg = nounode;
				previ = actual1;
				nounode->seg = nullptr;
				actual1 = nounode;
				++_mida;
				actual2 = actual2->seg;
			}
		 	else{
		 		previ = actual1;
		 		actual1 = actual1->seg;
		 	}
		 
		 }
	}
}





