#include <bits/stdc++.h>
using namespace std;
#define MAX 10001
const int INF = 1e9;
vector<vector<pair<int, int>>> graph;
vector<int> dist(MAX, INF);
string city[MAX];

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
    int t;
    cin >> t;
    while(t--) {
        int n, p, nr, cost, r;
        string name, name1, name2;
        graph = vector<vector<pair<int, int>>> (MAX, vector<pair<int, int>>());
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> name >> p;
            city[i] = name;
            for (int j = 0; j < p; j++) {
                cin >> nr >> cost;
                graph[i].push_back(pair<int, int> (nr, cost));
            }
        }
        cin >> r;
        int s, d;
        for (int j = 0; j < r; j++) {
            cin >> name1 >> name2;
            for (int k = 1; k <= n; k++) {
                if (city[k] == name1) s = k;
                if (city[k] == name2) d = k;
            }
            Dijkstra(s);
            cout << dist[d] << endl;
            dist = vector<int>(MAX, INF);
        }
    }
    return 0;
}