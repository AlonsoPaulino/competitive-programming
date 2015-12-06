#include <bits/stdc++.h>
#define MAX 1005
#define sz(x) x.size()
using namespace std;

string s1, s2;
int dp[MAX][MAX], n, m;

void init() {
	for (int i = 0; i < MAX; ++i) {
		dp[0][i] = 0;
		dp[i][0] = 0;
	}
}

int main() {
	while (getline(cin, s1)) {
		getline(cin, s2);
		init();
		n = sz(s1), m = sz(s2);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if (s1[i-1] == s2[j-1]) {
					dp[i][j] = dp[i-1][j-1] + 1;
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		cout << dp[n][m] << endl;
	}
	return 0;
}