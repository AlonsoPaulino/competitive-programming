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
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cout<<#x<<" : "<<x<<endl
#define all(v) v.begin(),v.end()
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
#define test2() cout << "hola mama" << endl
#define MAX 10005
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n, c, x, y;
vector< set<int> > e(MAX);
vi f(MAX);
bool UDEBUG = 0;

inline void initSets() {
	for (int i = 0; i <= n; ++i) {
		f[i] = i;
	}
}

inline int find(int a) {
	return (a == f[a]) ? a : f[a] = find(f[a]);
}

inline void join(int a, int b) {
	f[find(a)] = find(b);
}

inline bool areFriends(int a, int b) {
	int ra = find(a), rb = find(b);
	if (e[ra].count(rb)) return 0;
	return (a == b)	|| ra == rb;
}

inline bool areEnemies(int a, int b) {
	int ra = find(a), rb = find(b);
	if (a == b || ra == rb) return 0;
	return e[ra].count(rb);
}

inline bool setFriends(int a, int b);
inline bool setEnemies(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	if (UDEBUG) {
		freopen("war.out", "w", stdout);
	}
	cin >> n;
	initSets();
	while (cin >> c >> x >> y) {
		if (c == 0 && x == 0 && y == 0) break;
		if (c == 1) {
			if (!setFriends(x, y)) {
				cout << "-1\n";
			}
		}
		if (c == 2) {
			if (!setEnemies(x, y)) {
				cout << "-1\n";
			}
		}
		if (c == 3) cout << (areFriends(x, y) ? "1\n" : "0\n");
		if (c == 4) cout << (areEnemies(x, y) ? "1\n" : "0\n");
	}
	return 0;
}

inline bool setFriends(int a, int b) {
	if (areEnemies(a, b)) return 0;
	if (!areFriends(a, b)) {
		int ra = find(a), rb = find(b);
		join(ra, rb);
		int parent = find(ra);
		set<int> era = e[ra], erb = e[rb];
		set<int>::iterator itera = era.begin(), iterb = erb.begin();
		while (itera != era.end()) {
			int aux = find(*itera);
			setEnemies(parent, aux);
			++itera;
		}
		while (iterb != erb.end()) {
			int aux = find(*iterb);
			setEnemies(parent, aux);
			++iterb;
		}
	}
	return 1;
}

inline bool setEnemies(int a, int b) {
	if (areFriends(a, b)) return 0;
	if (!areEnemies(a, b)) {
		int ra = find(a), rb = find(b);
		if (sz(e[ra]) > 0 || sz(e[rb]) > 0) {
			set<int> era = e[ra], erb = e[rb];
			set<int>::iterator itera = era.begin(), iterb = erb.begin();
			while (itera != era.end()) {
				setFriends(rb, *itera);
				++itera;
			}
			while (iterb != erb.end()) {
				setFriends(ra, *iterb);
				++iterb;
			}

		}
		int nra = find(a), nrb = find(b);
		e[nra].insert(nrb);
		e[nrb].insert(nra);
	}
	return 1;
}