#include "call_registry.hpp"

// Cost: O(1)
// És una operació de temps constant, 
// ja que només implica l'assignació de valors inicials.
call_registry::call_registry() throw(error){
    _arrel = nullptr; 
    _mida = 0;
}

// Cost: O(N), on N és el nombre de nodes a l'arbre.
// S'utilitza per copiar un subarbre, i en el pitjor cas, 
// cada node del subarbre ha de ser copiat una vegada.
call_registry::node* call_registry::copiar_BST(node* n){
    if(n == nullptr) return nullptr;
    node *nounode = new node;
    nounode->_p = n->_p;
    nounode->_esq = copiar_BST(n->_esq);
    nounode->_dret = copiar_BST(n->_dret);
    nounode->_altura =n->_altura;
    return nounode;
}

// Cost: O(N), on N és el nombre de nodes a l'arbre.
// S'ha de copiar cada node de l'arbre original, i això es fa de manera recursiva. 
// En el pitjor cas, cada node de l'arbre original s'ha de copiar una vegada.
call_registry::call_registry(const call_registry& R) throw(error){
    _arrel = copiar_BST(R._arrel);
    _mida = R._mida;
}

// Cost: O(N), on N és el nombre de nodes a l'arbre.
// Esborra cada node de l'arbre, 
// i en el pitjor cas, cada node ha de ser esborrat una vegada. 
void call_registry::destruir_BST(node* n){
    if(n != nullptr){
        destruir_BST(n->_esq);
        destruir_BST(n->_dret);
        delete n;
    }
}

// Cost: O(N), on N és el nombre de nodes a l'arbre.
// Es destrueix l'arbre existent, i després es crea una còpia de l'arbre
// que es passa com a paràmetre.
// Això implica la còpia de cada node de l'arbre original.
call_registry& call_registry::operator=(const call_registry& R) throw(error){
    if(this != &R){
        destruir_BST(_arrel);
        _arrel = copiar_BST(R._arrel);
        _mida = R._mida;
    }
    return *this;
}

// Cost: O(N), on N és el nombre de nodes a l'arbre.
// S'ha de recórrer tot l'arbre i esborrar cada node.
// En el pitjor cas, es recorre cada node de l'arbre una vegada.
call_registry::~call_registry() throw(){
    destruir_BST(_arrel);
    
}

// Cost: O(log N), on N és el nombre de nodes a l'arbre.
// En el pitjor cas, es recorre l'arbre des de l'arrel
// fins a la posició d'inserció del nou número de telèfon.
void call_registry::registra_trucada(nat num) throw(error){
    if(not conte(num)){
        phone p = phone(num,"",1);
        _arrel = insereix(_arrel, p);
    }
    else{
        node* temporal = buscar(_arrel, num);
        temporal->_p++;
    }
}

// Cost: O(log N), on N és el nombre de nodes a l'arbre.
// L'operació d'inserció manté l'arbre AVL balancejat, 
// i en el pitjor cas, es podrien realitzar rotacions fins a l'arrel de l'arbre.
call_registry::node* call_registry::insereix(node* n, const phone &p){
    if(n == nullptr) {
        ++_mida;
        return new node {p, nullptr, nullptr, 0};
    }
    else if(p.numero() < n->_p.numero()){
        n->_esq = insereix(n->_esq, p);
    }
    else if(p.numero() > n->_p.numero()){
        n->_dret = insereix(n->_dret, p);
    }
    else{
        n->_p = p;
        return n;
    }
    //
    n->_altura = 1 + max(get_altura(n->_esq), get_altura(n->_dret));
   
    //EQUILIBRI ALV
    int balance = get_balance(n);
    //ROTACIONS AVL
    
    //S->IZQ
    if(balance > 1 && p.numero() < n->_esq->_p.numero()){
        return rotar_dret(n);
    }
    //S->DER
    if(balance < -1 && p.numero() > n->_dret->_p.numero()){
        return rotar_esq(n);
    }
    //DD
    if(balance > 1 && p.numero() > n->_esq->_p.numero()){
        n->_esq = rotar_esq(n->_esq);
        return rotar_dret(n);
    }
    //EE
    if(balance < -1 && p.numero() < n->_dret->_p.numero()){
        n->_dret = rotar_dret(n->_dret);
        return rotar_esq(n);
    }
    return n;
}

// Cost: O(1)
// Aquests mètodes realitzen operacions de temps constant 
// ja que només accedeixen als valors emmagatzemats en cada node.
int call_registry::get_altura(node* n) {
    if(n != nullptr){
        return n->_altura;
    }
    else{
        return 0;
    }
}

// Cost: O(1)
// Aquests mètodes realitzen operacions de temps constant 
// ja que només accedeixen als valors emmagatzemats en cada node.
int call_registry::get_balance(node* n){
    if(n != nullptr){
        return get_altura(n->_esq) - get_altura(n->_dret);
    }
    else{
        return 0;
    }
}

