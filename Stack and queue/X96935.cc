#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n, x;
    stack<int> st;
    cin >> n;
    if (n > 0) {
        bool odd = (n%2 != 0);
        int mid = n/2;
        bool palin = true;
        for (int i = 0; palin and i < n; ++i) {
            cin >> x;
            if (not odd or i != mid) {
                if (i >= mid) {
                    if (st.top() == x) st.pop();
                    else palin = false;
                } else st.push(x);
            }
        }
        if (st.empty() or n == 1) cout << "SI" << endl; // si es 1 sempre es palindrom
        else cout << "NO" << endl;
    }
}
