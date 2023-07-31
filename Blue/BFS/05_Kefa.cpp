#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int n, m;
int a[MAX], cat[MAX];
bool visited[MAX];
vector<int> graph[MAX];

int BFS(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    cat[s] = (a[s] == 1);
    int numrestaurant = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < graph[u].size(); i++) {
            int r = graph[u][i];
            if (!visited[r]) {
                visited[r] = true;
                if (a[r] == 1) {
                    cat[r] = cat[u] + 1;
                }
                if (cat[r] <= m) {
                    if (graph[r].size() == 1) {
                        ++numrestaurant;
                    }
                    else {
                        q.push(r);
                    }
                }
            }
        }
    }
    return numrestaurant;
}

int main() {
    int x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        visited[i] = false;
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    cout << BFS(1);
    return 0;
}