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

int t, n, c = 1;
vll f;

int fibo(int x) {
    int k = 0, cnt = 0;

    while (f[k + 1] <= x && k + 1< sz(f)) ++k;

    while (x > 0) {
        ++cnt;
        x = x - f[k];

        while (f[k] > x) --k;
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> t;

    ll x = 1, y = 2;
    f.pb(x), f.pb(y);

    while (x + y < 2000000001) {
        ll z = x + y;
        f.pb(z);
        x = y;
        y = z;
    }

    while (t--) {
        cin >> n;

        ll ans = 1;
        int xi;

        for (int i = 0; i < n; ++i) {
            cin >> xi;

            ans *= fibo(xi);
        }

        cout << "Case " << c++ << ": " << ans << "\n";
    }
}
