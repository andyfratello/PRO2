#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> st;
    char c;
    cin >> c;
    bool correct = true;
    while (correct and c != '.') {
        if (c == '(') st.push(c);
        if (c == '[') st.push(c);
        if (c == ')') {
            if (st.empty() or st.top() == '[') correct = false;
            else st.pop();
        }
        if (c == ']') {
            if (st.empty() or st.top() == '(') correct = false;
            else st.pop();
        }
        cin >> c;
    }
    if (correct and st.empty()) cout << "Correcte" << endl;
    else cout << "Incorrecte" << endl;
}
