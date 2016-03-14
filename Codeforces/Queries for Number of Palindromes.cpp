#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) ((int) x.size())
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vpii vector<pii>
#define mp make_pair
#define pb push_back
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cout<<#x<<":"<<x<<endl
#define debug2(x,y) cout<<#x<<":"<<x<<"&"<<#y<<":"<<y<<endl
#define test() cout<<"hola papa"<<endl
#define MAX 5002
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

string s;
int dp[MAX][MAX], t, l, r, n;
int ans[MAX][MAX];

inline void init() {
	mset2d(dp, 0, MAX);
	mset2d(ans, 0, MAX);
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j <= i; ++j) {
			dp[i][j] = 1;
		}
		ans[i][i] = 1;
	}
}

inline void solve() {
	n = sz(s);
	for (int i = n-2; i >= 0; --i) {
		for (int j = i+1; j < n; ++j) {
			if (s[i] == s[j] && dp[i+1][j-1] == 1) {
				dp[i][j] = 1;
			} else {
				dp[i][j] = 0;
			}
		}
	}
	for (int i = n-2; i >= 0; --i) {
		for (int j = i+1; j < n; ++j) {
			if (dp[i][j] == 1) {
				ans[i][j] = ans[i][j-1] + ans[i+1][j] - ans[i+1][j-1] + 1;
			} else {
				ans[i][j] = ans[i][j-1] + ans[i+1][j] - ans[i+1][j-1];
			}
		}
	}
}

int main() {
	init();
	cin >> s;
	solve();
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &l, &r);
		printf("%d\n", ans[l-1][r-1]);	
	}
}