#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, Alice, Bob;
    cin >> n;
    vector<int> time(n);
    for (int i = 0; i < n; i++) {
        cin >> time[i];
    }
    int j = n - 1, i = 0;
    int sumA = 0, sumB = 0;
    while (i <= j) {
        if (sumA + time[i] <= sumB + time[j]) {
            sumA += time[i];
            ++i;
        }
        else {
            sumB += time[j];
            --j;
        }
        //cout << i << " " << j << '\n';
    }
    cout << i << " " << n - i;
    return 0;
}