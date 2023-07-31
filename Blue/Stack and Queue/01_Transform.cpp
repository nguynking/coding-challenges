#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int j = 0; j < t; j++) {
        stack<char> st;
        string s, result;
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') continue;
            else if (s[i] >= 'a' && s[i] <= 'z') {
                result += s[i];
            }
            else if (s[i] == '*' || s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '^') {
                st.push(s[i]);
            }
            else if (s[i] == ')') {
                result += st.top();
                st.pop();
            }
        }
        cout << result << '\n';
    }
    return 0;
}