#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll n, v, min1, min2;
    while (true) {
        cin >> n;
        if (n == 0) break;
        for (ll i = 0; i < n; i++) {
            cin >> v;
            pq.push(v);
        }
        ll total = 0;
        while (pq.size() > 1) {
            min1 = pq.top(); pq.pop();
            min2 = pq.top(); pq.pop();
            total += min1 + min2;
            pq.push(min1 + min2);
        }
        cout << total << endl;
        pq.pop();
    }
    return 0;
}