//Cost: O(1)
// Aquestes operacions realitzen rotacions en temps constant,
// ja que afecten només un conjunt fix de nodes.
call_registry::node* call_registry::rotar_esq(node* x){
    node* y = x->_dret;
    node* T2 = y->_esq;
    y->_esq = x;
    x->_dret = T2;

    x->_altura = 1 + max(get_altura(x->_esq), get_altura(x->_dret));
    y->_altura = 1 + max(get_altura(y->_esq), get_altura(y->_dret));

    return y;
}

// Cost: O(1)
// Aquestes operacions realitzen rotacions en temps constant,
// ja que afecten només un conjunt fix de nodes.
call_registry::node* call_registry::rotar_dret(node* y){
    node* x = y->_esq;
    node* T2 = x->_dret;
    x->_dret = y;
    y->_esq = T2;

    y->_altura = 1 + max(get_altura(y->_esq), get_altura(y->_dret));
    x->_altura = 1 + max(get_altura(x->_esq), get_altura(x->_dret));

    return x;
}

// Cost: O(log N), on N és el nombre de nodes a l'arbre.
// Realitza una inserció,
// i en el pitjor cas recorre l'arbre fins a la posició d'inserció.
void call_registry::assigna_nom(nat num, const string& name) throw(error){
    if(not conte(num)){

        phone p = phone(num,name,0);
        _arrel = insereix(_arrel, p);
    }
    else{
        node* temporal = buscar(_arrel, num);
        phone p = phone(num,name,temporal->_p.frequencia());
        temporal->_p = p;
    }
}

// Cost: O(log N), on N és el nombre de nodes a l'arbre.
// Realitza una eliminació mantenint l'equilibri AVL, 
// i en el pitjor cas, es realitzen rotacions fins a l'arrel.
void call_registry::elimina(nat num) throw(error){
    if(_arrel!=nullptr) {
        _arrel = elimina_recursiva(_arrel, num);
    }
    else throw error(ErrNumeroInexistent);
}


// Cost: O(log N), on N és el nombre de nodes a l'arbre
// Elimina un node de manera recursiva mantenint l'equilibri de l'arbre AVL.
call_registry::node* call_registry::elimina_recursiva(node* n, nat num) throw(error){
    if(n == nullptr){
        throw error(ErrNumeroInexistent);
    }
    if(num < n->_p.numero()){
        n->_esq = elimina_recursiva(n->_esq, num);
    }
    else if(num > n->_p.numero()){
        n->_dret = elimina_recursiva(n->_dret, num);
    }
    else{
        if(n->_esq == nullptr || n->_dret == nullptr) {
            node* temp = (n->_esq != nullptr) ? n->_esq : n->_dret;
            --_mida;
            if(temp == nullptr){
                delete n;

                return nullptr;
            }else{
                *n = *temp;
                delete temp;

            }
            
        }
        else {
            node *fill = trobar_fill(n->_dret);
            n->_p = fill->_p;
            n->_dret = elimina_minim(n->_dret);
        }
    }

    if (n == nullptr) {
        return n;
    }

    n->_altura = 1 + max(get_altura(n->_esq), get_altura(n->_dret)); 

    int balance = get_balance(n);
    if(balance > 1 && get_balance(n->_esq) >= 0){
        return rotar_dret(n);
    }
    if(balance > 1 && get_balance(n->_esq) < 0){
        n->_esq = rotar_esq(n->_esq);
        return rotar_dret(n);
    }

    if(balance < -1 && get_balance(n->_dret) <= 0){
        return rotar_esq(n);
    }
    if(balance < -1 && get_balance(n->_dret) > 0){
        n->_dret = rotar_dret(n->_dret);
        return rotar_esq(n);
    }
    return n;
}

// Cost: O(log N), on N és el nombre de nodes a l'arbre.
// Troba el fill més a l'esquerra del subarbre, que té un cost logarítmic.
call_registry::node* call_registry::trobar_fill(node* n){
    node* actual = n;
    while(actual->_esq != nullptr){
        actual = actual->_esq;
    }
    return actual;
}

// Cost: O(log N), on N és el nombre de nodes a l'arbre. 
// Elimina el node amb el valor mínim d'un subarbre mantenint l'equilibri AVL.
call_registry::node* call_registry::elimina_minim(node* &n) {
    if (n->_esq == nullptr) {
        node* dreta = n->_dret;
        --_mida;
        delete n;
        return dreta;
    }

    n->_esq = elimina_minim(n->_esq);

    n->_altura = 1 + max(get_altura(n->_esq), get_altura(n->_dret));

    int balance = get_balance(n);

    // Rotaciones para balancear el árbol
    if (balance > 1 && get_balance(n->_esq) >= 0) {
        return rotar_dret(n);
    }

    if (balance > 1 && get_balance(n->_esq) < 0) {
        n->_esq = rotar_esq(n->_esq);
        return rotar_dret(n);
    }

    return n;
}

// Cost: O(log N), on N és el nombre de nodes a l'arbre.
// Busca el número de telèfon a l'arbre, amb un cost logarítmic en el pitjor cas.
bool call_registry::conte(nat num) const throw(){
    return buscar(_arrel, num) != nullptr;
}

