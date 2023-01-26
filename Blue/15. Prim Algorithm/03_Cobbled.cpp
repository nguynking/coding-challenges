#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
const int INF = 1e9;

vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX, INF);
bool visited[MAX];
int path[MAX];
int n;

void prim(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
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

int printMST() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (path[i] == -1) continue;
        ans += dist[i];
    }
    return ans;
}

int main() {
    int t, p, m, a, b, c;
    cin >> t;
    while(t--) {
        cin >> p >> n >> m;
        for (int i = 0; i < n; i++) {
            graph[i].clear();
            dist[i] = INF;
            visited[i] = false;
        }
        memset(path, -1, sizeof(path));
        int s;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            graph[a - 1].push_back(make_pair(b - 1, c));
            graph[b - 1].push_back(make_pair(a - 1, c));
            s = a - 1;
        }
        prim(s);
        int ans = printMST();
        cout << ans * p << endl;
    }
    return 0;
}