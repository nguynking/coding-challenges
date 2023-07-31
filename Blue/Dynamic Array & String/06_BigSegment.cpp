#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Segment {
    public:
        int l;
        int r;
};

int main() {
    int n;
    cin >> n;
    vector<Segment> seg;
    for (int i = 0; i < n; i++) {
        Segment s;
        cin >> s.l >> s.r;
        seg.push_back(s);
    }
    int minl = seg[0].l; 
    int maxr = seg[0].r;
    int indexL = 1, indexR = 1;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        if (seg[i].l < minl) {
            minl = seg[i].l;
            indexL = i + 1;
        }
        if (seg[i].r > maxr) {
            maxr = seg[i].r;
            indexR = i + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (seg[i].l == minl) {
            a.push_back(i+1);
        }
        if (seg[i].r == maxr) {
            b.push_back(i+1);
        }
    }
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) {
                indexL = indexR = a[i];
            }
        }
    }
    if (indexL == indexR) {
        cout << indexL;
    }
    else {
        cout << -1;
    }
    return 0;
}