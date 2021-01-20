#include <iostream>
#include <vector>
#include <algorithm>
#include "Estudiant.hh"
using namespace std;

bool comp (const Estudiant& a, const Estudiant& b) {
	if (a.consultar_nota() != b.consultar_nota()) return a.consultar_nota() > b.consultar_nota();
	return a.consultar_DNI() < b.consultar_DNI();
}

int main() {
	int m, n, s;
	cin >> m >> n >> s;
	vector<int> pos(s);
	for (int i = 0; i < s; ++i) cin >> pos[i];
	vector<Estudiant> v(m);
	vector<double> grades(n);
	for (int i = 0; i < m; ++i) {
		int id;
		cin >> id;
		for (int j = 0; j < n; ++j) cin >> grades[j];
		double sum = 0;
		for (int j = 0; j < s; ++j) sum += grades[pos[j] - 1];
		sum /= s;
		v[i] = Estudiant(id);
		v[i].afegir_nota(sum);
	}
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < m; ++i) v[i].escriure();
}
