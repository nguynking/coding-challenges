    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        int n;
        queue<int> q;
        while (true) {
            vector<int> discard;
            cin >> n;
            if (n == 0) break;
            for (int i = 1; i <= n; i++) {
                q.push(i);
            }
            while (q.size() >= 2) {
                discard.push_back(q.front());
                q.pop();
                q.push(q.front());
                q.pop();
            }
            if (n == 1) cout << "Discarded cards:";
            else cout << "Discarded cards: " << discard[0];
            for (int i = 1; i < discard.size(); i++) {
                cout << ", " << discard[i];
            }
            cout << endl;
            cout << "Remaining card: " << q.front() << endl;
            while (!q.empty()) {
                q.pop();
            }
        }
        return 0;
    }