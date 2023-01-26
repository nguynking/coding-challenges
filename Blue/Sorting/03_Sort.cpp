#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, l, r;
    cin >> n;
    ll a[n], s[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i] = a[i];
    }
    sort(s, s + n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == a[i]) {
            ++count; 
        }
    }
    if (count == n) {
        cout << "yes\n1 1";
        return 0;
    }
    int seg = 0;
    for (int i = 0; i < n - 1, seg < 1;) {
        if (a[i] < a[i + 1]) {
            ++i;
        }
        else {
            l = r = i;
            while (a[i] > a[i + 1] && i < n - 1) {
                ++i;
                ++r;
            }
            sort(a + l, a + r + 1);
            ++seg;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] != s[i]) {
            cout << "no";
            return 0;
        }
    }
    cout << "yes\n" << l + 1  << " " << r + 1;
    return 0;
}