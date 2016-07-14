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
#define MAX 25
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

string s;
int n, m;
int v[MAX + 5][MAX + 5];
bool dp[MAX + 5][MAX + 5][MAX + 5][MAX + 5];

void dpreset() {
    for (int i = 0; i < n + 2; ++i) {
        for (int j = 0; j < m + 2; ++j) {
            for (int k = 0; k < n + 2; ++k) {
                for (int z = 0; z < m + 2; ++z) {
                    dp[i][j][k][z] = 1;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int ans = 0;
    dpreset();
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        for (int j = 1; j <= m; ++j) {
            v[i][j] = s[j-1] - '0';
        }
    }
    for (int x1 = 1; x1 <= n; ++x1) {
        for (int y1 = 1; y1 <= m; ++y1) {
            for (int x2 = x1; x2 <= n; ++x2) {
                for (int y2 = y1; y2 <= m; ++y2) {
                    if (x1 == x2 && y1 == y2) {
                        if (v[x2][y2] == 0) {
                            dp[x1][y1][x2][y2] = 1;
                        } else {
                            dp[x1][y1][x2][y2] = 0;
                        }
                    } else {
                        if (v[x2][y2] == 0) {
                            if (x1 == x2) {
                                dp[x1][y1][x2][y2] = dp[x1][y1][x2][y2-1];
                            } else if (y1 == y2) {
                                dp[x1][y1][x2][y2] = dp[x1][y1][x2-1][y2];
                            } else {
                                dp[x1][y1][x2][y2] = dp[x1][y1][x2-1][y2] && dp[x1][y1][x2][y2-1];
                            }
                        } else {
                            dp[x1][y1][x2][y2] = 0;
                        }
                    }
                    if (dp[x1][y1][x2][y2]) {
                        ans = max(ans, 2 * (abs(y2 - y1 + 1) + abs(x2 - x1 + 1)));
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}
