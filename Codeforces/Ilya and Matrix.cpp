#include <bits/stdc++.h>
#define DEBUG(x) cout<<#x<<"->"<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"->"<<x<<" "<<#y<<"->"<<y<<endl
using namespace std;

typedef long long ll;

ll n, ans;

bool my_sort(ll a, ll b) {
	return a > b;
}

int main() {
	while (scanf("%I64d", &n) == 1) {
		int v[n];
		for (int i = 0; i < n; ++i) scanf("%I64d", v+i);
		sort(v, v + n, my_sort);
		ans = 0;
		for (int i = 1; i <= n; i*=4) {
			for (int j = 0; j < i; ++j) ans += v[j];
		}
		printf("%I64d\n", ans);
	}
}