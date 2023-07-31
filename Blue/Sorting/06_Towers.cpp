#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int count[1001] = {0}, a[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ++count[a[i]];
    }
    int maxT = 1, num = 0;
    for (int i = 0; i < 1001; i++) {
        if (count[i] != 0) {
            ++num;
        }
        maxT = max(maxT, count[i]);
    }
    cout << maxT << " " << num;
    return 0;
}