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

const ll INF = (1LL << 60);

struct cmp {
    bool operator() (const pill &p1, const pill &p2) {
        return p1.se > p2.se;
    }
};

ll dijkstra(int root, int dest, vector< pill > ady[], int n) {
    priority_queue< pill, vector< pill >, cmp> pq;
    vll dist(n + 5, INF); vb visited(n + 5);
    dist[root] = 0;
    pq.push(mp(root, 0));
    while (!pq.empty()) {
        pill front = pq.top(); pq.pop();
        int u = front.fi;
        for (int i = 0; i < sz(ady[u]); ++i) {
            int v = ady[u][i].fi;
            ll d = ady[u][i].se;
            if (!visited[v] && dist[u] + d < dist[v]) {
                dist[v] = dist[u] + d;
                pq.push(mp(v, dist[v]));
            }
        }
        visited[u] = 1;
    }
    return dist[dest];
}

int c, t, n, m, s, x, y, w;

int main() {
    ios::sync_with_stdio(false);
    cin >> c;
    for (int k = 1; k <= c; ++k) {
        cin >> n >> m >> s >> t;
        vector< pill > ady[n + 5];
        for (int i = 0; i < m; ++i) {
            cin >> x >> y >> w;
            ady[x].pb(mp(y, w));
            ady[y].pb(mp(x, w));
        }
        ll ans = dijkstra(s, t, ady, n);
        cout << "Case #" << k << ": ";
        if (ans >= INF) {
            cout << "unreachable\n";
        } else {
            cout << ans << "\n";
        }
    }
}