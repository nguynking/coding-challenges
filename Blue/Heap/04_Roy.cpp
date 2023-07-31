#include <bits/stdc++.h>
using namespace std;

struct Topic {
    int id, z, cur_z, new_z;
};

struct option {
    bool operator() (const Topic &a, const Topic &b) {
        if (a.z == b.z) {
            return a.id < b.id;
        }
        return a.z < b.z;
    }
};

int main() {
    int n, id, cur_z, p, l, c, s, z, new_z;
    priority_queue<Topic, vector<Topic>, option> pq;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> id >> cur_z >> p >> l >> c >> s;
        z = (50 * p + 5 * l + 10 * c + s * 20) - cur_z;
        new_z = 50 * p + 5 * l + 10 * c + s * 20;
        pq.push((Topic) {id, z, cur_z, new_z});
    }
    for (int i = 0; i < 5; i++) {
        cout << pq.top().id << " " << pq.top().new_z << endl;
        pq.pop();
    }
    return 0;
}