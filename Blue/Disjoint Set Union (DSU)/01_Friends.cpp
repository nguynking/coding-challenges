#include <bits/stdc++.h>
using namespace std;
#define MAX 30005

int parent[MAX];
int ranks[MAX];
int num[MAX];

void makeSet() {
    for (int i = 1; i <= MAX; i++) {
        parent[i] = i;
        ranks[i] = 0;
    }
}

int findSet(int u) {
    if (parent[u] != u) {
        parent[u] = findSet(parent[u]);
    }
    return parent[u];
}

void unionSet(int u, int v) {
    int up = findSet(u);
    int vp = findSet(v);
    if (up == vp) {
        return;
    }
    if (ranks[up] > ranks[vp]) {
        parent[vp] = up;
        num[up] += num[vp];
    }
    else if (ranks[up] < ranks[vp]) {
        parent[up] = vp;
        num[vp] += num[up];
    }
    else {
        parent[up] = vp;
        num[vp] += num[up];
        ++ranks[vp];
    }
}

int main() {
    int t; cin >> t;
    int n, m, a, b;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            ranks[i] = 0;
            num[i] = 1;
        }
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            unionSet(a, b);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, num[i]);
        }
        cout << ans << endl;
    }
    return 0;
}