#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int n, a, v[MAX];

int main() {
	while (cin >> n) {
		memset(v, 0, sizeof(v));
		for (int i = 0; i < n; ++i) {
			cin >> a;
			v[a]++;	
		}
		int limit = (n + 1) / 2;
		bool ans = true;
		for (int i = 1; i < MAX && ans; ++i) {
			if (v[i] > limit) ans = false;
		}
		cout << ((ans) ? "YES" : "NO") << endl;
	}
}

