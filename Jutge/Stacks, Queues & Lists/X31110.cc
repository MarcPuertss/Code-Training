 #include <iostream>
 #include <vector>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename T>
 class cua { // Cua no circular en memòria dinàmica
   public:
     cua();
     // Construeix una cua buida.
 
     ~cua();
     // Destrueix el p.i.
 
     cua(const vector<int> &v);
     // Crea cua amb els elements de v amb el mateix ordre.
 
     nat longitud() const;
     // Retorna el nombre d’elements del p.i.
 
     void mostra() const;
     // Mostra el p.i. pel canal estàndard de sortida.
 
     void fusiona(const cua<T> &c2);
     // Pre: Les cues del p.i. i c2 estan ordenades de menor a major
     // Post: Al p.i. se li han afegit els elements de c2 ordenadament. c2 no es modifica
 
   private:
     struct node {
       T info;
       node* seg;
     };
     node* _pri; // Apunta al primer element de la cua
     node* _ult; // Apunta al darrer element de la cua
     nat _mida;
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
template <typename T>
void cua<T>::fusiona(const cua<T> &c2){
 // Pre: Les cues del p.i. i c2 estan ordenades de menor a major
 // Post: Al p.i. se li han afegit els elements de c2 ordenadament. c2 no es modifica
 	node* actual1 = _pri;
	node* actual2 = c2._pri;
	node* previ = nullptr;
	if(c2._mida == 0) return;
	while(actual2 != nullptr ){
		if(actual1 == nullptr){
			_pri = new node;
			_pri->info = actual2->info;
			_pri->seg = nullptr;
			actual1 = _pri;
			++_mida;
			actual2 = actual2->seg;
		}
		else if(actual1->info >= actual2->info){
			if(previ == nullptr){
				node* nounode = new node;
				nounode->info = actual2->info;
				nounode->seg = actual1;
				_pri = nounode;
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
	node* nounode = _pri;
	while(nounode->seg != nullptr) nounode = nounode->seg;
	if(nounode != nullptr) _ult = nounode;
}
