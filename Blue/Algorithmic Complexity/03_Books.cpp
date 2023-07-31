#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> A;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }
    int max_book = 0, start_book = 0, read_time = 0;
    for (int end_book = 0; end_book < n; end_book++) {
        read_time += A[end_book];
        while (read_time > t) {
            read_time -= A[start_book];
            start_book++;
        }
        max_book = max(max_book, end_book - start_book + 1);
    }
    cout << max_book;
    return 0;
}