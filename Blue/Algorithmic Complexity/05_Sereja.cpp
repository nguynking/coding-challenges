#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> card;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        card.push_back(x);
    }
    int end = n - 1, start = 0;
    int ser = 0, dim = 0;
    bool flag = true;
    while (end != start) {
        if (flag == true) {
            if (card[end] > card[start]) {
                ser += card[end];
                --end;
            }
            else {
                ser += card[start];
                ++start;
            }
            flag = false;
        }
        else {
            if (card[end] > card[start]) {
                dim += card[end];
                --end;
            }
            else {
                dim += card[start];
                ++start;
            }
            flag = true;
        }
    }
    if (flag) {
        ser += card[end];
    }
    else dim += card[end];
    cout << ser << " " << dim;
    return 0;
}