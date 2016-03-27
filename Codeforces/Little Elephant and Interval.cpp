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
#define MAX 17
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

ull v[MAX], l, r, nl, nr, aux;

void init() {
	v[0] = 1, v[1] = 10;
	for (int i = 2; i < MAX; ++i) {
		v[i] = v[i-1] * 10;
	}
}

ull dg(ull n) {
	ull d = 0;
	while (n > 0) n /= 10, ++d;
	return d;
}

ull fd(ull n) {
	ull d;
	while (n > 0) d = n % 10, n /= 10;
	return d;
}

ull pw(ull b, ull e) {
	if (e == 0) return 1;
	if (e == 1) return b;
	if (e & 1) return b * pw(b, e-1);
	else return pw(b, e/2) * pw(b, e/2);
}

bool isValid(ull n) {
	return (fd(n) == (n % 10));
}

ull toup(ull n) {
	ull nfd = fd(n) + 1;
	ull ndg = dg(n);
	if (nfd == 10) nfd = 1, ++ndg;
	if (ndg == 1) return nfd;
	return (nfd * pw(10, ndg - 1)) + nfd;
}

ull todown(ull n) {
	ull nfd = fd(n) - 1;
	ull ndg = dg(n);
	if (nfd == 0 && ndg > 1) nfd = 9, --ndg;
	if (ndg == 1) return nfd;
	return (nfd * pw(10, ndg - 1)) + nfd;
}

int main() {
	ios::sync_with_stdio(false);
	init();
	while (cin >> l >> r) {
		ull ans = 0;
		while (!isValid(l)) ++l;
		while (!isValid(r)) --r;
		aux = nl = toup(l), nr = (todown(r));
		while (aux <= nr) {
			if (dg(aux) < 3) ++ans;
			else ans += v[dg(aux) - 2];
			aux = toup(aux);
		}
		if (l < r) {
			if (dg(l) == dg(r) && fd(l) == fd(r)) {
				if (dg(l) > 2) {
					ull tmp = (pw(10, dg(l) - 1) * (fd(l) + 1))  - (10 - fd(l));
					tmp = min(tmp, r);
					ans += (((tmp - l)/10) + 1);
				} else {
					ans += 2;
				}
			} else {
				if (dg(l) > 2) {
					ull tmp1 = (pw(10, dg(l) - 1) * (fd(l) + 1))  - (10 - fd(l));
					ans += (((tmp1 - l)/10) + 1);
				} else {
					++ans;
				}
				if (dg(r) > 2) {
					ull tmp2 = (pw(10, dg(r) - 1) * fd(r)) + fd(r);
					ans += (((r - tmp2)/10) + 1);
				} else {
					++ans;
				}
			}
		} else if (l == r) {
			ans = 1;
		}
		cout << ans << "\n";
	}
}