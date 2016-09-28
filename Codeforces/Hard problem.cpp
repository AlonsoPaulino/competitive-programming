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
#define MAX 100000
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = (1LL << 60);

vi weights(MAX + 3);
vs words(MAX + 3);
vs revwords(MAX + 3);
ll dp[MAX + 3][2];
ll n, c;

inline string rev(string s) {
    string r = s;
    reverse(all(r));
    return r;
}

int main() {
    cin >> n;
    for (int i = 0; i < 2 * n; ++i) {
        if (i < n) {
            cin >> weights[i];
        } else {
            cin >> words[i - n];
            revwords[i - n] = rev(words[i - n]);
        }
    }
    dp[0][0] = 0;
    dp[0][1] = weights[0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = dp[i][1] = INF;
        if (words[i] >= words[i - 1]) {
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        }
        if (words[i] >= revwords[i - 1]) {
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        }
        if (revwords[i] >= words[i - 1]) {
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + weights[i]);
        }
        if (revwords[i] >= revwords[i - 1]) {
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + weights[i]);
        }
    }
    ll ans = min(dp[n - 1][0], dp[n - 1][1]);
    if (ans >= INF) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
}