#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
vector<int> graph[MAX];
int u, v;
int dist[MAX] = {0};
bool visited[MAX] = {false};

void DFS(int s) {
    stack<int> st;
    st.push(s);
    visited[s] = true;
    
    while(!st.empty()) {
        int u = st.top();
        st.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                st.push(v);
            }
        }
    }
}

int main() {
    int n, q, id;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 0; i <= n; i++) {
        visited[i] = false;
    }
    DFS(1);
    int min_dist = n, min_id = n;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> id;
        if (dist[id] < min_dist || (dist[id] == min_dist && id < min_id)) {
            min_dist = dist[id];
            min_id = id;
        }
    }
    cout << min_id;
    return 0;
}