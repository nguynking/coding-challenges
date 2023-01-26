#include <bits/stdc++.h>
using namespace std;
#define MAX 101
const int INF = 1e9;
vector<vector<pair<int, int>>> graph;
vector<int> dist(MAX, INF);

struct option {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};

void Dijkstra(int s) {
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
    int n, e, t, m, a, b, c;
    cin >> n >> e >> t >> m;
    graph = vector<vector<pair<int, int>>> (MAX, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[b].push_back(pair<int, int> (a, c));
    }
    Dijkstra(e);
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] <= t) ++count;
    }
    cout << count;
    return 0;
}