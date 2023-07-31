#include <bits/stdc++.h>
using namespace std;
#define MAX 500

vector<int> adj[MAX];
vector<bool> vis(MAX, false);
vector<int> dist(MAX);

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty()) {
        int f = q.front(); q.pop();
        for (int i = 0; i < adj[f].size(); i++) {
            int neig = adj[f][i];
            if (!vis[neig]) {
                vis[neig] = true;
                dist[neig] = dist[f] + 1;
                q.push(neig);
            }
        }
    }
}

int main() {
    int n; cin >> n;
    string s, f, t;
    int p = 1;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        cin >> s >> f >> t;
        if (!m[s])
            m[s] = p++;
        if (!m[f])
            m[f] = p++;
        if (!m[t])
            m[t] = p++;
        adj[m[s]].push_back(m[f]);
        adj[m[s]].push_back(m[t]);
        adj[m[f]].push_back(m[s]);
        adj[m[f]].push_back(m[t]);
        adj[m[t]].push_back(m[s]);
        adj[m[t]].push_back(m[f]);
    }
    bfs(m["Isenbaev"]);
    map<string, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        if (it->second == 0) continue;
        if (!vis[it->second]) {
            cout << it->first << " undefined" << endl;
        }
        else {
            cout << it->first << " " << dist[it->second] << endl;
        }
    }
    return 0;
}