#include <iostream>
#include <vector>
#include "Estudiant.hh"
using namespace std;

int main() {
	int m, n, s;
	cin >> m >> n >> s;
	vector<int> posicio(s);
	for (int i = 0; i < s; ++i) cin >> posicio[i];
	vector<double> grades(n);
	vector<Estudiant> v(m);
	for (int i = 0; i < m; ++i) {
		int id;
		cin >> id;
		for (int j = 0; j < n; ++j) cin >> grades[j];
		double sum = 0;
		for (int j = 0; j < s; ++j) sum += grades[posicio[j] - 1];
		sum /= s;
		v[i] = Estudiant(id);
		v[i].afegir_nota(sum);
		v[i].escriure();
	}
}
