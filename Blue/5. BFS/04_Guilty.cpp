#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int w, h;
char grid[MAX][MAX];
int visited[MAX][MAX];
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

struct Cell {
    int r, c;
};

bool isValid(int r, int c) {
    return r >= 0 && r < h && c >= 0 && c < w;
}

int BFS (Cell s) {
    queue<Cell> q;
    visited[s.r][s.c] = true;
    q.push(s);
    int count = 1;

    while (!q.empty()) {
        Cell u = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int r = u.r + dr[i];
            int c = u.c + dc[i];
            if (grid[r][c] == '.' && isValid(r, c) && !visited[r][c]) {
                visited[r][c] = true;
                ++count;
                q.push((Cell) {r, c});
            }
        }
    }

    return count;
}

int main() {
    Cell start;
    int t;
    cin >> t;
    for (int k = 1; k <= t; k++) {
        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> grid[i][j];
                visited[i][j] = false;
                if (grid[i][j] == '@') {
                    start = (Cell) {i, j};
                }
            }
        }
        cout << "Case " << k << ": " << BFS(start) << endl;
    }
    return 0;
}