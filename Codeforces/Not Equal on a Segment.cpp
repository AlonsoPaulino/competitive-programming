#include <bits/stdc++.h>
#define MAX 200003
using namespace std;

int n, m, l, r, x;
int v[MAX], dp[MAX];

int main() {
	cin >> n >> m;
	memset(v, -1, sizeof(v));
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
	for (int i = 1; i < n; ++i) {
		int j = i;
		while (v[j] == v[j+1] && j < n) ++j;
		for (int k = i; k <= j; ++k) {
			dp[k] = j + 1;
		}
		i = j;
	}
	while (m--) {
		scanf("%d %d %d", &l, &r, &x);
		if (v[l] != x) {
			printf("%d\n", l);
		} else {
			if (dp[l] <= r) {
				printf("%d\n", dp[l]);
			} else {
				printf("-1\n");
			}
		}
	}
	return 0;
}
