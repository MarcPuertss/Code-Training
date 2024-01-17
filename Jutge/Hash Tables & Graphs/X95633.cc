
#include <vector>
using namespace std;
typedef unsigned int nat;

class graf {
// Graf dirigit i no etiquetat.
// Les arestes es guarden en multillistes d’adjacència en memòria dinàmica.
public:
    // Constructora per defecte. Crea un graf buit de n vèrtexs.
    graf(nat n);

    // Destructora
    ~graf();

    // Retorna un vector amb els successors del vèrtex v
    vector<nat> successors(nat v) const;

    // Retorna un vector amb els predecessors del vèrtex v
    vector<nat> predecessors(nat v) const;

    void insereix(nat orig, nat dest);
    // Pre: orig i dest són menors que el número de vèrtexs
    // Post: Insereix una aresta que connecta des del vèrtex orig cap al vèrtex dest.
        // Si l’aresta ja existia no fa res.

private:
    nat nv; // Nombre de vèrtexs
    struct node {
    nat orig; // Vèrtex origen 
    nat dest; // Vèrtex destí 
    node *seg_succ; // Punter al següent successor
    node *seg_pred; // Punter al següent predecessor
    };
    vector<node *> prim_succ; // Punters al primer successor de cada vèrtex.
                            // La llista de successors està ordenada.
    vector<node *> prim_pred; // Punters al primer predecessor de cada vèrtex.
                            // La llista de predecessors està ordenada.

    // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode públic insereix i privats addicionals

void graf::insereix(nat orig, nat dest) {
    // Comprovar que l'aresta no existeix ja
    node *p = prim_succ[orig];
    node *prev = nullptr;
    while (p != nullptr && p->dest < dest) {
        prev = p;
        p = p->seg_succ;
    }
    if (p != nullptr && p->dest == dest) return; // L'aresta ja existeix

    // Crear nou node i actualitzar punters
    node *nou = new node;
    nou->orig = orig;
    nou->dest = dest;
    nou->seg_succ = p;
    nou->seg_pred = nullptr;
    if(prev==nullptr) prim_succ[orig] = nou;
    else prev->seg_succ = nou;


    // Afegir com a predecessor
    prev = nullptr;
    p = prim_pred[dest];
    while (p != nullptr && p->orig < orig) {
        prev = p;
        p = p->seg_pred;
    }
    nou->seg_pred = p;
    if(prev==nullptr) prim_pred[dest] = nou;
    else prev->seg_pred = nou;

}