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

int n;

bool cmp(pii p1, pii p2) {
    if (p1.se == p2.se) return p1.fi > p2.fi;
    return p1.se > p2.se;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    vector<pii> v(n);
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        v[i] = {a, b};
    }
    sort(all(v), cmp);
    for (auto x: v) debug2(x.fi, x.se);
    int points = 0;
    int cnt = 1;
    for (int i = 0; cnt > 0 && i < n; ++i, cnt--) {
        points += v[i].fi;
        cnt += v[i].se;
    }
    cout << points << endl;
}
