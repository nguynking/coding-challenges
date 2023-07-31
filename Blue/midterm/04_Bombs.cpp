#include <bits/stdc++.h>
using namespace std;
#define MAX 1001
int graph[MAX][MAX];
int visited[MAX][MAX];
int dist[MAX][MAX];
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
int R, C, rows, a, b, z;

struct Cell {
    int r, c;
};

bool isValid (int r, int c) {
    return r >= 0 && c >= 0 && r < R && c < C;
}

void BFS(Cell s) {
    queue<Cell> q;
    q.push(s);
    visited[s.r][s.c] = true;
    dist[s.r][s.c] = 0;

    while(!q.empty()) {
        Cell u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int r = u.r + dr[i];
            int c = u.c + dc[i];
            if (isValid(r, c) && !visited[r][c] && graph[r][c] == 1) {
                dist[r][c] = dist[u.r][u.c] + 1;
                visited[r][c] = true;
                q.push((Cell) {r, c});
            }
        }
    }
}

int main() {
    while (true) {
        cin >> R >> C;
        if (R == 0 && C == 0) return 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                graph[i][j] = 1;
                visited[i][j] = false;
            }
        }
        cin >> rows;
        for (int i = 0; i < rows; i++) {
            cin >> a >> b;
            for (int j = 0; j < b; i++) {
                cin >> z;
                graph[a][z] = 0;
            }
        }
        Cell s, d;
        cin >> s.r >> s.c >> d.r >> d.c;
        BFS(s);
        cout << dist[d.r][d.c] << endl;
    }
    return 0;
}