// Cost: O(log N), on N és el nombre de nodes a l'arbre.
// Cerca el número de telèfon a l'arbre, amb un cost logarítmic en el pitjor cas.
call_registry::node* call_registry::buscar(node *n, nat num){
    if(n == nullptr or n->_p.numero() == num){
        return n;
    }
    else if(num < n->_p.numero()){
        return buscar(n->_esq, num);
    }
    else{
        return buscar(n->_dret, num); 
    }
}

// Cost: O(log N), on N és el nombre de nodes a l'arbre.
// Obtingut el nom associat a un número de telèfon, 
// amb un cost logarítmic en el pitjor cas.
string call_registry::nom(nat num) const throw(error){
    node* trobat = buscar(_arrel, num);
    if(trobat != nullptr){
        return trobat->_p.nom();
    }
    else{
        throw error(ErrNumeroInexistent);
    }
}

// Cost: O(1)
// Obtingut el nombre de trucades associat a un número de telèfon,
// amb un cost logarítmic en el pitjor cas.
nat call_registry::num_trucades(nat num) const throw(error){
    
    node* trobat = buscar(_arrel, num);

    if(trobat != nullptr){
        return trobat->_p.frequencia();
    }
    else{
        throw error(ErrNumeroInexistent);
    }
}

// Cost: O(1)
// Verifica si l'arbre està buit en temps constant.
bool call_registry::es_buit() const throw(){
    return _arrel == nullptr;
}

// Cost: O(1)
// Retorna el nombre total d'entrades a l'arbre en temps constant.
nat call_registry::num_entrades() const throw(){
    return _mida;
}

// Cost: O(N * log(N)), on N és el nombre d'elements al vector V.
// Implementa l'algorisme Merge Sort, que divideix el vector en meitats,
// ordena cada meitat de manera recursiva i després combina (fusiona) les meitats ordenades.
// La complexitat de temps és O(N * log(N)) degut a les divisions logarítmiques del vector.
void call_registry::merge(vector<phone>& V, int esq, int mig, int dret) throw(error){
    int n1 = mig - esq + 1;
    int n2 = dret - mig;

    vector<phone> v_esq(n1);
    vector<phone> v_dret(n2);

    for (int i = 0; i < n1; i++)
        v_esq[i] = V[esq + i];
    for (int j = 0; j < n2; j++)
        v_dret[j] = V[mig + 1 + j];

    int i = 0;
    int j = 0;
    int k = esq;

    while (i < n1 && j < n2) {
        if (v_esq[i].nom() >= v_dret[j].nom()) {
            V[k] = v_esq[i];
            i++;
        } else {
            V[k] = v_dret[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
   
        V[k] = v_esq[i];
        i++;
        k++;
    }

    while (j < n2) {
        
        V[k] = v_dret[j];
        j++;
        k++;
    }
}

// Cost: O(N * log(N)), on N és el nombre d'elements al vector V.
// Aquest mètode s'utilitza en el procés de fusió (merge) durant l'algorisme de ordenació Merge Sort. 
// Divideix el vector en dues parts, ordena de manera recursiva cada part 
// i després fusiona les parts ordenades en un sol vector ordenat. 
// El cost total és O(N * log(N)) degut a les divisions recursives 
// i a les fusions que es realitzen de manera logarítmica.
void call_registry:: merge_sort(vector<phone>& V, int esq, int dret) {
    if (esq < dret) {
        int mig = esq + (dret - esq) / 2;
        merge_sort(V, esq, mig);
        merge_sort(V, mig + 1, dret);
        merge(V, esq, mig, dret);
    }
}


// Cost: O(N * log(N)), on N és el nombre de nodes a l'arbre.
// Aquest mètode realitza un recorregut de l'arbre (operació lineal respecte al nombre de nodes)
// i recopila els elements en un vector.
// Després de recopilar, s'aplica l'algorisme Merge Sort al vector, 
// que té un cost total de O(N * log(N)) per ordenar els elements.
void call_registry::dump(vector<phone>& V) const throw(error){
    V.clear();
    dump_recursiu(_arrel, V);
   
    merge_sort(V, 0, V.size() - 1);
    if(V.size() > 1){
        for(unsigned int i = 0; i < V.size() - 1; ++i){
            if(V[i].nom() == V[i+1].nom()) throw error(ErrNomRepetit);    
        }
    }
}

// Cost: O(N), on N és el nombre de nodes a l'arbre.
// La complexitat de temps per recopilar els elements és lineal respecte al nombre de nodes a l'arbre (O(N)).
// Després, s'aplica Merge Sort al vector recopilat, afegint un cost addicional de O(N * log(N)),
// la qual cosa resulta en un cost total de O(N) + O(N * log(N)) = O(N * log(N)).
void call_registry::dump_recursiu(node* n, vector<phone>& V){
    if(n != nullptr){
        dump_recursiu(n->_esq, V);
        if(n->_p.nom() != "") V.push_back(n->_p);  
        dump_recursiu(n->_dret, V);
           
    }
}

/* Gestió d'errors. */
static const int  ErrNumeroInexistent = 21;
static const int  ErrNomRepetit       = 22;

