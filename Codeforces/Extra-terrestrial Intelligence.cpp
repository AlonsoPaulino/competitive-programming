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

bool ans;
int n, aux, total;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	freopen("input.txt" ,"r",stdin);
	freopen("output.txt","w",stdout);
	while (cin >> n >> s) {
		ans = 1, aux = 0, total = -1;
		int i = 0;
		while (s[i] != '1') ++i; ++i;
		for (i; i < n && ans; ++i) {
			if (s[i] != '1') ++aux;
			else {
				if (total == -1) {
					total = aux;	
				} else {
					if (total != aux) ans = 0;
				}
				aux = 0;
			}
		}
		cout << ((ans) ? "YES" : "NO") << "\n";
	}
}