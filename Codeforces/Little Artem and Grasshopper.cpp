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
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n, aux, cont;
string s;
bool ans;

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n) {
		ans = 1, aux = 0, cont = 0;
		vi v(n);
		cin >> s;
		for (int i = 0; i < n; ++i) cin >> v[i];
		while (cont < MAX && ans) {
			if (s[aux] == '<') {
				aux -= v[aux];
			} else {
				aux += v[aux];
			}
			++cont;
			if (aux < 0 || aux >= n) ans = 0;
		}
		(ans) ? cout << "INFINITE\n" : cout << "FINITE\n";	
	}
}
