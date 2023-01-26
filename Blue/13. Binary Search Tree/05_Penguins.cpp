#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    cin.ignore();
    string s;
    map<string, int> m;
    while(n--) {
        getline(cin, s);
        ++m[s];
    }
    int max = -1;
    string name;
    map<string, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        if (it->second > max) {
            max = it->second;
            name = it->first;
        }
    }
    cout << name;
    return 0;
}