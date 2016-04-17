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

int a, b, t;
string s;

int main() {
	cin >> t;
	while (t--) {
		bool ans = 0;
		cin >> a >> s >> b;
		if (s == "<" && a < b) ans = 1;
		if (s == "<=" && a <= b) ans = 1;
		if (s == "==" && a == b) ans = 1;
		if (s == ">" && a > b) ans = 1;
		if (s == ">=" && a >= b) ans = 1;
		if (s == "!=" && a != b) ans = 1;
		cout << ((ans) ? "true" : "false") << "\n";
	}
}