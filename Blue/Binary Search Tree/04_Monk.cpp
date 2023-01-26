#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t; cin >> t;
    ll n, m, x;
    while (t--) {
        cin >> n >> m;
        set<ll> s;
        for (int i = 0; i < n; i++) {
            cin >> x;
            s.insert(x);
        }
        for (int i = 0; i < m; i++) {
            cin >> x;
            if (s.find(x) != s.end()) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
            s.insert(x);
        }
    }
    return 0;
}