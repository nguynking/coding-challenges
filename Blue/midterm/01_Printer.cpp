#include <bits/stdc++.h>
using namespace std;
#define MAX 10

int main() {
    int t; cin >> t;
    while (t--) {
        queue<pair<int, int>> q;
        vector<int> v;
        int n, m, x;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> x;
            q.push(pair<int, int>(x, i));
            v.push_back(x);
        }
        sort(v.begin(), v.end());

        int time = 0;
        int i = n - 1;
        while (!q.empty()) {
            int u = q.front().first;
            int w = q.front().second;
            q.pop();
            if (u == v[i]) {
                ++time;
                if (w == m) break;
                --i;
            }
            else {
                q.push(pair<int, int>(u, w));
            }
        }
        cout << time << endl;
    }
    return 0;
}