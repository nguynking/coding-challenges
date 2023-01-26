#include <bits/stdc++.h>
using namespace std;
#define MAX 101
vector<int> dist(MAX);
int n, m;

struct Edge {
    int s, t, w;
};

void bellmanford (vector<Edge> graph) {
    int u, v, w;
    dist[1] = 100;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            u = graph[j].s;
            v = graph[j].t;
            w = graph[j].w;
            if (dist[u] != -101) {
                dist[v] = max(dist[v], dist[u] + w);
            }
        }
    }
}

int main() {
    int u, v, w, out;
    while(true) {
        cin >> n;
        if (n == -1) break;
        m = 0;
        vector<Edge> graph;
        for (int i = 1; i <= n; i++) {
            cin >> w >> out;
            m += out;
            for (int j = 0; j < out; j++) {
                cin >> v;
                if (i == 1) continue;
                graph.push_back({i - 1, v, w});
            }
        }
        for (int i = 0; i <= n; i++) {
            dist[i] = -101;
        }
        bellmanford(graph);
        //cout << dist[n] << endl;
        cout << (dist[n] <= 0 ? "hopeless" : "winnable") << endl;
    }
    return 0;
}