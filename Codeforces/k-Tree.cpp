#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
#define mp make_pair
#define pb push_back
#define popb pop_back
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
#define MOD 1000000007
#define MAX 101
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n, k, d;

ll sum(ll a, ll b) {
	return (a % MOD + b % MOD) % MOD;
}

ll dp[MAX][2];

ll solve() {
	mset2dd(dp, 0, MAX, 2);
	dp[n][1] = 1, dp[n][0] = 0;
	for (int i = n-1; i >= 0; --i) {
		int aux = 0;
		for (int j = i+1; j <= n && aux < k; ++j, ++aux) {
			dp[i][1] = sum(dp[i][1], dp[j][1]);
			if (j - i < d) {
				dp[i][0] = sum(dp[i][0], dp[j][0]);
			} else {
				dp[i][0] = sum(dp[i][0], dp[j][1]);
			}
		}
	}
	return dp[0][0];
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> k >> d) {
		cout << solve() << "\n";
	}
	return 0;
}