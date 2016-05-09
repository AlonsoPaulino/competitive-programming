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
#define all(v) v.begin(),v.end()
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
#define MAX 101
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n, s, t, x, y;
vi v(MAX);

int main() {
	while (cin >> n) {
		x = 0, y = 0;
		for (int i = 0; i < n; ++i) cin >> v[i];
		cin >> s >> t;
		if (s > t) swap(s, t);
		for (int i = s - 1; i < t - 1; ++i) x += v[i];
		for (int i = t - 1; i < n; ++i) y += v[i];
		for (int i = 0; i < s - 1; ++i) y += v[i];
		cout << min(x, y) << endl;
	}
}
