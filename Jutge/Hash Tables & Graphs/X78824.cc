#include <vector>
using namespace std;
typedef unsigned int nat;
class graf {
// Graf dirigit i no etiquetat.
// Les arestes es guarden en una matriu d’adjacència.
public:
// Constructora per defecte. Crea un graf buit.
graf ();
// Destructora
~graf ();
// Llegeix les dades del graf del canal d’entrada
void llegeix ();
bool hi_ha_cami (nat ini , nat fi ) const;
// Pre: ini i fi són vèrtexs del graf (són menors que n)// Post: Retorna un booleà indicant si hi ha camı́ per anar d’ini a fi
private:
nat n; // Nombre de vèrtexs
nat m; // Nombre d’arestes
vector <vector<bool> > a; // Matriu d’adjacència
// Aquı́ va l’especificació dels mètodes privats addicionals

//PRE :cert
//post: retorna cert si i nomes si existeix cami entre els dos vertex
//cost
bool cami_aux (nat ini, nat fi, nat cont) const;



};
// Aquı́ va la implementació del mètode públic hi ha cami i privats addicionals

bool graf::hi_ha_cami(nat ini,nat fi) const{

	if (ini == fi) return true;

	return cami_aux(ini,fi,0);

}

bool graf::cami_aux(nat ini, nat fi,nat cont) const{
	bool aux = false;
	++cont;
	
	if (a[ini][fi]) aux = true;
	
	else {
	
		for (nat i = 0; i < n and cont < m; ++i) {
		
			if (a[ini][i] and not aux) aux = cami_aux(i,fi,cont);
				 		
		}
	}
	
	return aux;

}
