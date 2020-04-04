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
#define MOD 1000000007
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int t, n, k;
string s;

ll mul(ll a, ll b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll pw(ll a, int b) {
    ll r = 1;
    a %= MOD;

    while (b > 0) {
        if (b & 1) r = mul(r, a);
        b >>= 1;
        a = mul(a, a);
    }

    return r;
}

ll sum(ll a, ll b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

int main() {
    freopen("class_treasurer.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> t;
    for (int c = 1; c <= t; ++c) {
        cin >> n >> k >> s;
        int cnt = 0;
        long long ans = 0LL;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == 'A') cnt--; else cnt++;
            if (cnt > k) {
                cnt = cnt - 2;
                ll d = pw(2, i + 1);
                ans = sum(ans, d);
            }
            if (cnt < 0) cnt = 0;
        }
        ans %= MOD;
        cout << "Case #" << c << ": " << ans << "\n";
    }
}