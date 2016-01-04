#include <bits/stdc++.h>
#define vi vector<int>
#define sz(x) x.size()
#define pb push_back
#define test() cout<<"Por qué no funciona :c"<<endl;
#define DEBUG(x) cout<<#x<<" -> "<<x<<endl;
#define DEBUG2(x, y) cout<<#x<<" -> "<<x<<" & "<<#y<<" -> "<<y<<endl;
#define MAX 502
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

char v[MAX][MAX];
int dp[MAX][MAX], h, w, q, r1, c1, r2, c2, ans;

int main() {
	while (cin >> h >> w) {
		memset(v, '#', sizeof(char) * MAX * MAX);
		memset(dp, 0, sizeof(int) * MAX * MAX);
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) cin >> v[i][j];
		}
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				int aux = 0;
				if (v[i][j] == '.') {
					if (v[i-1][j] == '.') ++aux;
					if (v[i][j-1] == '.') ++aux;
				}
				dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + aux;
			}
		}
		cin >> q;
		while (q--) {
			cin >> r1 >> c1 >> r2 >> c2;
			ans = 0;
			for (int i = r1+1; i <= r2; ++i) if (v[i][c1] == '.' && v[i-1][c1] == '.') ++ans;
			for (int j = c1+1; j <= c2; ++j) if (v[r1][j] == '.' && v[r1][j-1] == '.') ++ans;
			ans += dp[r2][c2] - (dp[r2][c1] + dp[r1][c2] - dp[r1][c1]);
			cout << ans << endl;
		}
	}
}