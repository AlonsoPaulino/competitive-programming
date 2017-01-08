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

int n, m, x, y, li, ls;

bool cmp(pii p1, pii p2) {
    return p1.fi < p2.fi;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    while (n--) {
        cin >> m;
        vector< pii > v;
        vector< pii > ans;
        while (cin >> x >> y) {
            if (x == 0 && y == 0) break;
            v.pb(mp(x, y));
        }
        sort(all(v), cmp);
        int li = 0, ls = 0, i = 0;
        while (i < sz(v) && ls < m) {
            pii election;
            while (i < sz(v) && v[i].fi <= li) {
                if (v[i].se > ls) {
                    ls = v[i].se;
                    election = v[i];
                }
                ++i;
            }
            if (ls > li) {
                li = ls;
                ans.pb(election);
            } else {
                ans.clear();
                break;
            }
        }
        if (ls < m) ans.clear();
        cout << sz(ans) << "\n";
        for (int i = 0; i < sz(ans); ++i) {
            cout << ans[i].fi << " " << ans[i].se <<"\n";
        }
        if (n > 0) cout << "\n";
    }
}