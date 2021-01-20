#include <iostream>
#include <vector>
#include <algorithm>
#include "Cjt_estudiants.hh"
using namespace std;

int main() {
	Cjt_estudiants a;
	a.llegir();
	Cjt_estudiants b;
	b.llegir();
	for (int i = 0; i < a.mida(); ++i) {
		Estudiant x = a.consultar_iessim(i + 1);
		Estudiant y = b.consultar_iessim(i + 1);
		if (x.te_nota()) {
			if (y.te_nota() and (x.consultar_nota() < y.consultar_nota())) {
				a.modificar_iessim(i + 1, y);
			}
		} else if (y.te_nota()) { // x no te nota
			a.modificar_iessim(i + 1, y);
		}
	}
	a.escriure();
}
