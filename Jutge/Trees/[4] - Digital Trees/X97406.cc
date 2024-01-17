 #include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 class dicc {
   public:
     dicc();  // Constructora per defecte. Crea un diccionari buit.
 
     ~dicc(); // Destructora
 
     // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
     void insereix(const string &k);
 
     nat quantes_comencen(string inicials) const;
     // Pre: inicials no conté el char ’#’
     // Post: Retorna el nº de claus que comencen per algun dels caràcters que conté inicials
 
   private:
     struct node {
       char _c;    // Símbol posició i-èssima de la clau
       node* _esq; // Fill esquerra, apunta a símbols mateixa posició formant un BST
       node* _cen; // Fill central, apunta a símbols següent posició
       node* _dre; // Fill dret, apunta a símbols mateixa posició formant un BST
       node(const char &c, node* esq = NULL, node* cen = NULL, node* dre = NULL);
     };
     node* _arrel;
     static void esborra_nodes(node* t);
     static node* insereix(node *t, nat i, const string &k);
     static void quantes_comencen_rec(node *n, char lletra, nat& count, bool& activar);
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
nat dicc::quantes_comencen(string inicials) const{
 if(inicials.size()>0){
  nat count = 0;
  for(int i = 0; i < inicials.size(); ++i){
    bool activar = false;
   quantes_comencen_rec(_arrel, inicials[i], count, activar);
  }
  return count;
 }
 else return 0;
}

void dicc::quantes_comencen_rec(node* n, char lletra, nat& count, bool& activar) {
if(n != nullptr){
 if (activar == true) {
      quantes_comencen_rec(n->_esq, lletra, count, activar);
      quantes_comencen_rec(n->_cen, lletra, count, activar); 
      quantes_comencen_rec(n->_dre, lletra, count, activar); 
      if(n->_c == '#') ++count;     
    } else if (n->_c < lletra) {
          quantes_comencen_rec(n->_dre, lletra, count, activar);
    } else if  (n->_c > lletra){
          quantes_comencen_rec(n->_esq, lletra, count, activar);
    }else {
          activar = true;
          quantes_comencen_rec(n->_cen, lletra, count, activar);  
    }
}
}
  
 // Aquí va la implementació del mètode públic quantes_comencen i privats addicionals


