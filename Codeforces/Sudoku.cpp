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
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

bool ans;
int t;

int main() {
	cin >> t;
	while (t--) {
		string s; ans = 1;
		vector< set<int> > v1(9);
		vector< set<int> > v2(9);
		vector< set<int> > v3(9);	
		for (int i = 0; i < 9; ++i) {
			cin >> s;
			for (int j = 0; j < 9; ++j) {
				v1[i].insert(s[j] - '0');
				v2[j].insert(s[j] - '0');
				if (i < 3) {
					v3[j/3].insert(s[j] - '0');
				} else if (i < 6) {
					v3[3 + j/3].insert(s[j] - '0');
				} else {
					v3[6 + j/3].insert(s[j] - '0');
				}
			}
		}
		for (int i = 0; i < 9 && ans; ++i) {
			if (sz(v1[i]) != 9 || sz(v2[i]) != 9 || sz(v3[i]) != 9) ans = 0;
		}
		cout << ((ans) ? "Valid" : "Invalid") << "\n";
	}
	return 0;
}