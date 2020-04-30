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
#define MAX 100001
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

vector<ll> v(MAX, 0), dp(MAX, 0);
ll n, a, ls = -1;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (ll i = 0; i < n; ++i) {
		cin >> a; 
		++v[a], ls = max(ls, a);
	}
	dp[0] = 0, dp[1] = v[1];
	for (ll i = 2; i <= ls; ++i) {
		dp[i] = max(dp[i-1], dp[i-2] + (v[i] * i));
	}
	cout << dp[ls] << endl;
}

