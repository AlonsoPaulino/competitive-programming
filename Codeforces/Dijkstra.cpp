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
#define MAX 100000
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const ll INF = (1LL << 60);

int n, m, a, b;
ll w;
vector < pill > g[MAX + 5];

struct Node {
    int v;
    ll dist;
    Node(int v, ll dist) : v(v), dist(dist) {}
};

bool operator < (const Node &a, const Node &b) { 
    return a.dist > b.dist; 
}

void add(int x, int y, ll w) {
    g[x].pb(mp(y, w));
    g[y].pb(mp(x, w));
}

vi dijkstra(int root) {
    priority_queue< Node > pq;
    vi visited(n + 5), parent(n + 5, -1), ans;
    vll dist(n + 5, INF);

    dist[root] = 0;
    pq.push(Node(root, 0));

    while (!pq.empty()) {
        Node front = pq.top(); pq.pop();
        int u = front.v;
        if (visited[u]) continue;
        for (int i = 0; i < sz(g[u]); ++i) {
            int v = g[u][i].fi;
            ll d = g[u][i].se;
            if (!visited[v] && dist[u] + d < dist[v]) {
                dist[v] = dist[u] + d;
                parent[v] = u;
                pq.push(Node(v, dist[v]));
            }
        }
        visited[u] = 1;
    }
    if (dist[n] >= INF) {
        ans.pb(-1);
        return ans;   
    }
    int u = n;
    ans.pb(u);
    while (parent[u] != -1) {
        ans.pb(parent[u]);
        u = parent[u];
    }
    reverse(all(ans));
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        add(a, b, w);
    }
    vi ans = dijkstra(1);
    for (int i = 0; i < sz(ans); ++i) {
        cout << ans[i] << (i + 1 < sz(ans) ? " " : "\n");
    }
}
