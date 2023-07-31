#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    int yay = 0, whoops = 0;
    map<char, int> mess, news;
    for (int i = 0; i < s.size(); i++) {
        ++mess[s[i]];
    }
    for (int i = 0; i < t.size(); i++) {
        ++news[t[i]];
    }
    for (int i = 0; i < s.size(); i++) {
        int min_num = min(mess[s[i]], news[s[i]]);
        mess[s[i]] -= min_num;
        news[s[i]] -= min_num;
        yay += min_num;
    }
    for (int i = 0; i < s.size(); i++) {
        if (mess[s[i]] != 0) {
            int min_num;
            if (s[i] <= 'z' && s[i] >= 'a') {
                min_num = min(mess[s[i]], news[s[i] - 32]);
                mess[s[i]] -= min_num;
                news[s[i] - 32] -= min_num;
                whoops += min_num;
            }
            else if (s[i] <= 'Z' && s[i] >= 'A') {
                min_num = min(mess[s[i]], news[s[i] + 32]);
                mess[s[i]] -= min_num;
                news[s[i] + 32] -= min_num;
                whoops += min_num;
            }
        }
    }
    cout << yay << " " << whoops;
    return 0;
}