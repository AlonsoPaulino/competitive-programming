#include <bits/stdc++.h>
using namespace std;

int n, t;

int main() {
	while (cin >> n >> t) {
		if (t != 10) {
			for (int i = 0; i < n; ++i) {
				cout << t;
			}
		} else {
			if (n == 1) cout << -1;
			else {
				cout << 1;
				for (int i = 1; i < n; ++i) {
					cout << 0;
				}
			}
		}
		cout << endl;
	}
}