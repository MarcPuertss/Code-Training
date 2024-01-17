 #include <vector>
 using namespace std;
 typedef unsigned int nat;
 
 class graf {
   // Graf dirigit i no etiquetat.
   // Les arestes es guarden en llistes d’adjacència (vector amb els successors).
   public:
     // Constructora per defecte. Crea un graf buit.
     graf();
 
     // Destructora
     ~graf();
 
     // Llegeix les dades del graf del canal d’entrada
     void llegeix();
 
     bool hi_ha_cami(nat ini, nat fi) const;
     // Pre: ini i fi són vèrtexs del graf (són menors que n)
     // Post: Retorna un booleà indicant si hi ha camí per anar d’ini a fi
 
   private:
     nat n; // Nombre de vèrtexs
     nat m; // Nombre d’arestes
     vector<vector<nat> > a; // Vectors amb els successors de cada vèrtex
 
     // Aquí va l’especificació dels mètodes privats addicionals
     bool cami_aux (nat ini, nat fi, nat cont) const;
 };
 
 // Aquí va la implementació del mètode públic hi_ha_cami i privats addicionals
 
	bool graf::hi_ha_cami(nat ini,nat fi) const{

	if (ini == fi) return true;

	return cami_aux(ini,fi,0);

}

bool graf::cami_aux(nat ini, nat fi,nat cont) const{
	bool aux = false;
	++cont;
	
	for (nat i = 0; i< a[ini].size() and cont < n*(n - 1) and not aux; ++i) {
	
		if (a[ini][i] == fi) aux = true; 
		
		else aux = cami_aux(a[ini][i],fi,cont);

	}
	
	return aux;
	
}
