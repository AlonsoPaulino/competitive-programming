#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, k, t;

int main() {
	while (cin >> n >> k >> t) {
		t = (t * k * n) / 100;
		for (int i = 0; i < n; ++i) {
			if (t >= 0) {
				if (t >= k) {
					cout << k;
				} else {
					cout << t;
				}
				t -= k;
			} else {
				cout << 0;
			}
			if (i != n-1) cout << " ";
		}
		cout << endl;
	}
}