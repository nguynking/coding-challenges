#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	long long n, x;
  	cin >> n >> x;
  	vector<int> time;
  	for (int i = 0; i < n; i++) {
      	int c;
      	cin >> c;
		time.push_back(c);
    }
  	sort(time.begin(), time.end());
  	long long res = 0;
  	for (int i = 0; i < n; i++) {
      	if (x - i > 1) {
          	res += time[i] * (x - i);
        }
		else res += time[i];
    }
  	cout << res;
  	return 0;
}