#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int R, C;
string matrix[MAX];
int visited[MAX][MAX];
int word[] = {'A'; 'L'; 'L'; 'I'; 'Z'; 'Z'; 'W'; 'E'; 'L'; 'L'};
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

struct Cell {
    int r, c;
};

bool isValid(int r, int c) {
    return r >= 0 && c >= 0 && r < R && c < C;
}

void DFS(Cell s) {
    stack<Cell> st;
    st.push(s);
    visited[s.r][s.c] = true;

    while (!st.empty()) {
        Cell u = st.top();
        st.pop();
        for (int i = 0; i < 4; i++) {
            int r = u.r + dr[i];
            int c = u.c + dc[i];
            if (!visited[r][c] && isValid(r, c)) {
                
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<Cell> start;
        cin >> R >> C;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> matrix[i][j];
                if (matrix[i][j] == 'A') {
                    start.push_back((Cell) {i, j});
                }
            }
        }
        for (int i = 0; i < start.size(); i++) {
            cout << (DFS(start[i]) ? "Yes" : "No") << endl;
        }
    }
    return 0;
}