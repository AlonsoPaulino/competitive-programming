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
#define MAX 10000
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = (1LL << 60);

int n, m, t;

struct cmp {
    bool operator() (const pill &a, const pill &b) {
        return a.se > b.se;
    }
};

ll dijkstra(int root, vector<pill> ady[]) {
    priority_queue< pill, vector<pill>, cmp > pq;
    vector<ll> dist(n * m + 5, INF);
    vb visited(n * m + 5, false);
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
    return dist[n * m - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        ll ans = 0;
        vector< pill > ady[n * m + 5];
        ll aux[n + 1][m + 1];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> aux[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j > 0) {
                    ady[i * m + j].pb(mp(i * m + j - 1, aux[i][j - 1])); 
                }
                if (j + 1 < m) {
                    ady[i * m + j].pb(mp(i * m + j + 1, aux[i][j + 1]));    
                }
                if (i > 0) {
                    ady[i * m + j].pb(mp((i - 1) * m + j, aux[i - 1][j]));
                }
                if (i + 1 < n) {
                    ady[i * m + j].pb(mp((i + 1) * m + j, aux[i + 1][j])); 
                }
            }
        }
        ans = dijkstra(0, ady) + aux[0][0];
        cout << ans << "\n";
    }
}