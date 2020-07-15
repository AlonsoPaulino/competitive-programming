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

ll f(ll k, ll m) {
    ll t = (k * (k + 1LL)) / 2LL - 1LL;
    ll x = k - m;
    ll r = (x * (x + 1LL)) / 2LL - 1LL;
    return t - r;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;
    if (n == 1LL) {
        cout << "0\n";
    } else if (n <= k) {
        cout << "1\n";
    } else {
        ll r = k;
        ll l = 2LL;
        while (l <= r) {
            ll m = l + (r - l) / 2LL;
            ll x = f(k, m) - m + 1LL;
            if (x >= n) {
                r = m - 1LL;
            } else {
                l = m + 1LL;
            }
        }
        debug2(l, r);
        debug2(f(k, l), f(l, r));
        if (f(k, l) - l + 1LL >= n) {
            cout << l << endl;
        } else {
            cout << "-1\n";
        }
    }
}
