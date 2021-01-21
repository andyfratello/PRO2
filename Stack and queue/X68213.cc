#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector<stack<string> > v(n);
    cin >> x;
    while (x != -4) {
        int category;
        if (x == -1) {
        	string name;
        	cin >> name >> category;
        	v[category - 1].push(name);
        } else if (x == -2) {
        	int number;
        	cin >> number >> category;
        	while (number != 0) {
        		v[category - 1].pop();
        		--number;
        	}
        } else if (x == -3) {
        	cin >> category;
        	cout << "Pila de la categoria " << category << endl;
        	stack<string> st = v[category - 1];
        	while (not st.empty()) {
        		cout << st.top() << endl;
        		st.pop();
        	}
        	cout << endl;
        }
        cin >> x;
    }
}
