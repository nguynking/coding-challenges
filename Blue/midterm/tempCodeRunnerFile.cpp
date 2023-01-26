#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        queue<pair<int, int>> q;
        vector<int> v(10);
        int n, m, x;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (i != m) q.push(make_pair(x, 0));
            else q.push(make_pair(x, 1));
            v.push_back(x);
        }
        sort(v.begin(), v.end());

        int time = 0;
        int k = n - 1;
        while (!q.empty()) {
            int u = q.front().first;
            int v = q.front().second;
            if (u != v[k]) {
                q.push(make_pair(u, v));
                q.pop();
                ++time;
            }
            else {
                if (v == 0) {
                    q.pop();
                    ++time;
                }
                else {
                    cout << time << endl;
                    break;
                }
            }
        }
    }
    return 0;
}