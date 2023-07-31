#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s, t, k;
    cin >> s >> t;
    string c = s;
    int n = s.length();
    for (int i = n - 1; i >= 0; i--) {
        while (c[i] < 'z') {
            ++c[i];
            if (c < t) {
                cout << c;
                return 0;
            }
        }
        if (c[i] == 'z') {
            c[i] = 'a';
        }
    }
    cout << "No such string";
}