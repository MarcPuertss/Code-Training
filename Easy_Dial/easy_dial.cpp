#include "easy_dial.hpp"

//Cost: O(N) , on N és la quantitat de telèfons al registre.
//Primer, es realitza una ordenació dels telèfons utilitzant l'algorisme Merge Sort
// amb un cost de O(N * log(N)), on N és la quantitat de telèfons al registre.
// Després, es recorre el vector ordenat i s'insereix cada telèfon a l'arbre TST de l'objecte easy_dial.
// Es calcula també la freqüència total dels telèfons i s'actualitza la variable _freqP
easy_dial::easy_dial(const call_registry& R) throw(error) {
    _arrel = nullptr;
    _pre_indefinit = true;
    _sin_telefons = true;
    vector<phone> v;
    max_freq = nullptr;
    _guard = "";
    string s = "";
    s_node* snode = nullptr;
    _freqP = 0; 
    R.dump(v);
    merge_sort(v,0,v.size()-1);
    for (unsigned int i = 0; i < v.size(); ++i) {

        snode = new s_node;
        snode->s_p = v[i];
        s = v[i].nom() + phone::ENDPREF;
        bool activar = false; 
        if(i==0){
            activar = true;
            max_freq = new s_node;
            max_freq->s_p = snode->s_p;
        }
        else activar = false;
        _arrel = insereix(_arrel,snode, 0, s, v[i], activar);
        _freqP += v[i].frequencia();
    }
}

