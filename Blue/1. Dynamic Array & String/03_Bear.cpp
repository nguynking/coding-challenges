#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> v;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int time;
        cin >> time;
        v.push_back(time);
    }
    v.push_back(90);

    int minutes = 0;
    for (int i = 0; i <= n; i++) {
        if (v[i] - minutes <= 15) {
            minutes = v[i];
        }
        else {
            minutes += 15;
            break;
        }
    }

    cout << minutes;
}