#include "llista.hpp"
using namespace std;

void Llista::separa(Llista &l2){
	node *p1 = _prim;
	node *p2 = l2._prim;
	node *previ = _prim;
	int cnt = 0;
	if(_long == 0) return;
	while(p1 != nullptr){	
		if(cnt % 2 != 0){
			if(l2._long <= 0){
				l2._prim = new node;
				p2 = l2._prim;
			}
			else{
				p2->seg = new node;
				p2 = p2->seg;
			}
			p2->info = p1->info;
			p2->seg = nullptr;
			l2._long++;
			node *aux = p1;
			previ->seg = p1->seg;
			p1 = p1->seg;
			delete aux;
			--_long;
			++cnt;
		}
		else{
			p1 = p1->seg; 
			if(cnt != 0) previ = previ->seg;
			++cnt;
			
		}
	}			
}
