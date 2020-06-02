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
#define MAX 100001
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

bool possible;
int aux, n, sum;
vi a(MAX, 0), v(10);

int main() {
	while (cin >> n) {
		possible = 0, sum = 0, aux = MAX + 1;
		for (int i = 1; i < 10; ++i) {
			cin >> v[i];
			a[v[i]] = i;
			aux = min(v[i], aux);
			if (v[i] <= n) possible = 1;
		}
		if (possible) {
			string ans = "";
			for (int i = 0; i < n/aux; ++i) {
				ans += (a[aux] + '0');
				sum += v[a[aux]];	
			}
			aux = 9;
			for (int i = 0; i < sz(ans); ++i) {
				while (aux > 0 && sum - v[ans[i] - '0'] + v[aux] > n) --aux;
				if (aux > (ans[i] - '0') && sum - v[ans[i] - '0'] + v[aux] <= n) {
					sum = sum - v[ans[i] - '0'] + v[aux];
					ans[i] = (aux + '0');
				}
			}
			cout << ans << "\n";
		} else {
			cout << "-1" << "\n";
		}
	}
}