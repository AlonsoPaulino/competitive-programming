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
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
#define MAX 28
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;
 
string s, si;
bool possible = 0;
set<int> areas;
vb slept(MAX);
int n, m, ans, v[MAX][MAX];
 
void initSets() {
	areas.clear();
	for (int i = 0; i < MAX; ++i) {
		slept[i] = 1;
		for (int j = 0; j < MAX; ++j) {
			if (i != j) {
				v[i][j] = 0;
			} else {
				v[i][i] = 1;
			}
		}
	}
}
 
int idx(string s, int pos) {
	return s[pos] - 'A';
}
 
pair<bool, bool> checkAndUpdate(vi &vaux, int x) {
	if (slept[x]) {
		int cnt = 0;
		for (int i = 0; i < MAX; ++i) {
			if (i != x && v[x][i]) {
				if (!slept[i]) cnt++;
			}
			if (cnt >= 3) {
				vaux.pb(x);
				return mp(1, 1);
			}
		}
		return mp(0, 0);
	}
	return mp(1, 0);
}
 
int main() {
	ios::sync_with_stdio(false);
	while (cin >> n) {
		initSets(), ans = 0, possible = 0;
		cin >> m >> s;
		slept[idx(s,0)] = slept[idx(s,1)] = slept[idx(s,2)] = 0;
		areas.insert(idx(s,0));
		areas.insert(idx(s,1));
		areas.insert(idx(s,2));
		for (int i = 0; i < m; ++i) {
			cin >> si;
			v[idx(si, 0)][idx(si, 1)] = 1;
			v[idx(si, 1)][idx(si, 0)] = 1;
			areas.insert(idx(si,0));
			areas.insert(idx(si,1));
		}
		if (sz(areas) >= n) {
			while (ans < MAX + 1 && !possible) {
				set<int>::iterator it = areas.begin();
				bool flag = 1, update = 0;
				vi vaux;
				while (it != areas.end()) {
					pair<bool, bool> aux = checkAndUpdate(vaux, *it);
					flag &= aux.first;
					update |= aux.second;
					++it;
				}
				for (int i = 0; i < sz(vaux); ++i) {
					slept[vaux[i]] = 0;
				}
				if (flag) {
					possible = 1;
				}
				if (update) {
					++ans;
					if (possible) break;
				} else {
					break;
				}
			}	
		}
		if (possible) {
			cout << "WAKE UP IN, " << ans << ", YEARS\n";
		} else {
			cout << "THIS BRAIN NEVER WAKES UP\n";
		}
	}
	return 0;
}
