#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> complex;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        complex.push_back(c);
    }
    sort(complex.begin(), complex.end());
    int x = complex[b] - complex[b-1];
    cout << x;
    return 0;
}