#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string,int> d;
    char codi;
    string s;
    while (cin >> codi >> s) {
        map<string, int>::iterator it = d.find(s); // se'n va al final d.end() si no troba s
        if (codi == 'a') { 
            if (it != d.end()) { // si està s, s'afegeix a la pos del seu indicador, la freq + 1
                d[s] = it->second + 1; 
            } else d.insert(make_pair(s, 1)); // si no està s (it al final) s'afegeix i es posa la freq a 1
        } else if (codi == 'f') { // imprimir freq
            if (it == d.end()) cout << 0 << endl;
            else cout << it->second << endl;
        }
    }
}
