#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 1e6 + 1;

int main() {
    ll n; cin >> n;
    ll k, price, cost = 0;
    priority_queue<ll> pqMax;
    priority_queue<ll, vector<ll>, greater<ll>> pqMin;
    vector<ll> cntMax(MAX);
    vector<ll> cntMin(MAX);
    while (n--) {
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> price;
            pqMax.push(price);
            pqMin.push(price);
        }
        while (cntMax[pqMax.top()] != 0) {
            --cntMax[pqMax.top()];
            pqMax.pop();
        }
        while (cntMin[pqMin.top()] != 0) {
            --cntMin[pqMin.top()];
            pqMin.pop();
        }
        cost += pqMax.top() - pqMin.top();
        ++cntMax[pqMax.top()]; ++cntMax[pqMin.top()];
        ++cntMin[pqMin.top()]; ++cntMin[pqMax.top()];
    }
    cout << cost;
    return 0;
}