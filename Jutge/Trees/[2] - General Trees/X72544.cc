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

  // Col·loca l’Arbre donat com a darrer fill de l’arrel de l’arbre sobre el que s’aplica el mètode i l’arbre a queda invalidat; després de fer b.afegir_fill(a), a no és un arbre vàlid.
  void afegir_darrer_fill(Arbre<T> &a);

  // Imprimeix la informació dels nodes en preodre, cada element en una nova línia i precedit per espais segons el nivell on està situat.
  void preordre() const;

  static const int ArbreInvalid = 400;

  // Per cada fulla afegeix un nou fill que conté la suma de tots els elements del camí que va de l’arrel a la fulla.
  void crea_fills_sumes_camins();

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
  static void preordre(node* p, string pre);
  void cf_sumes(node* n, int& sum);
 };

  template<typename T>
  void Arbre<T>::crea_fills_sumes_camins(){
      if(_arrel == nullptr) return;

      int sum = 0;
      cf_sumes(_arrel,sum);
  }
  template<typename T>
  void Arbre<T>::cf_sumes(node* n,int& sum){
    if(n->primf == nullptr){
      n->primf = new node;
      n->primf->info = sum + n->info;
      n->primf->primf = nullptr;
      n->primf->seggerm = nullptr;
      return;
    } 
    sum += n->info;  
    node* aux = n->primf;
    while(aux != nullptr){
        cf_sumes(aux, sum);
        aux = aux->seggerm;
    }
    sum -= n->info;
  }