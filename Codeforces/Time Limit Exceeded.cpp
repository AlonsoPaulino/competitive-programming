#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
#define vb vector<bool>
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
#define DIFF 32
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int t, n, v[MAX], aux;

int cmb(int x) {
	if (x < 2) return 0;
	if (x == 2) return 1;
	return (x * (x-1)) / 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		ll ans = 0;
		cin >> n; mset(v, 0);
		vi vaux;
		for (int i = 0; i < n; ++i) {
			cin >> aux;
			if (v[aux] == 0) {
				vaux.pb(aux);
			}
			++v[aux];
		}
		for (int i = 0; i < sz(vaux); ++i) {
			aux = vaux[i];
			if (v[aux] > 1) {
				ans += cmb(v[aux]);
			}
			for (int j = aux + 1; j < min(aux + DIFF, MAX); ++j) {
				if (v[j] > 0) {
					ans += (v[j] * v[aux]);
				}
			}
		}
		cout << ans << "\n";
	}
}
