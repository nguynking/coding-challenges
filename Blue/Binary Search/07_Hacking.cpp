#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, x;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long cnt = 0;
    vector<int>::iterator it;
    for (int i = 0; i < n; i++) {
        it = lower_bound(v.begin(), v.end(), v[i] + k);
        if (it != v.end() && *it == v[i] + k) {
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}