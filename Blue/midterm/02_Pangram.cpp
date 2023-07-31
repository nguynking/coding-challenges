#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s;
    cin >> s;
    int arr[26];
    for (int i = 0; i < 26; i++) {
        arr[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        s[i] = tolower(s[i]);
        arr[s[i] - 'a'] = 1;
    }
    for (int i = 0; i < 26; i++) {
        if (arr[i] == 0) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}