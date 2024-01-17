#include "llista.hpp"
using namespace std;

Llista::Llista(const vector<int> &v){
	_long = v.size();
	_prim = nullptr;
	_prim = new node;
	_prim->seg = _prim;	
	_prim->ant = _prim;
	if(_long == 0) return;
	node *fantasma = _prim;
	for(int i = 0; i < _long; ++i){
  		fantasma->seg = new node;
  		fantasma->seg->info = v[i];
  		fantasma->seg->seg = nullptr;
  		fantasma->seg->ant = fantasma;
  		fantasma = fantasma->seg;
  	}
  	fantasma->seg = _prim;
  	fantasma->seg->ant = fantasma;
}
