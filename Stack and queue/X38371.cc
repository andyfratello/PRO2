#include <iostream>
#include <queue>
using namespace std;

void recalcula(queue<int> q, int& max, int& min) {
	max = -1000, min = 1000;
	while (!q.empty()) {
		if (max < q.front()) max = q.front();
		if (min > q.front()) min = q.front();
		q.pop();
	}
}

int main() {
	queue<int> q;
	int n, max = -1000, min = 1000;
	double sum = 0;
	cin >> n;
	while (n >= -1001 and n <= 1000) {
		if (n != -1001) {
			q.push(n);
			if (n > max) max = n;
			if (n < min) min = n;
			sum += n;
		} else if (not q.empty()) { // n == -1001
			int front_borrat = q.front(); 
			q.pop();
			sum -= front_borrat;
			if (front_borrat == max or front_borrat == min) recalcula(q, max, min);
		}
		if (q.empty()) {
			cout << 0 << endl;
			max = -1000;
			min = 1000;
		} else cout << "min " << min << "; max " << max << "; media " << sum/q.size() << endl;
		cin >> n;
	}
}
