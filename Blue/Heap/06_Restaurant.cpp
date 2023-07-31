#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int type, x, nreviews = 0;
    priority_queue<int> pqMax;
    priority_queue<int, vector<int>, greater<int>> pqMin;
    vector<int> store;
    while (n--) {
        cin >> type;
        if (type == 1) {
            cin >> x;
            pqMax.push(x);
            ++nreviews;
        }
        else {
            if (pqMax.size() < 3) {
                cout << "No reviews yet" << endl;
            }
            else {
                for (int i = 0; i < nreviews / 3; i++) {
                    if (pqMin.size() < nreviews / 3) {
                        pqMin.push(pqMax.top());
                        pqMax.pop();
                    }
                    else if (pqMax.top() > pqMin.top()) {
                        int topMax = pqMax.top();
                        int topMin = pqMin.top();
                        pqMin.pop(); pqMax.pop();
                        pqMax.push(topMin);
                        pqMin.push(topMax);
                    }
                }
                cout << pqMin.top() << endl;
            }
        }
    }
    return 0;
}