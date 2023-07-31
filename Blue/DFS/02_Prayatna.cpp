#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
vector<int> graph[MAX];
int visited[MAX] = {false};

void DFS(int s) {
    stack<int> st;
    st.push(s);
    visited[s] = true;

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (!visited[v]) {
                visited[v] = true;
                st.push(v);
            }
        }
    }
}

int main() {
    int t, n, e, a, b;
    cin >> t ;
    while (t--) {
        cin >> n >> e;
        for (int i = 0; i < n; i++) {
            graph[i].clear();
            visited[i] = false;
        }
        for (int i = 0; i < e; i++) {
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ++count;
                DFS(i);
            }
        }
        cout << count << endl;
    }
    return 0;
}