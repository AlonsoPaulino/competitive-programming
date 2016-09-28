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

const ll INF = 1LL << 60;

int c, m, n, e, t, a, b, w;

struct cmp {
    bool operator() (const pill &p1, const pill &p2) {
        return p1.se > p2.se;
    }
};

int dijkstra(int root, vector< pill > ady[]) {
    priority_queue< pill, vector< pill >, cmp> pq;
    vb visited(n + 5); vll dist(n + 5, INF);
    dist[root] = 0;
    pq.push(mp(root, 0));
    while (!pq.empty()) {
        pill front = pq.top(); pq.pop();
        int u = front.fi;
        if (visited[u]) continue;
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
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        if (i != root && dist[i] <= t) {
            ++ans;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> c;
    while (c--) {
        cin >> n >> e >> t >> m;
        vector< pill > ady[n + 5];
        for (int i = 0; i < m; ++i) {
            cin >> a >> b >> w;
            ady[b].pb(mp(a, w));
        }
        cout << dijkstra(e, ady) << "\n";
        if (c > 0) {
            cout << "\n";
        }
    }
}
