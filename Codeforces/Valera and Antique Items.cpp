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
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n, v, k, sij;

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> v) {
		vector<int> ans;
		for (int i = 0; i < n; ++i) {
			cin >> k;
			bool added = 0;
			for (int j = 0; j < k; ++j) {
				cin >> sij;
				if (sij < v && !added) {
					ans.pb(i+1);
					added = 1;
				}
			}
		}
		cout << sz(ans) << "\n";
		if (sz(ans) > 0) {
			for (int i = 0; i < sz(ans); ++i) {
				cout << ans[i];
				if (i +1 < sz(ans)) {
					cout << " ";
				}
			}
		} else {
			cout << "\n";
		}
	}
}
