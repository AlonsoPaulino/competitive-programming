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
#define MAX 1001
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

bool v[MAX][MAX], flag;
int n, m, x, y, ans;
int di[] = {0 , 0 ,  0, -1, -1, -1, -2, -2, -2};
int dj[] = {0 ,-1 , -2,  0, -1, -2,  0, -1, -2};

bool square(int si, int sj) {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			int auxi = si + di[i];
			int auxj = sj + dj[j];
			bool ans = (auxi + 2 <= n && auxj + 2 <= n);
			for (int k = auxi; ans && k < auxi + 3; ++k) {
				for (int z = auxj; ans && z < auxj + 3; ++z) {
					if (!v[k][z]) ans = false;
				}
			}
			if(ans) return ans;
		}
	}
	return false;
}

int main() {
	while (cin >> n >> m) {
		ans = -1;
		flag = 0;
		memset(v, 0, sizeof(v));
		for (int i = 0; i < m; ++i) {
			cin >> x >> y;
			v[x][y] = 1;
			if (!flag && square(x, y)) {
				ans = i + 1;
				flag = 1;
			}
		}
		cout << ans << endl;
	}
}