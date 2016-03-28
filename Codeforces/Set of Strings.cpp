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

int k;
string s;

int main() {
	ios::sync_with_stdio(false);
	while (cin >> k >> s) {
		if (k > sz(s)) {
			cout << "NO" << "\n";
		} else if (k == 1){
			cout << "YES" << "\n";
			cout << s << "\n";
		} else {
			vector<bool> v(30, 0);
			vector<string> ans;
			int cont = 0;
			string aux = "";
			aux += s[0], v[s[0] - 'a'] = 1;
			for (int i = 1; i < sz(s); ++i) {
				if (cont < k - 1) {
					if (v[s[i] - 'a']) {
						aux += s[i];
					} else {
						ans.pb(aux);
						aux = "", aux += s[i], ++cont;
						v[s[i] - 'a'] = 1;
						if (i + 1 == sz(s)) ++cont, ans.pb(aux);
					}
				} else {
					aux += s[i];
					if (i + 1 == sz(s)) ++cont, ans.pb(aux);
				}
			}
			if (cont == k) {
				cout << "YES" << "\n";
				for (int i = 0; i < sz(ans); ++i) {
					cout << ans[i] << "\n";
				}
			} else {
				cout << "NO" << "\n";
			}
		}
	}
}