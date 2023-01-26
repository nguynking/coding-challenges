#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int nA, nB, k, m;
    cin >> nA >> nB >> k >> m;
    vector<int> A, B;
    for (int i = 0; i < nA; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }
    for (int i = 0; i < nB; i++) {
        int x;
        cin >> x;
        B.push_back(x);
    }
    if (A[k-1] < B[nB-m]) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}