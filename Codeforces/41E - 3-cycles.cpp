#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define pill pair<int, long long>
#define mii map<int, int>
#define vi vector<int>
#define vll vector<long long>
#define vs vector<string>
#define vb vector<bool>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define popb pop_back
#define all(v) v.begin(),v.end()
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cerr<<#x<<" : "<<x<<endl
#define debug2(x,y) cerr<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cerr<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const int MAX = 100;

bool ady[MAX + 5][MAX + 5] = {0};
vector<pii> ans;
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; j += 2) {
			if (!ady[i][j]) {
				ans.pb(mp(i, j));
				ady[i][j] = ady[j][i] = 1;
			}
		}
	}
	cout << sz(ans) << "\n";
	for (int i = 0; i < sz(ans); ++i) {
		cout << ans[i].fi + 1 << " " << ans[i].se + 1 << "\n";
	}
}
