#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) ((int) x.size())
#define pii pair<int, int>
#define pss pair<string, string>
#define mii map<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vpii vector<pii>
#define vpss vector<pss>
#define mp make_pair
#define pb push_back
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cout<<#x<<":"<<x<<endl
#define debug2(x,y) cout<<#x<<":"<<x<<"&"<<#y<<":"<<y<<endl
#define test() cout<<"hola papa"<<endl
#define MAX 1001
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int q;
string s1, s2;

int main() {
	vpss v;
	cin >> q;
	cin >> s1 >> s2;
	v.pb(mp(s1, s2)), --q;
	while (q--) {
		cin >> s1 >> s2;
		bool flag = 1;
		for (int i = 0; i < sz(v) && flag; ++i) {
			if (s1 == v[i].second) {
				v[i].second = s2;
				flag = 0;
			}
		}
		if (flag) v.pb(mp(s1, s2));
	}
	printf("%d\n", sz(v));
	for (int i = 0; i < sz(v); ++i) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}