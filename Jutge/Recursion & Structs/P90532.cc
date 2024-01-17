#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Provincia {
         string nom;
         string capital;
         int habitants;
         int area;
         double pib;
};
struct Pais {
         string nom;
         string capital;
         vector<Provincia> provs;
};
typedef vector<Pais> Paisos;

double pib(const Paisos& p, char c, double d) {
    int n = p.size();
    double suma = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i].nom[0] == c) {
            int provsize = p[i].provs.size();
            for (int j = 0; j < provsize; ++j) {
                double hab = p[i].provs[j].habitants;
                double area = p[i].provs[j].area;
                if (hab/area > d) suma += p[i].provs[j].pib;
            }
        }
    }
    return suma;
}
