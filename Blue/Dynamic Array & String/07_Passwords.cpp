#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> password;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        password.push_back(s);
    }
    string v_pass;
    cin >> v_pass;
    vector<int> count(101);
    for (int i = 0; i < n; i++) {
        ++count[password[i].length()];
    }
    int sum = 0;
    for (int i = 0; i < v_pass.length(); i++) {
        sum += count[i];
    }
    int max_tries = sum + count[v_pass.length()];
    if (max_tries % k == 0) {
        cout << sum + (sum / k) * 5 + 1 << " " << max_tries + (max_tries / k) * 5 - 5;
    }
    else {
        cout << sum + (sum / k) * 5 + 1 << " " << max_tries + (max_tries / k) * 5;
    }
    return 0;

    // time complexity O(N), space complexity O(N)
}