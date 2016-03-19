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
#define MAX 51
#define INF 1 << 9
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n, m, ans;

int main() {
	while (cin >> n >> m) {
		vi v(m);
		for (int i = 0; i < m; ++i) cin >> v[i];
		sort(v.begin(), v.end());
		ans = v[n - 1] - v[0];
		for (int i = 1; i < m - n + 1; ++i) ans = min(ans, v[i + n - 1] - v[i]);
		printf("%d\n", ans);
	}
}