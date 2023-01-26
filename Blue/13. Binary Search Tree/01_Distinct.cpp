#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    int n, x, value;
    while (t--) {
        cin >> n;
        cin >> x;
        set<int> s;
        for (int i = 0; i < n; i++) {
            cin >> value;
            s.insert(value);
        }
        if (s.size() == x) cout << "Good" << endl;
        else if (s.size() < x) cout << "Bad" << endl;
        else cout << "Average" << endl;
    }
    return 0;
}