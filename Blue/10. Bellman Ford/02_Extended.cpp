#include<bits/stdc++.h>
using namespace std;
#define MAX 205
#define ll long long
int n, m;
const long long int INF = 1e9 + 7;
vector<long long int> dist(MAX, INF);
vector<bool> visited(MAX, false);

struct Edge {
    int s, t; 
  	long long int w;
};

void bfs(int s, vector<int> graph1[]) {
    queue<int> q;
    q.push(s);
    dist[s] = -INF;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph1[u].size(); i++) {
            int v = graph1[u][i];
            if (!visited[v]) {
                dist[v] = -INF;
                visited[v] = true;
            }
        }
    }
}

void bellmanford(int s, vector<Edge> graph, vector<int> graph1[]) {
    int u, v;
    long long int w;
    dist[s] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            u = graph[j].s;
            v = graph[j].t;
            w = graph[j].w;
            if (dist[u] != INF && (dist[u] + w < dist[v])) {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            u = graph[j].s;
            v = graph[j].t;
            w = graph[j].w;
            if (dist[v] == -INF) continue;
            if (dist[u] != INF && (dist[u] + w < dist[v])) {
                dist[v] = -INF;
                break;
            }
        }
    }
    // for (int i = 0; i < m; i++) {
    //     u = graph[i].s;
    //     v = graph[i].t;
    //     w = graph[i].w;
    //     if (dist[u] + w < dist[v]) {
    //         bfs(u, graph1);
    //     }
    // }
    // while(true) {
    //     int i;
    //     for (i = 0; i < m; i++) {
    //         u = graph[i].s;
    //         v = graph[i].t;
    //         w = graph[i].w;
    //         if (dist[u] == -INF) continue;
    //         if (dist[u] + w < dist[v]) {
    //             dist[v] = -INF;
    //             break;
    //         }
    //     }
    //     if (i == m) break;
    // }
}

int main() {
    int t; cin >> t;
    int x, u, v, q, a;
    for (int k = 1; k <= t; k++) {
        vector<int> busy;
        vector<Edge> graph;
        vector<int> graph1[MAX];
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x;
            busy.push_back(x);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            long long int w = (busy[v - 1] - busy[u - 1]) * (busy[v - 1] - busy[u - 1]) * (busy[v - 1] - busy[u - 1]);
            graph.push_back({u, v, w});
            graph1[u].push_back(v);
        }
        cout << "Case " << k << ":" << endl;
        for (int i = 0; i <= n; i++) {
            dist[v] = INF;
        }
        bellmanford(1, graph, graph1);
        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> a;
            if (dist[a] != INF && dist[a] >= 3) {
                cout << dist[a] << endl;
            }
            else {
                cout << "?" << endl;
            }
        }
    }
    return 0;
}