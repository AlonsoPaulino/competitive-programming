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

const int M = 1000000007;

int sum(int a, int b) {
    return (a % M + b % M) % M;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    string s; cin >> s; int n = sz(s);
    int ans = 0;
    vi dp(n + 5, 0);

    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'b') dp[i] = sum(dp[i + 1], 1);
        if (s[i] == 'a') {
            ans = sum(ans, dp[i + 1]);
            dp[i] = sum(dp[i + 1], dp[i + 1]);
        }
    }

    cout << ans << endl;
}
