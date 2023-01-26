#include <bits/stdc++.h>
using namespace std;
#define MAX 20001
const int INF = 1e9;
vector<vector<pair<int, int>>> graph;
vector<int> dist(MAX, INF);

struct option {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};

void Dijkstra (int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, option> pq;
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
    int q; cin >> q;
    for (int k = 1; k <=q; k++) {
        graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());
        dist = vector<int>(MAX, INF);
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        int u, v, w;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            graph[u].push_back(pair<int, int> (v, w));
            graph[v].push_back(pair<int, int> (u, w));
        }
        Dijkstra(s);
        if (dist[t] != INF) {
            cout << "Case #" << k << ": " << dist[t] << endl;
        }
        else cout << "Case #" << k << ": unreachable" << endl;
    }
    return 0;
}