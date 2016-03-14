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

int n;
string s, aux, ans;

int main() {
	while (cin >> s) {
		aux = "", ans = "", n = sz(s);
		if (s[0] == '@' || s[n-1] == '@') {
			cout << "No solution" << "\n";
		} else {
			vs v;
			for (int i = 0; i < n; ++i) {
				if (s[i] != '@') {
					aux += s[i];
					if (i == n-1) v.pb(aux);
				} else {
					v.pb(aux);
					aux = "";
				}
			}
			n = sz(v);
			if (n < 2) {
				cout << "No solution" << "\n";	
			} else {
				bool flag = 1;
				ans += v[0], ans += "@";
				for (int i = 1; i < n-1 && flag; ++i) {
					if (sz(v[i]) <= 1) {
						flag = 0;
						break;
					}
					ans += v[i].substr(0, sz(v[i]) - 1);
					ans += ",";
					ans += v[i][sz(v[i]) - 1];
					ans += "@";
				}
				if (flag && sz(v[n-1]) > 0) {
					ans += v[n-1];	
				} else {
					flag = 0;
				}
				cout << ((flag) ? ans : "No solution") << "\n";
			}
		}
	}
}