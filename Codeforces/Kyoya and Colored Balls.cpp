#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define pss pair<string, string>
#define mii map<int, int>
#define vi vector<int>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vpii vector<pii>
#define vpss vector<pss>
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
#define MAX 1001
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int k;
ll dp[MAX][MAX];

ll mod(ll a) {
	return a % MOD;
}

ll sum(ll a, ll b) {
	return mod(mod(a) + mod(b));
}

ll mul(ll a, ll b) {
	return mod(mod(a) * mod(b));
}

void initdp() {
	for (int i = 0; i < MAX; ++i) dp[i][0] = dp[i][i] = 1;
	for (int i = 1; i < MAX; ++i) {
		for (int j = 1; j < MAX; ++j) {
			dp[i][j] = sum(dp[i-1][j-1],dp[i-1][j]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	initdp();
	while (cin >> k) {
		vector<ll> v(k);
		ll ans = 1, aux = 0;
		for (int i = 0; i < k; ++i) cin >> v[i];
		aux = v[0];
		for (int i = 1; i < k; ++i) {
			aux += v[i];
			ans = mul(ans, dp[aux-1][v[i]-1]);
		}
		cout << ans << "\n";
	}
}