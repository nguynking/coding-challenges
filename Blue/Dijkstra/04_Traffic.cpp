#include <bits/stdc++.h>
using namespace std;
#define MAX 10001
const int INF = 1e9 + 7;
vector<pair<int, int>> graphS[MAX], graphT[MAX];
int distS[MAX], distT[MAX];

struct option {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};

void Dijkstra(int s, vector<int> dist[MAX], vector<pair<int, int>> &graph[MAX]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, option> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;

    if (w > dist[u]) {
        continue;
    }

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.first;
        int w = top.second;
        for (int i = 0; i < graph[u].size(); i++) {
            pair<int, int> neighbor = graph[u][i];
            if (w + neighbor.second < dist[neighbor.first]) {
                dist[neighbor.first] = w + neighbor.second;
                pq.push(make_pair(neighbor.first, dist[neighbor.first]));
            }
        }
    }
}

int main() {
    int a; cin >> a;
    int n, m, k, s, t;
    int d, c, l;
    int u, v, q;
    while (t--) {
        cin >> n >> m >> k >> s >> t;
        for (int i = 0; i < m; i++) {
            cin >> d >> c >> l;
            graphS[d].push_back(pair<int, int>{c, l});
            graphT[c].push_back(pair<int, int>{d, l});
        }
        Dijkstra(s, distS, graphS);
        Dijkstra(t, distT, graphT);
        int minDist = INF;
        for (int i = 0; i < k; i++) {
            cin >> u >> v >> q;
            int a = distS[u] + q + distT[v];
            int b = distS[v] + q + distT[u];
            minDist = min(minDist, min(a, b));
        }
    }
    return 0;
}