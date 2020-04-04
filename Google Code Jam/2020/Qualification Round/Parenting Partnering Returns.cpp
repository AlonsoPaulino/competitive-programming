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

int nc, n, x, y;

bool cmp(pair<pii, int > p1, pair<pii, int> p2) {
    return p1.fi.fi < p2.fi.fi;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> nc;
    for (int t = 1; t <= nc; ++t) {
        cin >> n;
        bool exist = true;
        string ans(n, 'x');
        vector< pair < pii, int > > v(n);
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            v[i] = mp(mp(x, y), i);
        }
        sort(all(v), cmp);
        int c = -1, j = -1;
        for (int i = 0; i < n; ++i) {
            pair< pii, int> p = v[i];
            if (c == -1 || c <= p.fi.fi) {
                c = p.fi.se;
                ans[p.se] = 'C';
            } else if (j == -1 || j <= p.fi.fi) {
                j = p.fi.se;
                ans[p.se] = 'J';
            } else {
                exist = false;
                break;
            } 
        }

        if (!exist) {
            cout << "Case #" << t << ": IMPOSSIBLE" << endl;
        } else {
            cout << "Case #" << t << ": " << ans << endl;
        }
    }
}
