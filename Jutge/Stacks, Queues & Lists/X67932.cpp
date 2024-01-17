#include <iostream>
#include "llista.hpp"

using namespace std;

void Llista::fusiona_suma(Llista &l2, nat n) {
    
    node* p1 = _prim->seg;
    node* p2 = l2._prim->seg;
    while(p1->seg != _prim){
    	p1 = p1->seg;
    }
    p1->seg = nullptr;
    p1 = _prim->seg;
    while(p2->seg != l2._prim){
    	p2 = p2->seg;
    }
    p2->seg = nullptr;
    p2 = l2._prim->seg;
    _prim = p1;
    l2._prim = p2;
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
    
    l2._prim = new node;
    l2._prim->seg = l2._prim;
	l2._prim->ant = l2._prim;
	
    int cntinicial = 0;
    node* aux1 = _prim;
    while(aux1 != nullptr){
		cntinicial += aux1->info;
        aux1 = aux1->seg;
    }
    node *aux2 = _prim;
    _prim = new node;
    _prim->seg = aux2;
    _prim->info = cntinicial;
    _long += 1;
    aux2 = _prim;
    _prim = new node;
    _prim->seg = aux2;
    
    aux1 = _prim;
  	aux2 = _prim;
    while(aux1->seg != nullptr){
        aux1 = aux1->seg;
        aux1->ant = aux2;
        aux2 = aux2->seg;
    }
    aux1->seg = _prim;
    _prim->ant = aux1;
}
