#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s;
    map<string, int> tree;
    while(n--) {
        int cnt = 0;
        while(true) {
            getline(cin, s);
            if (s == "") break;
            tree[s] += 1;
            ++cnt;
        }
        map<string, int>::iterator it;
        for (it = tree.begin(); it != tree.end(); it++) {
            cout << it->first << " " << fixed << setprecision(4) << it->second / cnt << endl;
        }
    }
    return 0;
}