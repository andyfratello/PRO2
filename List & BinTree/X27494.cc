#include <list> 
#include <iostream>
using namespace std;

void recalculate(list<int>& l, int& min, int& max) {
	if (not l.empty()) {
		max = *l.begin(); 	// valor 1a posicio
		min = *l.begin();
		list<int>::const_iterator it;
		for (it = l.begin(); it != l.end(); ++it) {
			if (max < (*it)) max = (*it);
			if (min > (*it)) min = (*it);
		}
	}
}

void erase_element(list<int>& l, int& n, double& total) {
	if (not l.empty()) {
		list<int>::iterator it = l.begin();
		bool esborrat = false;
		while (not esborrat and it != l.end()) {
			if ((*it) == n) {
				it = l.erase(it);
				total -= n;
				esborrat = true;
			} else ++it;
		}
	}
}

int main() {
	int codi, n;
	int max = 0;
	int min = 0;
	double total = 0;
	list<int> l;
	cin >> codi >> n;
	while (codi != 0 and n != 0) {
		if (codi == -1) {
			if (l.empty()) min = max = n;
			else {
				if (max < n) max = n;
				if (min > n) min = n;
			}
			l.push_back(n);
			total += n;
		} else if (codi == -2) {
			erase_element(l, n, total);
			if (max == n or min == n) recalculate(l, min, max);
		}
		if (not l.empty()) cout << min << ' ' << max << ' ' << total/l.size() << endl; 
		else cout << 0 << endl;
		cin >> codi >> n;
	}
}
