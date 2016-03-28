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

int n, k;

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> k) {
		if (k > (n *n + 1) / 2) {
			cout << "NO" << "\n";
		} else {
			int aux = 0;
			cout << "YES" << "\n";
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (aux < k && ((!(i & 1) && !(j & 1)) || ((i & 1) && (j & 1)))) {
						cout << "L";
						++aux;
					} else {
						cout << "S";
					}
				}
				cout << "\n";
			}
		}
	}
}