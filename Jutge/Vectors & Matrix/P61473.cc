#include <iostream>
#include <vector>

using namespace std; 

typedef vector < vector<int> > Matriu;

bool es_simetrica(const Matriu& m){
	
 bool t = true; 
	
 for(unsigned int i = 0; i < m.size() and t; i++){
  
  for(unsigned int j = 0; j < m.size() and t; j++){
   if(m[i][j] != m[j][i]) t = false; 
  }
  
 }
	
 return t; 
	
}
