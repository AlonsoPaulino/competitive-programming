#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
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
#define N 3
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

vector< pii > v(N + 1);

bool right(vector< pii > points) {
    pii p1 = points[0], p2 = points[1], p3 = points[2], r, s;
    if (p1 == p2 || p2 == p3 || p1 == p3) return 0;
    r.fi = p2.fi - p1.fi, r.se = p2.se - p1.se;
    s.fi = p3.fi - p1.fi, s.se = p3.se - p1.se;
    if (r.fi * s.fi + r.se * s.se == 0) return 1;
    r.fi = p1.fi - p2.fi, r.se = p1.se - p2.se;
    s.fi = p3.fi - p2.fi, s.se = p3.se - p2.se;
    if (r.fi * s.fi + r.se * s.se == 0) return 1;
    r.fi = p2.fi - p3.fi, r.se = p2.se - p3.se;
    s.fi = p1.fi - p3.fi, s.se = p1.se - p3.se;
    if (r.fi * s.fi + r.se * s.se == 0) return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    for (int i = 0; i < N; ++i) {
        cin >> v[i].fi >> v[i].se;
    }
    if (right(v)) {
        cout << "RIGHT\n";
    } else {
        bool almost = 0;
        for (int i = 0; i < N && !almost; ++i) {
            vector< pii > aux = v;
            aux[i].fi = v[i].fi + 1;
            if (right(aux)) almost = 1;
            aux[i].se = v[i].se + 1, aux[i].fi = v[i].fi;
            if (right(aux)) almost = 1;
            aux[i].fi = v[i].fi - 1, aux[i].se = v[i].se;
            if (right(aux)) almost = 1;
            aux[i].se = v[i].se - 1, aux[i].fi = v[i].fi;
            if (right(aux)) almost = 1;
        }
        if (almost) {
            cout << "ALMOST\n";
        } else {
            cout << "NEITHER\n";
        }
    }
}