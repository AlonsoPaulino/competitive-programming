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

const int MOD = 1000000007;

int h, w;

ll fastExp(int e) {
    if (e == 0LL) return 1LL;
    if (e == 1LL) return 2LL;
    if (e & 1LL) return (2LL * (fastExp(e - 1) % MOD)) % MOD;
    return ((fastExp(e / 2LL) % MOD) * (fastExp(e / 2LL) % MOD)) % MOD;
}

int main() {
    cin >> h >> w;

    vi vh(h + 5), vw(w + 5);

    for (int i = 0; i < h; ++i) cin >> vh[i];
    for (int i = 0; i < w; ++i) cin >> vw[i];

    int e = 0;
    ll ans = 0;
    bool valid = true;
 
    for (int i = 0; i < h && valid; ++i) {
        for (int j = 0; j < w && valid; ++j) {
            int r = vh[i];
            int c = vw[j];

            int cr = (j < r) ? 1 : (j == r ? 0 : 2);
            int cc = (i < c) ? 1 : (i == c ? 0 : 2);

            if (cr == 2 && cc != 2) cr = cc;
            if (cc == 2 && cr != 2) cc = cr;

            if (cr == 2 && cc == 2) {
                e++;
            } else if (cr != cc) {
                valid = false;
            }
        }
    }

    if (valid) ans = fastExp(e);

    cout << ans << "\n";
}

