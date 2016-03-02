#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) x.size()
#define vi vector<int>
#define vb vector<bool>
#define mp make_pair
#define pb push_back
#define all(v) v.begin, v.end()
#define debug(x) cout<<#x<<":"<<x<<endl
#define debug2(x,y) cout<<#x<<":"<<y<<"&"<<#y<<":"<<y<<endl
#define test() cout<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int k, l, m, n, d;

int main() {
	while (cin >> k >> l >> m >> n >> d) {
		int ans = 0;
		vb bs(d+1);
		for (int i = 0; i <= d; ++i) bs[i] = 1;
		for (int i = 0; i <= d; i += k) bs[i] = 0;
		for (int i = 0; i <= d; i += l) bs[i] = 0;
		for (int i = 0; i <= d; i += m) bs[i] = 0;
		for (int i = 0; i <= d; i += n) bs[i] = 0;
		for (int i = 1; i <= d; ++i) if (!bs[i]) ++ans;
		cout << ans << endl;
	}
}