#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
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
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int m, n;
ll kmin, kmax;

ll comb2(ll x) {
	if (x < 2) return 0;
	if (x == 2) return 1;
	return (x * (x-1)) / 2;
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m) {
		kmin = (n % m) * (comb2((n / m) + 1)) + (m - (n % m)) * comb2(n / m);
		kmax = (n != m) ? comb2(n - m + 1) : 0;
		cout << kmin << " " << kmax << "\n";
	}
}