// Cost: O(N * log(N)), on N és el nombre d'elements al vector V.
// Implementa l'algorisme Merge Sort, que divideix el vector en meitats,
// ordena cada meitat de manera recursiva i després combina (fusiona) les meitats ordenades.
// La complexitat de temps és O(N * log(N)) degut a les divisions logarítmiques del vector.
void easy_dial::merge(vector<phone>& V, int esq, int mig, int dret) throw(error){
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
        if (v_esq[i] > v_dret[j]) {
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
void easy_dial::merge_sort(vector<phone>& V, int esq, int dret) {
    if (esq < dret) {
        int mig = esq + (dret - esq) / 2;
        merge_sort(V, esq, mig);
        merge_sort(V, mig + 1, dret);
        merge(V, esq, mig, dret);
    }
}

//Cost: O(N), on N és la longitud del prefix.
// Aquesta funció insereix un node a l'arbre TST de l'objecte easy_dial segons el prefix proporcionat. 
// Utilitza una aproximació recursiva per navegar a través de l'arbre fins a la posició correcta, 
// mantenint l'ordre alfabètic dels caràcters i gestionant els caràcters especials.
// S'ha de recórrer l'arbre des de la arrel fins a la posició correcta, i aquesta recorreguda té un cost lineal. 
easy_dial::node_tst* easy_dial::insereix(node_tst* n,s_node* snode, unsigned int i, const string& s, const phone& p, bool& activar) {
    if(i<s.size()){
        if (n == nullptr) {
            n = new node_tst;
            n->_c = s[i];
            n->_interes = false;
            n->_esq = n->_cen = n->_dret = nullptr;
            n->_apuntar = nullptr;
        } 
        if (s[i] < n->_c) n->_esq = insereix(n->_esq,snode, i, s, p, activar);

        else if (s[i] > n->_c) n->_dret = insereix(n->_dret,snode, i, s, p, activar); 
        
        else if (s[i] == phone::ENDPREF) {
            n->_apuntar = snode;
            if(activar) n->_interes = true;
            else n->_interes = false;   
        }   
        else {
            if(n->_apuntar == nullptr and activar==false){
                n->_apuntar = snode;
                activar = true;  
            }
            n->_cen = insereix(n->_cen, snode, i + 1, s, p, activar);   
        }
    }   
    return n;
}

// Cost: O(N), on N és la quantitat de nodes a l'arbre TST de l'objecte 
// Aquest constructor crea una còpia d'un objecte easy_dial. 
// Utilitza la funció auxiliar copiar_trie per realitzar una còpia de tot l'arbre TST.
//  Crea una còpia de tot l'arbre TST, i aquesta operació té un cost lineal.
easy_dial::easy_dial(const easy_dial& D) throw(error){
    
    _arrel = copiar_trie(D._arrel);
    _guard = D._guard;
    max_freq = D.max_freq;
    _pre_indefinit = D._pre_indefinit;
    _sin_telefons = D._sin_telefons;
    _freqP = D._freqP;
}

// Cost: O(N), on N és el nombre de nodes al subarbre TST de l'objecte
// Aquesta funció crea una còpia d'un subarbre TST utilitzant una aproximació recursiva.
// Cada node i les seves dades són duplicats en la nova estructura.
// Té un cost lineal O(N) ja que cada node i les seves dades són duplicats.
void easy_dial::copiar_snode(node_tst*& nou, const node_tst* copia){
    
    if(nou == nullptr) return;
    
    copiar_snode(nou->_esq, copia->_esq);
    copiar_snode(nou->_cen, copia->_cen);
    copiar_snode(nou->_dret, copia->_dret);
    if(nou->_c == '\0'){ 
        s_node* nounode =  new s_node;
        nou->_apuntar = nounode;
        nou->_apuntar->s_p = copia->_apuntar->s_p;
    }
    nou->_apuntar = copia->_apuntar;
    nou->_interes = copia->_interes;

}

// Cost: O(N), on N és la quantitat de nodes a l'arbre TST de l'objecte 
// Aquesta funció crea una còpia d'un subarbre TST utilitzant una aproximació recursiva. 
// Cada node i les seves dades són duplicats en la nova estructura.
// Té un cost lineal O(N) ja que cada node i les seves dades són duplicats.
easy_dial::node_tst* easy_dial::copiar_trie(const node_tst* n){
    
    if(n == nullptr) return nullptr;
    node_tst* nounode = new node_tst;
    nounode->_c = n->_c;
    nounode->_interes = n->_interes;
    nounode->_esq = copiar_trie(n->_esq);
    nounode->_cen = copiar_trie(n->_cen);
    nounode->_dret = copiar_trie(n->_dret);
    return nounode;
}

// Cost: O(N + M), on N és la quantitat de nodes a l'arbre TST actual i M és la quantitat de nodes a l'arbre TST de D.
// Primer, es destrueix l'arbre TST actual, després es copia l'arbre de l'objecte a assignar utilitzant la funció copiar_trie.
easy_dial& easy_dial::operator=(const easy_dial& D) throw(error){
    if (this != &D) {
        destruir_trie(_arrel);
        _arrel = copiar_trie(D._arrel);
        copiar_snode(_arrel, D._arrel);
        _guard = D._guard;
        max_freq = D.max_freq;
        _pre_indefinit = D._pre_indefinit;
        _sin_telefons = D._sin_telefons;
        _freqP = D._freqP;
    }
    return *this;
}

// Cost: O(N + M), on N és la quantitat de nodes a l'arbre TST actual i M és la quantitat de nodes a l'arbre TST de D.
// Aquesta funció elimina tots els nodes de l'arbre TST utilitzant una aproximació recursiva, alliberant la memòria.
void easy_dial:: destruir_trie(node_tst* n){
  if (n != nullptr) {
        destruir_trie(n->_esq);
        destruir_trie(n->_cen);
        destruir_trie(n->_dret);

        if (n->_c == '\0') {
            if (n->_apuntar != nullptr) {
                delete n->_apuntar;
                n->_apuntar = nullptr;
            }
        }

        delete n;
        n = nullptr;  // Actualiza el puntero después de eliminar el nodo
    }
}

// Cost: O(N), on N és la quantitat de nodes a l'arbre TST.
// Aquest destructor allibera la memòria associada a l'arbre TST i a altres elements de l'objecte.
easy_dial::~easy_dial() throw(){   
    if(max_freq!=nullptr){
        delete max_freq;
    }destruir_trie(_arrel);
    _arrel = nullptr;
    max_freq = nullptr;
}

// Cost: O(1).
// Aquesta funció només realitza operacions bàsiques com a establir variables de control, 
// i la seva complexitat és constant
string easy_dial::inici() throw(){
    _pre_indefinit = false;
    _guard = "";
    if(_arrel != nullptr and max_freq != nullptr){
        _sin_telefons = false;
        return max_freq->s_p.nom();
    }
    else return "";
}

// Cost: O(log(27)), on 26 es el nombre total de caracters en el alfabet més el '\0'.
// La funció busca el següent telèfon en funció del prefix actual. La recerca es realitza en l'arbre TST, i la complexitat de temps és O(log(27))
// ja que el nombre total de caràcters en l'alfabet més el '\0' és 27.
string easy_dial::seguent(char c) throw(error){
    if (_pre_indefinit == true) throw error(ErrPrefixIndef);
    else if(_sin_telefons==true){
        _pre_indefinit = true;
        throw error(ErrPrefixIndef);
    }
    if(_arrel!=nullptr){
        _guard.push_back(c);
        node_tst* node_busca = buscar_node_prefix(_arrel, 0, _guard, c);
        if (node_busca != nullptr and node_busca->_apuntar!=nullptr) {
            _sin_telefons = false;
            if(c=='\0' and node_busca->_interes==true){
                 _sin_telefons = true;
                return ""; 
            }
            else return node_busca->_apuntar->s_p.nom();
        } 
        else if(node_busca==nullptr and _pre_indefinit==false) {
            _sin_telefons = true;
            return "";
        }    
    }
    else {
        _pre_indefinit = true;
        _sin_telefons = true;
        _guard = "";
        throw error(ErrPrefixIndef);
    }
    return "";
}

//Cost: O(L), on L és la longitud del prefix proporcionat.
// Aquesta funció busca el node corresponent a la posició actual del prefix proporcionat. Utilitza una aproximació recursiva 
// i té una complexitat de temps O(L).
typename easy_dial::node_tst* easy_dial::buscar_node_prefix(node_tst* n, unsigned int i, const string& s, char actual)  {
    if (n == nullptr)return nullptr;
    if (s[i] < n->_c) return buscar_node_prefix(n->_esq, i, s, actual);
    else if (s[i] > n->_c)  return buscar_node_prefix(n->_dret, i, s, actual);
    else {
        if (n->_apuntar!=nullptr and (i==s.size()-1) and actual == n->_c) return n;
        else return buscar_node_prefix(n->_cen, i + 1, s, actual);
    }
}

// Cost: O(log(27)), on 26 es el nombre total de caracters en el alfabet més el '\0'.
// Aquesta funció retorna el telèfon anterior en funció del prefix actual. Utilitza la funció buscar_node_prefix,
// per trobar el node corresponent, i la complexitat de temps és O(log(27)).
string easy_dial::anterior() throw(error) {
    if (_pre_indefinit==true) throw error(ErrPrefixIndef);
    if (_guard.empty()){
        _sin_telefons = true;
        _pre_indefinit = true;
        throw error(ErrNoHiHaAnterior);
    }
    _guard.pop_back();
    if(_guard=="" and max_freq != nullptr) {
        _sin_telefons = false;
        return max_freq->s_p.nom();
    }
    else{
        node_tst* node_busca = buscar_node_prefix(_arrel, 0, _guard, _guard.back());
        if (node_busca != nullptr and node_busca->_apuntar!=nullptr) {
            _sin_telefons = false;
            return node_busca->_apuntar->s_p.nom();
        } 
        else if(node_busca==nullptr and _pre_indefinit==false) {
            _sin_telefons = true;
            return "";
        }  
        else {
            _pre_indefinit = true;
            _sin_telefons = true;
            _guard = "";
            throw error(ErrPrefixIndef);
        }
    }
}

// Cost: O(log(27)), on 26 es el nombre total de caracters en el alfabet més el '\0'.
// Aquesta funció retorna el nombre de telèfon associat al prefix actual. Utilitza la funció obtenir_num_telefon,
// per trobar el node corresponent, i la complexitat de temps és O(log(27)).
nat easy_dial::num_telf() const throw(error) {
    if(_pre_indefinit==true and _sin_telefons==true) throw error(ErrPrefixIndef);
    else if(_sin_telefons==true) throw error(ErrNoExisteixTelefon);
    else if(_guard=="" and _arrel!=nullptr and max_freq != nullptr) return max_freq->s_p.numero();
    else if (_arrel!=nullptr) return obtenir_num_telefon(_arrel, 0, _guard, _guard.back());
    else throw error(ErrNoExisteixTelefon); 
}

// Cost: O(log(27)), on 26 es el nombre total de caracters en el alfabet més el '\0'.
// Aquesta funció retorna el nombre de telèfon associat al node TST corresponent al prefix actual. 
// Utilitza una aproximació recursiva i té una complexitat de temps O(log(27)).
nat easy_dial::obtenir_num_telefon(node_tst* n, unsigned int i, const string& s, char actual) throw(error) {

    if (n == nullptr) throw error(ErrNoExisteixTelefon);
    if (s[i] < n->_c) return obtenir_num_telefon(n->_esq, i, s, actual);
    else if (s[i] > n->_c) return obtenir_num_telefon(n->_dret, i, s, actual);
    else {
         if (n->_apuntar!=nullptr and (i==s.size()-1) and actual == n->_c) return n->_apuntar->s_p.numero();
        else return obtenir_num_telefon(n->_cen, i + 1, s, actual);
    }
}

// Cost: O(L), on L és la longitud del prefix proporcionat.
// Aquesta funció busca el node que comença amb el prefix proporcionat. 
// Utilitza una aproximació recursiva i té una complexitat de temps
// O(L).
typename easy_dial::node_tst* easy_dial::buscar_node_comencem(node_tst* n, unsigned int i, const string& s)  {
    if (n == nullptr) return nullptr;
    if (s[i] < n->_c) return buscar_node_comencem(n->_esq, i, s);
    else if (s[i] > n->_c) return buscar_node_comencem(n->_dret, i, s);
    else {
        if (i == s.size()-1) return n->_cen;
        else return buscar_node_comencem(n->_cen, i + 1, s);
    }
}

// Cost: O(L + K), on L és la longitud del prefix i K és la quantitat de nodes al subarbre corresponent al prefix.
// Aquesta funció recopila els noms dels telèfons que comencen amb el prefix proporcionat. 
// Utilitza la funció recopilar_nombres per recórrer l'arbre TST i recopilar els noms. La complexitat de temps és O(L + K)
void easy_dial::comencen(const string& pref, vector<string>& result) const throw(error) {
    
    node_tst* nodo_pref;
    if(pref=="") nodo_pref = _arrel;
    else nodo_pref = buscar_node_comencem(_arrel, 0, pref);
    if (nodo_pref != nullptr) {;
        recopilar_nombres(nodo_pref, pref, result);
    }
    return;
}
 
// Cost: O(N), on N és el nombre total de nodes a l'arbre TST.
// Aquesta funció recopila els noms dels telèfons mitjançant una aproximació recursiva per recórrer l'arbre TST.
// Els noms s'afegeixen al vector de resultats, i la complexitat de temps és O(N)
void easy_dial::recopilar_nombres(node_tst* n, const string& pref_actual, vector<string>& result) {
    if (n == nullptr) {
        return;
    }    
    if(n!=nullptr and n->_apuntar!=nullptr and n->_c=='\0') result.push_back(n->_apuntar->s_p.nom());    
    recopilar_nombres(n->_esq, pref_actual, result);
    recopilar_nombres(n->_cen, pref_actual, result);
    recopilar_nombres(n->_dret, pref_actual, result);
}

// Cost: O(N), on N és la quantitat total de nodes a l'arbre TST.
// Aquesta funció calcula la longitud mitjana dels noms de telèfon a l'arbre TST, tenint en compte les freqüències dels telèfons. 
// Utilitza la funció calcul_longitud_rec per realitzar aquest càlcul,
// i la complexitat de temps és O(N).
double easy_dial::longitud_mitjana() const throw(){
    double freq_res = 0;
    calcul_longitud_rec(_arrel, 1, _freqP, freq_res);
    return freq_res;
} 

// Cost: O(N), on N és la quantitat total de nodes a l'arbre TST.
// Aquesta funció és una funció auxiliar que calcula recursivament la longitud mitjana dels noms de telèfon a l'arbre TST,
// prenent en compte les freqüències dels telèfons. Utilitza una aproximació recursiva
// per recórrer l'arbre, i la complexitat de temps és O(N)
void easy_dial::calcul_longitud_rec(node_tst *n, nat f, nat freq_total, double& freq_res)  {
    if (n != nullptr) {   
        calcul_longitud_rec(n->_esq, f , freq_total, freq_res);
        calcul_longitud_rec(n->_cen, f + 1, freq_total, freq_res);
        calcul_longitud_rec(n->_dret, f , freq_total, freq_res);
        double frec_phone;
        if(n->_apuntar!=nullptr) frec_phone = n->_apuntar->s_p.frequencia();
        else frec_phone = 0.0;
        if(n->_interes==false)freq_res += (frec_phone /freq_total) * f;
    }
    return;
}
