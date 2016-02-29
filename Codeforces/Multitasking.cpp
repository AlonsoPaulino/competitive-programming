#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) ((int) x.size())
#define pii pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vpii vector<pii>
#define mp make_pair
#define pb push_back
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cout<<#x<<":"<<x<<endl
#define debug2(x,y) cout<<#x<<":"<<x<<"&"<<#y<<":"<<y<<endl
#define test() cout<<"hola papa"<<endl
#define N 1001
#define M 101
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n, m, k;
vi vd[N];
vi vo[N];
vpii ans;

bool descmp(int a, int b) {
	return b < a;
}

inline void swaparrays(int i, int x, int y) {
	for (int k = i; k < n; ++k) {
		if (vd[k][x] > vd[k][y]) {
			swap(vd[k][x], vd[k][y]);
		}
	}
}

int main() {
	while (cin >> n >> m >> k) {
		ans.clear();
		vi vdaux(m);
		vi voaux(m);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> vdaux[j];
				voaux[j] = vdaux[j];
			}
			!k ? sort(voaux.begin(), voaux.end()) : 
			sort(voaux.begin(), voaux.end(), descmp);
			vd[i] = vdaux;
			vo[i] = voaux;
		}
		int x, y;
		for (int i = 0; i < n; ++i) {
			if (!k) {
				x = y = 0;
				while (x < m) {
					if (vd[i][x] != vo[i][x]) {
						y = x + 1;
						while (y < m) {
							if (vd[i][x] > vd[i][y] && vd[i][y] != vo[i][y]) {
								swaparrays(i, x, y);
								ans.push_back(mp(x, y));
								break;
							}
							++y;
						}
					} else {
						++x;
					}
				}
			} else {
				x = y = (m - 1);
				while (x >= 0) {
					if (vd[i][x] != vo[i][x]) {
						y = x - 1;
						while (y >= 0) {
							if (vd[i][x] > vd[i][y] && vd[i][y] != vo[i][y]) {
								swaparrays(i, x, y);
								ans.push_back(mp(x, y));
								break;
							}
							--y;
						}
					} else {
						--x;
					}
				}
			}
		}
		printf("%d\n", sz(ans));
		for (int i = 0; i < sz(ans); ++i)  {
			printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
		}
	}
}