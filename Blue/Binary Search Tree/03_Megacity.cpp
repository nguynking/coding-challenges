#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s, x, y, people;
    double r;
    cin >> n >> s;
    map<double, int> location;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> people;
        r = x * x + y * y;
        if (location.find(r) != location.end()) {
            location[r] += people;
        }
        else {
            location[r] = people;
        }
    }
    map<double, int>::iterator it;
    for (it = location.begin(); it != location.end(); it++) {
        s += it->second;
        if (s >= 1000000) {
            cout << fixed << setprecision(6) << sqrt(it->first);
            return 0;
        }
    }
    cout << -1;
    return 0;
}