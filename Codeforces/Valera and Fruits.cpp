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
#define MAX 3001
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n, v, a, b, ans, aux1, aux2;

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> v) {
		vi m(MAX + 1, 0);
		ans = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			m[a] += b;
		}
		ans = min(m[0], v);
		m[0] -= ans;
		for (int i = 1; i <= MAX; ++i) {
			aux1 = min(v, m[i-1]), aux2 = 0;
			m[i-1] = m[i-1] - aux1;
			if (aux1 < v) {
				aux2 = v - aux1;
				aux2 = min(aux2, m[i]);
				m[i] = m[i] - aux2;
			}
			ans += (aux1 + aux2);
		}
		cout << ans << endl;
	}
}