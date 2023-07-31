#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& a, int left, int right) {
    int mid = (left + right) / 2;
    int res, x = a[mid];
    for (int i = left + 1; i <= mid; i++) {
        if (a[i] - a[i - 1] > x) {
            binarySearch(a, mid + 1, right);
        }
        else if (a[i] - a[i - 1] == x) --x;
        else if (a[i] - a[i - 1] < x) 
    }
}

int main() {
    int t; cin >> t;
    int n;
    vector<int> a;
    for (int k = 1; k <= t; k++) {
        cin >> n;
        a.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        binarySearch();
        cout << "Case 1: ";

    }
    return 0;
}