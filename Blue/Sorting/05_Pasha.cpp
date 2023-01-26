#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll n, w;
    cin >> n >> w;
    vector<ll> a(2*n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    double p;
    if (a[n] >= 2 * a[0]) {
        p = (double)a[0];
    }
    else {
        p = (double)a[n] / 2;
    }
    if (p * 3 * n > w) {
        cout << (double)w;
    }
    else {
        cout << (double)(p * 3 * n);
    }
    /*
    if (a[n] <= 2 * a[0]) {
        if (a[n] / 2 <= max) {
            cout << (double)((a[n] / 2) * 3 * n);
            //cout << "TH1";
            return 0;
        }
        else {
            cout << (double)(max * 3 * n);
            //cout << "TH2";
            return 0;
        }
    }
    else {
        if (a[0] <= max) {
            cout << (double)(a[0] * 3 * n);
            //cout << "TH3";
            return 0;
        }
        else {
            cout << (double)(max * 3 * n);
            //cout << "TH4";
            return 0;
        }
    }
    */
    return 0;
}
