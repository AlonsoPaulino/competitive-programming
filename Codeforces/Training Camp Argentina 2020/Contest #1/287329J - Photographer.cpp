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

bool cmp(pair<ll, ll> p1, pair<ll, ll> p2) {
    return p1.fi < p2.fi;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    ll n, d, a, b, x, y;
    cin >> n >> d;
    cin >> x >> y;

    vector<pair<ll, ll>> v;
    vll ans;

    for (ll i = 1; i <= n; ++i) {
        cin >> a >> b;
        int ta = a * x, tb = b * y;
        v.pb({ta + tb, i});
    }

    sort(all(v), cmp);
    int acum = 0;
    for (int i = 0; i < sz(v); ++i) {
        if (acum + v[i].fi > d) break;
        acum += v[i].fi;
        ans.pb(v[i].se);
    }

    cout << sz(ans) << endl;
    for (int i = 0; i < sz(ans); ++i) {
        cout << ans[i] << (i + 1 < sz(ans) ? " " : "\n");
    }
}
