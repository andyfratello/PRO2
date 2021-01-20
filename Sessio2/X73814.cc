#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<Estudiant> v(n);
	for (int i = 0; i < n; ++i) v[i].llegir();
	vector<Estudiant> simplified;
	Estudiant x = v[0];
	for (int i = 1; i < n; ++i) {
		Estudiant y = v[i];
		if (x.consultar_DNI() == y.consultar_DNI()) {
			if (x.te_nota() and y.te_nota()) {
				if (x.consultar_nota() < y.consultar_nota()) {
					x.modificar_nota(y.consultar_nota());
				}
			} else if (y.te_nota()) {
				x.afegir_nota(y.consultar_nota());
			}
		} else {
			simplified.push_back(x);
			x = y;
		}
	}
	simplified.push_back(x);
	for (int i = 0; i < simplified.size(); ++i) simplified[i].escriure();
}
