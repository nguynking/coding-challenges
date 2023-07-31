#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(10e5 + 1, 0), num;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }
    int unique = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[num[i]] == 0) {
            ++unique;
        }
        ++cnt[num[i]];
        if (unique == k) {
            int j = 0;
            while (true) {
                if (cnt[num[j]] > 1) {
                    --cnt[num[j]];
                    ++j;
                }
                else {
                    cout << j + 1 << " " << i + 1;
                    return 0;
                }
            }
        }
    }
    cout << -1 << " " << -1;
    return 0;
}