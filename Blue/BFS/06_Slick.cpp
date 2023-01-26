#include <bits/stdc++.h>
using namespace std;
#define MAX 251
int n, m;
int maze[MAX][MAX];
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
int slick[MAX * MAX];

struct Cell {
    int r, c;
};

bool isValid(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

void BFS(Cell s) {
    queue<Cell> q;
    maze[s.r][s.c] = 0;
    q.push(s);
    int count = 1;

    while (!q.empty()) {
        Cell u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int r = u.r + dr[i];
            int c = u.c + dc[i];
            if (isValid(r, c) && maze[r][c] == 1) {
                maze[r][c] = 0;
                ++count;
                q.push((Cell) {r, c});
            }
        }
    }
    ++slick[count];
}

int main() {
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) return 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> maze[i][j];
                slick[i * m + j + 1] = 0;
            }
        }

        int nslicks = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == 1) {
                    Cell s = (Cell) {i, j};
                    BFS(s);
                    ++nslicks;
                }
            }
        }
        cout << nslicks << endl;
        for (int i = 1; i <= n * m; i++) {
            if (slick[i]) {
                cout << i << " " << slick[i] << endl;
            }
        }
    }
    return 0;
}