#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, x, y, cnt = 1;
    while(true) {
        cin >> n >> q;
        if (n == 0 && q == 0) break;
        int index;
        vector<int> mar;
        for (int i = 0; i < n; i++) {
            cin >> x;
            mar.push_back(x);
        }
        sort(mar.begin(), mar.end());
        cout << "CASE# " << cnt << ":" << endl;
        for (int i = 0; i < q; i++) {
            cin >> y;
            index = lower_bound(mar.begin(), mar.end(), y) - mar.begin() + 1;
            if (index <= mar.size() && y == mar[index - 1]) {
                cout << y << " found at " << index << endl;
            }
            else {
                cout << y << " not found" << endl;
            }
        }
        ++cnt;
    }
    return 0;
}