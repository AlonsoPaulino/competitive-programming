#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
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
#define test() cout<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

map<int, vi> m;
int nc, x, y, q, ttl, c = 1;

int bfs(int root, int carry) {
    map<int, bool> v;
    queue< pii > q;
    q.push(mp(root, carry));
    while (!q.empty()) {
        pii top = q.front();
        q.pop();
        v[top.fi] = true;
        if (top.se > 0) {
            vi childs = m[top.fi];
            for (int i = 0; i < sz(childs); ++i) {
                if (!v[childs[i]]) {
                    q.push(mp(childs[i], top.se - 1));
                }
            }
        }
    }
    return sz(m) - sz(v);
}

int main() {
    while (cin >> nc) {
        if (!nc) break;

        m.clear();
        for (int i = 0; i < nc; ++i) {
            cin >> x >> y;
            m[x].pb(y), m[y].pb(x);
        }

        while (cin >> q >> ttl) {
            if (!q && !ttl) break;

            int ans = bfs(q, ttl);
            cout << "Case " << c++ << ": " << ans << " nodes not reachable from node " << q << " with TTL = " << ttl << ".\n";
        }

    }

    return 0;
}