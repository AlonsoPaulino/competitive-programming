#include <bits/stdc++.h>
using namespace std;

int t, r;

int main() {
	cin >> t;
	while (t--) {
		cin >> r;
		vector<int> v(r);
		for (int i = 0; i < r; ++i) cin >> v[i];
		sort(v.begin(), v.end());
		int s = v.size();
		int a = 0, b = 0;
		if (s&1) {
			for (int i = 0; i < r; ++i) {
				a += abs(v[s/2] - v[i]);
				b = a;
			}
		} else {
			for (int i = 0; i < r; ++i) {
				a += abs(v[s/2] - v[i]);
				b += abs(v[(s/2) - 1] - v[i]);
			}
		}
		cout << min(a, b) << endl;
	}
	return 0;
}