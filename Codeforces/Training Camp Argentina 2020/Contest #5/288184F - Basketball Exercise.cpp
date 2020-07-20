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

int n;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    vll v1(n), v2(n);
    for (int i = 0; i < 2 * n; ++i) {
        if (i < n) cin >> v1[i];
        else cin >> v2[i % n];
    }
    ll dp[n + 5][2];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = v1[0];
    dp[0][1] = v2[0];

    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][1] + v1[i], dp[i - 1][0]);
        dp[i][1] = max(dp[i - 1][0] + v2[i], dp[i - 1][1]);
    }

    cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
}
