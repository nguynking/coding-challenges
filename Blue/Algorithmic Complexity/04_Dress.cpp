#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, x, y, a;
    cin >> n >> m >> x >> y;
    vector<int> desire, available;
    vector<pair<int, int>> store;
    for (int i = 0; i < n; i++) {
        cin >> a;
        desire.push_back(a);
    }
    for (int i = 0; i < m; i++) {
        cin >> a;
        available.push_back(a);
    }
    int i = 0, j = 0, num = 0;
    while (i < n && j < m) {
        if (available[j] <= desire[i] + y && available[j] >= desire[i] - x) {
            ++num;
            store.push_back(make_pair(i + 1, j + 1));
            ++i; ++j;
        }
        else if (available[j] < desire[i] - x) ++j;
        else ++i;
    }
    cout << num << endl;
    for (int i = 0; i < store.size(); i++) {
        cout << store[i].first << " " << store[i].second << endl;
    }
    return 0;
}