#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> require(n), prep(m);
    for (int i = 0; i < n; i++) {
        cin >> require[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> prep[i];
    }
    int j = 0, matches = 0;
    for (int i = 0; i < n; i++) {
        while (prep[j] < require[i] && j < m) ++j;
        if (j < m) ++matches;
        ++j;
    }
    cout << n - matches;
    return 0;
}
