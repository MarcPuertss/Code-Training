#include <iostream>
#include <vector>
#include <string>

using namespace std; 

typedef vector < vector <int> > Matriu ;

void fila(const Matriu& v, int a){
 a = a - 1; 
 
	for(unsigned int i = 0; i < v[0].size(); i++){
	cout << v[a][i];
  
		if(i != v[0].size() - 1){
	    cout << " "; 
   		}  
 	}
 	cout << endl; 
}

void columna(const Matriu& v, int a){
 a = a - 1;
	
	for(unsigned int i = 0; i < v.size(); i++){
	cout << v[i][a]; 
  
		if(i != v.size() - 1){
	    cout << " "; 
  		}
 	}
    cout << endl; 
}

int main(){
	
 int x, y, a, b; 
 cin >> x >> y; 
	
 Matriu v(x, vector <int> (y));

	for(int i = 0; i < x; i++){
	  for(int j = 0; j < y; j++) cin >> v[i][j];
 	}
	
 string req;
	
	while(cin >> req){
	  if(req == "fila"){
   	  cin >> a; 
   	  cout << "fila " << a << ": ";
	  fila(v, a);
	  }
	  
	  else if(req == "columna"){
   	  cin >> a; 
  	  cout << "columna " << a << ": ";
   	  columna(v, a); 
   	  }
   	  
   	  else{
   	  cin >> a >> b; 
   	  cout << "element " << a << " " << b << ": " << v[a-1][b-1] << endl; 
  	  }
 }
		
}
