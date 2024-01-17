#include <iostream>
#include "cua.hpp"
using namespace std;

cua::cua(const vector<int> &v){
	_long = v.size();
	_ult = nullptr;
	if(_long == 0) return;
	_ult = new node;
	_ult->info = v[0];
	_ult->seg = nullptr;
	node* nounode= _ult;
	for(int i = 1; i < _long; ++i){
		nounode->seg = new node;
		nounode->seg->info = v[i];
		nounode->seg->seg = nullptr;
		nounode = nounode->seg;
	}
	nounode->seg = _ult;
	_ult = nounode;
}
