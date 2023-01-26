#include<bits/stdc++.h>
using namespace std;

/*
- n students
- each has some positive integer rating
- the rating of i-th student as ai. Contest ends, every student will end up with some positive integer position
- students take place equal to 1 + (number of students strictly higher rating than his or her), 2 students have equal ratings --> share the same position
*/

int main() {
    int n;
    cin >> n;
    vector<int> a(n), s(n);
    int count[2001] = {0}, pos[2001] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i] = a[i];
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
        ++count[a[i]];
    }
    int sum = 0;
    for (int i = 2000; i >= 0; i--) {
        if (count[i] != 0) {
            pos[i] += sum + 1;
            sum += count[i];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << pos[a[i]] << " ";
    }
    return 0;
}