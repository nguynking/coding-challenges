    #include <bits/stdc++.h>
    using namespace std;
    #define MAX 501
    int n, m;
    char maze[MAX][MAX];
    const int dr[] = {-1, 0, 1, 0};
    const int dc[] = {0, 1, 0, -1};

    struct Cell {
        int r, c;
    };

    bool isValid(int r, int c) {
        return r >= 0 && c >= 0 && r < n && c < m;
    }

    bool checkAround(Cell s) {
        for (int i = 0; i < 3; i++) {
            int r = s.r + dr[i];
            int c = s.c + dc[i];
            if (maze[r][c] == '.') {
                return true;
            }
        }
        return false;
    }


    bool BFS(Cell s, Cell e) {
        queue<Cell> q;
        q.push(s);
        maze[s.r][s.c] = 'X';

        while (!q.empty()) {
            Cell u = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int r = u.r + dr[i];
                int c = u.c + dc[i];
                if (r == e.r && c == e.c && maze[r][c] == 'X') {
                    return true;
                }
                if (isValid(r, c) && maze[r][c] == '.') {
                    maze[r][c] = 'X';
                    q.push((Cell) {r, c});
                }
            }
        }
        return false;
    }

    int main() {
        Cell s, e;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> maze[i][j];
            }
        }
        cin >> s.r >> s.c >> e.r >> e.c;
        s.r -= 1, s.c -= 1, e.r -= 1, e.c -= 1;
        cout << (BFS(s, e) ? "YES" : "NO");
        return 0;
    }