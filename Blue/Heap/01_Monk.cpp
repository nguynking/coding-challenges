#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
#define ll long long

int main() {
    priority_queue<ll> pq;
    ll n; cin >> n;
    ll a[MAX];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pq.push(a[i]);
        if (i < 2) cout << -1 << '\n';
        else {
            ll max1 = pq.top();
            pq.pop();
            ll max2 = pq.top();
            pq.pop();
            ll max3 = pq.top();
            pq.pop();
            cout << max1 * max2 * max3 << endl;
            pq.push(max1);
            pq.push(max2);
            pq.push(max3);
        }
    }
    return 0;   
}