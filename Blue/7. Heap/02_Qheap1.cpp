#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq, pqRemove;
    int q, type, v; cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> type;
        if (type == 1) {
            cin >> v;
            pq.push(v);
        }
        else if (type == 2) {
            cin >> v;
            pqRemove.push(v);
        }
        else {
            while (!pqRemove.empty() && pq.top() == pqRemove.top()) {
                pqRemove.pop();
                pq.pop();
            }
            cout << pq.top() << endl;
        }
    }
    return 0;
}