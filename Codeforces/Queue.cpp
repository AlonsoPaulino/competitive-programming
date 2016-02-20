#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

int n;
long long ans;

int main() {
	while (cin >> n) {
		vi v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		ans = 1;
		int aux = v[0];
		for (int i = 1; i < n; ++i) {
			if (aux <= v[i]) {
				ans++;
				aux += v[i];
			} else {
				int j = i + 1;
				if (j < n) {
					while (v[j] < aux && j < (n - 1)) j++;
					if (aux <= v[j]) {
						ans++;
						swap(v[i], v[j]);
					}
				}
				aux += v[i];
				i = j;
			}
		}
		cout << ans << endl;
	}
}