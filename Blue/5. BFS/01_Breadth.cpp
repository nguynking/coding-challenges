#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1001
bool visited[MAX];

void readGraph(int E, vector<int> graph[]) {
    int u, v;
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void BFS(int s, int V, vector<int> graph[]) {
    for (int i = 0; i <= V; i++) {
        visited[i] = false;
    }
    int dist[MAX];
    for (int i = 0; i <= V; i++) {
        dist[i] = -1;
    }
    queue<int> q;
    visited[s] = true;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                q.push(v);
                //cout << "v = " << v << " " << "dist[v] = " << dist[v] << '\n';
            }
        }
    }
    for (int i = 1; i <= V; i++) {
        if (i != s) {
            cout << max(dist[i] * 6 , -1) << " ";
        }
    }
}

int main() {
    int q, V, E, u, v;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s;
        vector<int> graph[MAX];
        cin >> V >> E;
        readGraph(E, graph);
        cin >> s;
        BFS(s, V, graph);
        cout << '\n';
    }
    return 0;
}