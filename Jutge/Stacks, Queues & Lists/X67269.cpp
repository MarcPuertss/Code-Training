#include <iostream>
#include "llista.hpp"

using namespace std;

void Llista::fusiona_suma(Llista &l2, nat n) {
    
    node* p1 = _prim;
    node* p2 = l2._prim;
    int cnt = n-1;
    bool repeticio = true;
    while (l2._long != 0 or (l2._long == 0 and (p1 != nullptr and p1->seg != nullptr))) {
        if (cnt <= 0) {
            repeticio = !repeticio;
            cnt = n;
        }
        --cnt;
        if(p1 == nullptr){
            _prim = new node;
            p1 = _prim;
            p1->info = p2->info;
            p1->seg = nullptr;
            ++_long;
            node* aux = p2;
            p2 = p2->seg;
            delete aux;
            --l2._long;
            if (p2 == nullptr) l2._prim = nullptr;
            else l2._prim = p2;
        }
        else if(p1->seg == nullptr){
            p1->seg = new node;
            p1->seg->info = p2->info;
            p1->seg->seg = nullptr;
            p1 = p1->seg;
            ++_long;
            node* aux = p2;
            p2 = p2->seg;
            delete aux;
            --l2._long;
            if (p2 == nullptr) l2._prim = nullptr;
            else l2._prim = p2;
        }
        else if(repeticio or l2._long == 0){
            p1 = p1->seg;
        }
        else if(!repeticio){
            node* sig = p1->seg;
            p1->seg = new node;
            p1->seg->info = p2->info;
            p1->seg->seg = sig;
            p1 = p1->seg;
            ++_long;
            node* aux = p2;
            p2 = p2->seg;
            delete aux;
            --l2._long;
            if (p2 == nullptr) l2._prim = nullptr;
            else l2._prim = p2;
        }
    }
    
    int cntinicial = 0;
    node* aux = _prim;
    while(aux != nullptr){
		cntinicial += aux->info;
        aux = aux->seg;
    }
    aux = _prim;
    _prim = new node;
    _prim->seg = aux;
    _prim->info = cntinicial;
    _long += 1;
}
