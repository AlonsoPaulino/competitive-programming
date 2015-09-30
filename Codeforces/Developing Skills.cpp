#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

typedef unsigned long long ull;

int n, k, a , r;
ull ans;
vector<int> v(MAX);

bool my_sort(int a, int b){
	int mb, ma;
	ma = (10 - (a % 10));
	mb = (10 - (b % 10));
	return (mb > ma);
}

int main() {
	while (cin>>n>>k) {

		ans = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}

		sort(v.begin(), v.begin() + n, my_sort);

		for (int i = 0; i < n; ++i) {
			if (k > 0) {
				if (v[i] < 100) {
					r = (10 - (v[i] % 10));
					if (r <= k) {
						v[i] += r;
						k -= r;
					}
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			if (k > 9) {
				r = 0;
				while ((v[i] + 10) <= 100 && (r + 10) <= k) {
					v[i] += 10;
					r += 10;
				}
				k -= r;
			}
			ans += (int) (v[i] / 10);
		}
		
		cout << ans << endl;
	}
}