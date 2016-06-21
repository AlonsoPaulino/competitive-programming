#include <bits/stdc++.h>
#define vi vector<int>
#define MAX 100001
using namespace std;

int n, ans = 0;
vi v(MAX + 5, 0), acum(MAX + 5, 0);

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n + 1; ++i) {
		cin >> v[i];
		acum[i] = acum[i - 1] + v[i];
	}
	for (int i = 1; i < n; ++i) {
		if (acum[i] == (acum[n] - acum[i])) {
			++ans;
		}
	}
	cout << ans << endl;
}
