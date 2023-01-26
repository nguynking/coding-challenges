#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
const int INF = 1e9;
int n;

vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX, INF);
int path[MAX];
bool visited[MAX];

void prim(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0 ,src));
    dist[src] = 0;
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if (!visited[v] && dist[v] > w) {
                dist[v] = w;
                pq.push(make_pair(w, v));
                path[v] = u;
            }
        }
    }
}

void printMST() {
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (path[i] == -1) continue;
        ans += dist[i];
        //cout << i << " - " << path[i] << ": " << dist[i] << endl;
    }
    cout << ans;
}

int main() {
    int m, u, v, w, s = 0;
    cin >> n >> m;
    memset(path, -1, sizeof(path));
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        s = u - 1;
        graph[u - 1].push_back(make_pair(v - 1, w));
        graph[v - 1].push_back(make_pair(u - 1, w));
    }
    prim(s);
    printMST(); 
    return 0;
}