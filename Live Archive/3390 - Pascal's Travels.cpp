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
#define mod(x, m) ((x % m) + m) % m
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

const int N = 34;

int n;
string m[N + 5];
ull dp[N + 5][N + 5];

int main() {   
    while (cin >> n) {
        if (n == -1) break;
        for (int i = 0; i < n; ++i) {
            cin >> m[i];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = (i == 0 && j == 0 ? 1LL : 0LL);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != 0 || j != 0) {
                    for (int k = 0; k < i; ++k) {
                        if (((m[k][j] - '0') + k) == i) {
                            dp[i][j] += dp[k][j];
                        }
                    }
                    for (int k = 0; k < j; ++k) {
                        if ((m[i][k] - '0') + k == j) {
                            dp[i][j] += dp[i][k];
                        }
                    }
                }
            }
        }
        cout << dp[n - 1][n - 1] << "\n";
    }
    return 0;
}