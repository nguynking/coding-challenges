#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(8), b(8), cntA(8), cntB(8), A(8), B(8);
    for (int i = 0; i < 8; i++) {
        cin >> a[i] >> b[i];
        A[i] = a[i];
        B[i] = b[i];
        cout << a[i] << " = a[" << i << "]" <<  " " << b[i] << " = b[" << i << "]" << '\n';
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cntA[0] = a[0];
    cntB[0] = b[0];
    // for (int i = 0; i < 8; i++) {
    //     cout << b[i] << '\n';
    // }
    int matchA = 1, matchB = 1, j = 1, k = 1;
    for (int i = 1; i < 8; i++) {
        if (a[i] != a[i - 1]) {
            cntA[j] = a[i];
            ++j;
        }
        if (b[i] != b[i - 1]) {
            cntB[k] = b[i];
            ++k;
        }
    }
    for (int i = 0; i < 8; i++) {
        cout << cntA[i] << " " << cntB[i] << '\n';
    }
    if (j != 3 || k != 3) {
        cout << "ugly" << " " << "TH1";
        return 0;
    }
    for (int i = 0; i < 8; i++) {
        if (cntA[1] == A[i] && cntB[1] == B[i]) {
            // cout << cntA[1] << " " << cntB[1] << '\n';
            // cout << i << '\n';
            // cout << a[i] << "        " << b[i] << '\n';
            cout << "ugly" << " " << "TH2";
            return 0;
        }
    }
    cout << "respectable" << " " << "TH3";
    return 0;
}