#include <bits/stdc++.h>
using namespace std;
#define MAX 2001

int main() {
    int n; cin >> n;
    if (n < 3) {
        cout << "NO";
        return 0;
    }
    vector<int> diff(n);
    int x, cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (diff[x] == 0) ++cnt;
    }
    return 0;
}