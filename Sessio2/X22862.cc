#include <iostream>
#include <vector>
#include <algorithm>
#include "Cjt_estudiants.hh"
using namespace std;

double redondear(double r) {  
  return int(10.*(r + 0.05)) / 10.0;
} 

int main() {
	Cjt_estudiants a;
	a.llegir();
	int n;
	cin >> n; 
	while (n != -6) {
		int id, mida;
		double nota;
		Estudiant est;
		if (n == -1) {
			cin >> id >> nota;
			est = Estudiant(id);
			if (nota >= 0 and nota <= 10) est.afegir_nota(nota);
			if (a.existeix_estudiant(id)) cout << "el estudiante " << id << " ya estaba" << endl << endl;
			else if (a.mida() == 5) cout << "el conjunto esta lleno" << endl << endl;
			else a.afegir_estudiant(est);
		} else if (n == -2) {
			cin >> id;
			if (a.existeix_estudiant(id)) {
				est = a.consultar_estudiant(id);
				if (est.te_nota()) cout << "el estudiante " << id << " tiene nota " << est.consultar_nota() << endl;
				else cout << "el estudiante " << id << " no tiene nota" << endl;
			} else cout << "el estudiante " << id << " no esta" << endl;
			cout << endl;
		} else if (n == -3) {
			cin >> id >> nota;
			if (a.existeix_estudiant(id)) {
				est = a.consultar_estudiant(id);
				if (est.te_nota()) est.modificar_nota(nota);
				else est.afegir_nota(nota);
				a.modificar_estudiant(est);
			} else cout << "el estudiante " << id << " no esta" << endl << endl;
		} else if (n == -4) {
			mida = a.mida();
			for (int i = 1; i <= mida; ++i) {
				est = a.consultar_iessim(i);
				if (est.te_nota()) {
					est.modificar_nota(redondear(est.consultar_nota()));
					a.modificar_iessim(i, est);
				}
			}
		} else if (n == -5) {
			a.escriure();
			cout << endl;
		}
		cin >> n;
	}
}
