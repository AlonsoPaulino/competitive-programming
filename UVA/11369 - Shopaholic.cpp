#include <bits/stdc++.h>
#define vi vector<int>
#define ll long long
using namespace std;

int t, n, p;
ll ans;

bool my_sort(int a, int b) {
	return a > b;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		vi v(n);
		ans = 0;
		for (int i = 0; i < n; ++i) cin >> v[i];
		sort(v.begin(), v.end(), my_sort);
		int i = 2;
		while (i < n) {
			ans += v[i];
			i += 3;
		}
		cout << ans << endl;
	}
	return 0;
}