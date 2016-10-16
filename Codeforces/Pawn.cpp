#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define pill pair<int, long long>
#define mii map<int, int>
#define vi vector<int>
#define vll vector<long long>
#define vs vector<string>
#define vb vector<bool>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define popb pop_back
#define all(v) v.begin(),v.end()
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cerr<<#x<<" : "<<x<<endl
#define debug2(x,y) cerr<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cerr<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const int K = 10;
const int N = 100;

const int L = -1;
const int R = +1;

int path[N + 5][N + 5][K + 5];
int res[N + 5][N + 5][K + 5];
int dp[N + 5][N + 5][K + 5];
int v[N + 5][N + 5];
int n, m, k, ans = -1, col = -1;

int main() {
    memset(dp, -1, sizeof(dp));
    memset(res, -1, sizeof(res));
    
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < m; ++j) {
            v[i][j] = (int) (s[j] - '0');
        }
    }

    k = k + 1;

    for (int j = 0; j < m; ++j) {
        int val = v[n - 1][j];
        dp[n - 1][j][val % k] = max(dp[n - 1][j][val % k], val);
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < m; ++j) {
            int x = v[i][j];
            for (int d = 0; d < k; ++d) {
                if (j > 0 && dp[i + 1][j + L][d] >= 0) {
                    int acum = x + dp[i + 1][j + L][d];
                    if (acum > dp[i][j][acum % k]) {
                        dp[i][j][acum % k] = acum;
                        path[i][j][acum % k] = L;
                        res[i][j][acum % k] = d;
                    }
                }
                if (j + 1 < m && dp[i + 1][j + R][d] >= 0) {
                    int acum = x + dp[i + 1][j + R][d];
                    if (acum > dp[i][j][acum % k]) {
                        dp[i][j][acum % k] = acum;
                        path[i][j][acum % k] = R;
                        res[i][j][acum % k] = d;
                    }
                }
            }
        }
    }

    for (int j = 0; j < m; ++j) {
        if (dp[0][j][0] > ans) {
            ans = dp[0][j][0];
            col = j;
        }
    }

    if (ans >= 0) {
        cout << ans << "\n";
        string s = "";
        int r = 0;
        for (int i = 0; i + 1 < n; ++i) {
            int j = col;
            if (path[i][j][r] == L) {
                col += L;
                s += "R";
            } else {
                col += R;
                s += "L";
            }
            r = res[i][j][r];
        }
        reverse(all(s));
        cout << col + 1 << "\n" << s << "\n";
    } else {
        cout << -1 << "\n";
    }
}