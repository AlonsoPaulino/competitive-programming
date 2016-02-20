#include <bits/stdc++.h>
#define vull vector<unsigned long long>
typedef unsigned long long ull;
using namespace std;

int n, x;
ull ans;

int main() {
	while (cin >> n >> x) {
		vull v(n);
		ans = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < n; ++i) {
			ans += v[i] * x;
			if (x > 1) x--;
		}
		cout << ans << endl;
	}
}