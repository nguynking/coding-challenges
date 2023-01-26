#include <bits/stdc++.h>
using namespace std;
#define MAX 1005

int main() {
    int n, x;
    int v[MAX];
    stack<int> st;
    while (true) {
        cin >> n;
        if(n == 0) break;
        int target = 1;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int i = 0;
        while (i < n) {
            if (v[i] == target) {
                ++i;
                ++target;
            }
            else if (!st.empty() && st.top() == target) {
                st.pop();
                ++target;
            }
            else {
                st.push(v[i]);
                ++i;
            }
        }
        while (!st.empty() && st.top() == target) {
            ++target;
            st.pop();
        }
        cout << (target == n + 1 ? "yes" : "no") << endl;
        while (!st.empty()) {
            st.pop();
        }
    }
    return 0;
}