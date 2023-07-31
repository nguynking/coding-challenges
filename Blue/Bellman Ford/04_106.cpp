#include <bits/stdc++.h>
using namespace std;
#define MAX_N 105
#define MAX_M 100 * 50 + 5
int n, m;
vector<double> dist(MAX_N, -1.0);

struct Edge {
    int s, t;
    double w;
};
Edge graph[MAX_M];

void bellmanford() {
    int u, v;
    double w;
    for (int i = 0; i <= n; i++) {
        dist[i] = -1.0;
    }
    dist[1] = 1.0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            u = graph[j].s;
            v = graph[j].t;
            w = graph[j].w;
            dist[u] = max(dist[u], dist[v] * w);
            dist[v] = max(dist[v], dist[u] * w);
        }
    }
}

int main() {
    int a, b;
    double p;
    while (true) {
        cin >> n;
        if (n == 0) break;
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> p;
            graph[i] = (Edge) {a, b, p / 100.0};
        }
        bellmanford();
        cout << fixed << setprecision(6) << dist[n] * 100.0 << " percent" << endl;
    }
    return 0;
}