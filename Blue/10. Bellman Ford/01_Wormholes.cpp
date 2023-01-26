#include <bits/stdc++.h>
using namespace std;
#define MAX 2001
const int INF = 1e9 + 7;
vector<int> dist(MAX, INF);
int n, m;

struct Edges {
    int source, target, weight;
    Edges (int source = 0, int target = 0, int weight = 0) {
        this->source = source;
        this->target = target;
        this->weight = weight;
    }
};

bool BellmanFord(int s, vector<Edges> graph) {
    int u, v, w;
    dist[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            u = graph[j].source;
            v = graph[j].target;
            w = graph[j].weight;
            if (dist[u] != INF && (dist[u] + w < dist[v])) {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        u = graph[i].source;
        v = graph[i].target;
        w = graph[i].weight;
        if (dist[u] != INF && (dist[u] + w < dist[v])) {
            return false;
        }
    }
    return true;
}

int main() {
    int c; cin >> c;
    int x, y, t;
    while (c--) {
        vector<Edges> graph;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> x >> y >> t;
            graph.push_back(Edges(x, y, t));
        }
        if (!BellmanFord(0, graph)) {
            cout << "possible" << endl;
        }
        else cout << "not possible" << endl;
        for (int i = 0; i < m; i++) {
            dist[i] = INF;
        }
    }
    return 0;
}