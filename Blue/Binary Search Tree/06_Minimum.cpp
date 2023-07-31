#include <bits/stdc++.h>
using namespace std;
#define MAX 2e16
#define ll long int

int main() {
    ll n, price; cin >> n;
    map<ll, ll> m;
    for (ll year = 0; year < n; year++) {
        cin >> price;
        m[price] = year;
    }
    ll min_loss = MAX, loss;
    map<ll, ll>::iterator it, best_buy_idx;
    for (it = m.begin(); it != m.end(); it++) {
        best_buy_idx = m.upper_bound(it->first);
        if (best_buy_idx != m.end() && best_buy_idx->second < it->second) {
            loss = best_buy_idx->first - it->first;
            min_loss = min(loss, min_loss);
        }
    }
    cout << fixed << setprecision(0) << min_loss;
    return 0;
}