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

const int N = 18;
const ll INF = - (1 << 18);

int n;
string a;

ll dp[2 * N + 5][N + 5][N + 5] = { INF };

ll fastexp(ll x) {
    if (x == 0) return 1;
    if (x == 1) return 10;
    if (x & 1) {
        return 10 * fastexp(x - 1);
    } else {
        return fastexp(x / 2) * fastexp(x / 2);
    }
}

ll append(ll x, ll i) {
    return fastexp(x) * (a[i] - '0');
}

int main() {
    cin >> n >> a;
    dp[0][0][0] = 0;
    for (int i = 1; i < 2 * n + 1; ++i) {
        for (int j = 0; j < i; ++j) {
            int k = i - j;
            if (k > n || j > n) continue;
            if (j > 0) {
                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + append(n - j, i - 1));
            }
            if (k > 0) {
                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + append(n - k, i - 1));
            }
        }
    }
    string ans = "";
    int h = n, m = n, i = 2 * n;
    while (h > 0 || m > 0) {
        if (h > 0 && dp[i][h][m] == dp[i-1][h-1][m] + append(n - h, i - 1)) {
            ans += "H";
            --h;
        } else {
            ans += "M";
            --m;
        }
        --i;
    }
    reverse(all(ans));
    cout << ans << "\n";
}