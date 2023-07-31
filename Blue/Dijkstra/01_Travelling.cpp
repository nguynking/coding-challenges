#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 501
const int INF = 1e9;
vector<vector<pair<int, int>>> graph;
vector<int> dist(MAX, INF);
int path[MAX];

struct option {
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};

void Dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, option> pq;
    pq.push(make_pair(s, 0));
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
                path[neighbor.first] = u;
            }
        }
    }
}

int main() {
    int n, a, b, w, u, q, v;
    cin >> n;
    graph = vector<vector<pair<int, int>>>(MAX + 5, vector<pair<int, int>>());
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> w;
        graph[a].push_back(pair<int, int> (b, w));
        graph[b].push_back(pair<int, int> (a, w));
    }
    cin >> u;
    Dijkstra(u);
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> v;
        if (dist[v] != INF) cout << dist[v] << endl;
        else cout << "NO PATH" << endl;
    }
    return 0;
}