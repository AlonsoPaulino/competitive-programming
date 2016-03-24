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

int ans1, ans2, aux,  r, g, b;

int main() {
	ios::sync_with_stdio(false);
	while (cin >> r >> g >> b) {
		ans1 = ans2 = r / 3 + g / 3 + b / 3;
		ans1 += min(r % 3, min (g % 3, b % 3));
		aux = max(r % 3, max(g % 3, b % 3));
		if (r % 3 + 3 <= r && g % 3 + 3 <= g && b % 3 + 3 <= b) {
			if (r % 3 < aux) --ans2; 
			if (g % 3 < aux) --ans2;
			if (b % 3 < aux) --ans2;
			ans2 += aux;
		}
		printf("%d\n", max(ans1, ans2));
	}
}