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
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

bool flag;
int n, t, c, ans;

int main() {
	cin >> n >> t >> c;
	vi v(n);
	flag = 0, ans = 0;
	for (int i = 0; i < n; ++i) cin >> v[i];
	for (int i = 0; i < n; ++i) {
		if (!flag) {
			bool aux = 1;
			if (i + c <= n) {
				for (int j = i; j < i + c; ++j) {
					if (v[j] > t) aux = 0, i = j, j += c;
				}
				if (aux) ++ans, i = i + c - 1;
				flag = aux;
			} else {
				i = n+1;
			}
		} else {
			flag = (v[i] <= t);
			if (flag) ++ans;
		}
	}
	printf("%d\n", ans);
}