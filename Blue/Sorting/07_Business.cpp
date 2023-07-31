#include<bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    int a[12];
    for (int i = 0; i < 12; i++) {
        cin >> a[i];
    }
    sort(a, a + 12);
    int total = 0, month = 0;
    int i = 0;
    for (int i = 11; i >= 0; i--) {
        if (total < k) {
            total += a[i];
            ++month;
        }
        else {
            cout << month;
            return 0;
        }
    }
    if (total < k) cout << -1;
    else cout << month;

    return 0;
}