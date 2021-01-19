#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int x;
	cin >> x;
	for (int i = 1; i <= n; ++i) {
		int sum = 0;
		int m;
		cin >> m;
		while (m != x) {
			sum += m;
			cin >> m;
		}
		string s;
		getline(cin, s);
		cout << "La suma de la secuencia " << i << " es " << sum << endl;
	}
}
