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

int n, m, k, aux, cont, orientation;

struct point {
	int x, y;
};

void printpoints(vector<point> ps) {
	cout << sz(ps);
	for (int i = 0; i < sz(ps); ++i) {
		cout << " " << ps[i].x << " " << ps[i].y;
	}
	cout << "\n";
}

point initpoint(int x, int y) {
	point pt;
	pt.x = x, pt.y = y;
	return pt;
}

void solve(vector<point> &vp, vector<int> vaux, int i, int j, int &aux) {
	++cont;
	if (cont > 0 && cont == vaux[aux]) {
		point p = initpoint(i+1, j+1);
		vp.pb(p);
		printpoints(vp);
		vp.clear();
		++aux;
	} else {
		point p = initpoint(i+1, j+1);
		vp.pb(p);
	}
}

int main() {
	ios::sync_with_stdio(false);
	while (cin >> n >> m >> k) {
		vector<int> vaux(k); aux = 0;
		for (int i = 0; i < k; ++i) {
			aux += (n * m) / k;
			if (aux <= n * m && i + 1 < k) {
				vaux[i] = aux;
			} else {
				vaux[i] = n * m;
			}
		}
		aux = 0, cont = 0, orientation = 1;
		vector<point> vp;
		for (int i = 0; i < n; ++i) {
			if (orientation == 1) {
				for (int j = 0; j < m; ++j) {
					solve(vp, vaux, i, j, aux);
				}
				orientation = -1;
			} else {
				for (int j = m - 1; j >= 0; --j) {
					solve(vp, vaux, i, j, aux);
				}
				orientation = 1;
			}
		}
	}
}