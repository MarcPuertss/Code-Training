#include "llista.hpp"
using namespace std;

Llista::Llista(const vector<int> &v){
     // Pre: True
     // Post: El p.i. conté els elements de v amb el mateix ordre.
     _long = v.size();
	 _prim = nullptr;
	 if(_long == 0) return;
  	 _prim = new node;
  	 _prim->info = v[0];
  	 _prim->seg = nullptr;
  	 node* nounode = _prim;
  	 for(int i = 1; i < _long; ++i){
  		nounode->seg = new node;
  		nounode->seg->info = v[i];
  		nounode->seg->seg = nullptr;
  		nounode = nounode->seg;
  	}
}
