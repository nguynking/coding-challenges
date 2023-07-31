#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
const int INF = 1e9;
vector<int> choco(MAX);
vector<vector<pair<int, int>>> graph;
vector<int> dist(MAX, INF);

void Dijkstra (int s) {
    priority_queue<pair<int, int>> pq;
    pq.push(pair<int, int> (s, 0));
    dist[s] = 0;

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.first;
        int w = top.second;
        for (int i = 0; i < graph[u].size(); i++) {
            pair<int, int> neighbor = graph[u][i];
            if (w + neighbor.second < dist[neighbor.first]) {
                dist[neighbor.first] = w + neighbor.second;
                pq.push(pair<int, int> (neighbor.first, dist[neighbor.first]));
            }
        }
    }
}

int main() {
    int n, m, k, x, c, u, v, d, a, b;
    cin >> n >> m >> k >> x;
    graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());
    for (int i = 0; i < k; i++) {
        cin >> c;
        choco[c] = 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> d;
        graph[u].push_back(pair<int, int> (v, d));
        graph[v].push_back(pair<int, int> (u, d));
    }
    cin >> a >> b;
    Dijkstra(a);
    for (int i = 1; i <= n; i++) {
        if (choco[i] != 0) choco[i] = dist[i];
    }
    dist = vector<int>(MAX, INF);
    Dijkstra(b);
    int min = INF;
    for (int i = 1; i <= n; i++) {
        if (choco[i] != 0 && (choco[i] + dist[i]) < min) {
            min = choco[i] + dist[i];
        }
    }
    if (min >= x) cout << -1;
    else cout << min;
    return 0;
}