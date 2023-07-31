#include <vector>
#include <iostream>
using namespace std;

int main() {
  vector<int> v;
  int n, count = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  for (int i = 0; i < n; i++) {
    if (v[i] == 1) {
      ++count;
    }
  }

  if ((count == n - 1 && n > 1) || (n == 1 && count == 1)) {
    cout << "YES";
  }
  else {
    cout << "NO";
  }
}