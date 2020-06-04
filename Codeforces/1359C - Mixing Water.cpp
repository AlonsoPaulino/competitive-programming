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

const int N = 1000005;

ll T, c, h, t;

double diff(double a, double b) {
    double d = a - b;
    return d < 0.0 ? -1.0 * d : d;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> h >> c >> t;
        ll ans = N;
        double av = (h + c) / 2.0;
        if (av >= t) {
            ans = 2;
        } else {
            ll l = 0, r = N;
            double d = N;
            while (l <= r) {
                ll k = l + (r - l) / 2;
                double num = (k + 1) * h + k * c;
                double den = 2 * k + 1;
                double x = (double) num / den;
                double dd = diff(x, t);
                if (dd < d) {
                    ans = 2 * k + 1;
                    d = dd;
                } else if (dd == d) {
                    ans = min(2 * k + 1, ans);
                }
                if (x > t) l = k + 1;
                else r = k - 1;
            }
        }
        cout << ans << endl;
    }
}
