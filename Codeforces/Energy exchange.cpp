#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) ((int) x.size())
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
#define MAX 10001
#define ERR 0.0000000001
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

double ans, ls, li;
int n, k;
vi v(MAX);

int main() {
	while (cin >> n >> k) {
		li = 1001, ls = -1;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			ls = (v[i] > ls) ? v[i] : ls;
			li = (v[i] < li) ? v[i] : li;
		}
		if (li == ls) {
			ans = ls;
		} else {
			while (li < ls) {
				ans = (li + ls) / 2.0;
				double aux = 0.0;
				for (int i = 0; i < n; ++i) {
					if (v[i] > ans) {
						aux += (v[i] - ans);
					} else if (v[i] < ans) {
						aux += -1.0 * ((100.0 * (ans - v[i])) / (100.0 - k));
					}
				}
				if (aux <= ERR && aux >= -1.0 * ERR) break;
				aux < 0.0 ? ls = ans : li = ans;
			}
		}
		printf("%.9lf\n", ans);
	}
}