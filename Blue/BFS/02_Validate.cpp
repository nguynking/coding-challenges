#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int m, n;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
string maze[MAX];
int visited[MAX][MAX];

struct Cell {
    int r, c;
};

bool isValid(int r, int c) {
    return r >= 0 && r < m && c >= 0 && c < n;
}

bool BFS (Cell s, Cell f) {
    queue<Cell> q;
    visited[s.r][s.c] = true;
    q.push(s);
    
    while (!q.empty()) {
        Cell u = q.front();
        q.pop();
        if (u.r == f.r && u.c == f.c) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int r = u.r + dr[i];
            int c = u.c + dc[i];

            if (isValid(r, c) && maze[r][c] == '.' && visited[r][c] == false) {
                visited[r][c] = true;
                q.push((Cell) {r, c});
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        vector<Cell> entrance;
        cin >> m >> n;
        for (int i = 0; i < m; i++) {
            cin >> maze[i];
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
                if (maze[i][j] == '.' && (i == 0 || j == 0 || i == m - 1 || j == n - 1)) {
                    entrance.push_back((Cell) {i, j});
                }
            }
        }
        if (entrance.size() != 2) {
            cout << "invalid" << endl;
        }
        else {
            Cell s = entrance[0];
            Cell f = entrance[1];
            cout << (BFS(s, f) ? "valid" : "invalid") << endl;
        }
    }
    return 0;
}