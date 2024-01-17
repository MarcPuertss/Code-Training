#include "llista.hpp"
using namespace std;

Llista::Llista(const vector<int> &v){
	_long = v.size();
	_prim = nullptr;
	_prim = new node;
	if(_long == 0) return;
	node *fantasma = new node;
	fantasma = _prim;
	fantasma->seg = _prim;	
	_prim->seg = nullptr;
	for(int i = 0; i < _long; ++i){
  		fantasma->seg = new node;
  		fantasma->seg->info = v[i];
  		fantasma->seg->seg = nullptr;
  		fantasma = fantasma->seg;
  	}
}
