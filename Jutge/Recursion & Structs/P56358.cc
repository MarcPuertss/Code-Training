#include <iostream>
using namespace std;

struct Temps {
    int hora, minut, segon;
};

void un_segon(const Temps& t, Temps& t1, Temps& t2) {	
	t1.hora = t.hora;
	t1.minut = t.minut;
	t1.segon = t.segon;
	t2.hora = t.hora;
	t2.minut = t.minut;
	t2.segon = t.segon;
	
	t1.segon = t.segon + 1;
	
	if (t1.segon >= 60) {
		t1.segon -= 60;
		t1.minut += 1;
	}
	
	if (t1.minut >= 60) {
		t1.minut -= 60;
		t1.hora += 1;
	}
	
	if (t1.hora >= 24) t1.hora -= 24;
	
	cout << t1.hora << " " << t1.minut << " " << t1.segon << endl;
	
	t2.segon = t.segon - 1;
	
	if (t2.segon < 0) {
		t2.segon += 60;
		t2.minut -= 1;
	}
	
	if (t2.minut < 0) {
		t2.minut += 60;
		t2.hora = t2.hora - 1;
	}
	
	if (t2.hora < 0) t2.hora += 24;
	
	cout << t2.hora << " " << t2.minut << " " << t2.segon << endl;
}

int main () {
	Temps t, t1, t2;
	int hora, minut, segon;
	
	while (cin >> hora) {
		cin >> minut >> segon;
		t.hora = hora;
		t.minut = minut;
		t.segon = segon;
		
		un_segon (t, t1, t2);
	}	
}
