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
 
struct Env {
    int w, h, i;
    Env(int w, int h, int i) : w(w), h(h), i(i) {}
};
 
bool cmp(const Env &e1, const Env &e2) { 
    if (e1.w == e2.w) return e1.h < e2.h;
    return e1.w < e2.w;
}
 
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
 
    int n, w, h, x, y;
    cin >> n >> w >> h;
    vector<Env> v;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        if (x > w && y > h) {
            v.pb(Env(x, y, i + 1));   
        }
    }
    n = sz(v);
    if (n > 0) {
        sort(all(v), cmp);
        vector< pii > dp(n, {0, 0});
        for (int i = 0; i < n; ++i) dp[i] = { 1, i };
        for (int i = 1; i < n; ++i) {
            int x = i, lis = 1;
            for (int j = 0; j < i; ++j) {
                if (v[j].w < v[i].w && v[j].h < v[i].h && dp[j].fi + 1 > lis) {
                    lis = dp[j].fi + 1;
                    x = j;
                }
            }
            dp[i] = { lis, x };
        }
        int ians = 0;
        for (int i = 1; i < n; ++i) {
            auto x = dp[i];
            if (x.fi > dp[ians].fi) ians = i;
        }
        cout << dp[ians].fi << endl;
        vi ans; int k = ians;
        while (dp[k].se != k) ans.pb(v[k].i), k = dp[k].se;
        ans.pb(v[k].i);
        reverse(all(ans));
        for (int i = 0; i < sz(ans); ++i) {
            cout << ans[i] << (i + 1 < sz(ans) ? " " : "\n"); 
        }
    } else {
        cout << "0\n";
    }
}