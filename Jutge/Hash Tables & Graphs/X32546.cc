#include <iostream>
 using namespace std;
 typedef unsigned int nat;
 
 class dicc {
   // Taula de dispersió amb direccionament obert fent sondeig lineal.
   public:
     dicc(nat m);
     // Pre: m > 0
     // Post: Crea un diccionari buit en una taula de dispersió de mida m
 
     ~dicc();
     // Pre: Cert
     // Post: Destrueix el diccionari
 
     nat quants() const;
     // Pre: Cert
     // Post: Retorna quants elements (claus) té el diccionari.
 
     void print() const;
     // Pre: Cert
     // Post: Imprimeix per cout del contingut de la taula de dispersió
 
     void insereix(const int &k);
     // Pre: Cert
     // Post: Insereix la clau k en el diccionari. Si ja hi era, no fa res.
     // Redimensiona la taula de dispersió amb una mida el doble que 
     // l’anterior més un si el factor de càrrega és superior a 0.8
 
     float factor_de_carrega() const;
     // Pre: Cert
     // Post: Retorna el factor de càrrega de la taula de dispersió
 
     void redispersio();
     // Pre: Cert
     // Post: Redimensiona la taula de dispersió amb una mida el doble que 
     // l’anterior més un (_M passa a ser 2*_M+1)
 
   private:
     enum Estat {lliure, esborrat, ocupat};
     struct node_hash {
       int   _k;    // Clau
       Estat _est;
     };
     node_hash *_taula;  // Taula amb les claus del diccionari
     nat _M;             // Mida de la taula
     nat _quants;        // Nº d’elements guardats al diccionari
 
     static long const MULT = 31415926;
 
     static long h(int k);
     // Pre: Cert
     // Post: Retorna un valor de dispersió entre 0 i LONG_MAX a partir de k
 
     nat busca_node(const int &k) const;
     // Pre: Cert
     // Post: Retorna la posició on es troba l’element amb la clau k o,
     // en cas que no trobi la clau, la primera posició no ocupada.
 
     // Aquí va l’especificació dels mètodes privats addicionals
 
 };
 
 // Aquí va la implementació dels mètodes públics factor_de_carrega, redispersio i
 // dels mètodes privats addicionals

  float dicc::factor_de_carrega() const{
   
    return (float)_quants/_M;
  }

  void dicc::redispersio(){

    node_hash *nueva_tabla = new node_hash[2 * _M + 1];
    nat nueva_mida = 2 * _M + 1;
    nat nueva_cantidad = 0;

    // Insertar todos los elementos de la tabla anterior en la nueva tabla
    for (nat i = 0; i < _M; ++i) {
        if (_taula[i]._est == ocupat) {
            nat pos = h(_taula[i]._k) % nueva_mida;
            while (nueva_tabla[pos]._est == ocupat) {
                pos = (pos + 1) % nueva_mida;
            }
            nueva_tabla[pos] = _taula[i];
            ++nueva_cantidad;
        }
    }

    // Asignar la nueva tabla a la variable de instancia _taula
    _M = nueva_mida;
    _quants = nueva_cantidad;
    delete[] _taula;
    _taula = nueva_tabla;
  }