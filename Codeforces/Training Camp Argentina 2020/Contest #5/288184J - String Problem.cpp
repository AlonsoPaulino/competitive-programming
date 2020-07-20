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

const int INF = 1000000007;

struct Node {
    int v;
    int dist;
    Node(int v, int dist) : v(v), dist(dist) {}
};

bool operator < (const Node &a, const Node &b) { 
    return a.dist > b.dist; 
}

vector< pii > g[30];

vi dijkstra(int root) {
    priority_queue< Node > pq;
    vi visited(30);
    vi dist(30, INF);

    dist[root] = 0;
    pq.push(Node(root, 0));

    while (!pq.empty()) {
        Node front = pq.top(); pq.pop();
        int u = front.v;
        if (visited[u]) continue;
        for (int i = 0; i < sz(g[u]); ++i) {
            int v = g[u][i].fi;
            int d = g[u][i].se;
            if (!visited[v] && dist[u] + d < dist[v]) {
                dist[v] = dist[u] + d;
                pq.push(Node(v, dist[v]));
            }
        }
        visited[u] = 1;
    }

    return dist;
}

int to_int(char c) { return c - 'a'; }

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string a, b; int n;
    cin >> a >> b >> n;
    vector< vi > v(30, vi(30, -1));
    for (int i = 0; i < n; ++i) {
        char x, y; int w;
        cin >> x >> y >> w;
        int ix = to_int(x), iy = to_int(y);
        v[ix][iy] = v[ix][iy] == -1 ? w : min(w, v[ix][iy]);
    }
    if (sz(a) != sz(b)) {
        cout << "-1\n";
    } else {
        int l = sz(a);
        for (int i = 0; i < 30; ++i) {
            for (int j = 0; j < 30; ++j) {
                if (i != j && v[i][j] != -1) {
                    g[i].pb({j, v[i][j]});
                }
            }
        }
        vi dd[30];
        for (int i = 0; i < 30; ++i) {
            dd[i] = dijkstra(i);
        }
        int cost = 0;
        string ans;
        for (int i = 0; i < l; ++i) {
            int ai = to_int(a[i]), bi = to_int(b[i]);
            if (ai == bi) {
                ans += ('a' + ai);
                continue;
            }
            int aux = INF, kaux = -1;
            for (int k = 0; k < 30; ++k) {
                if (dd[ai][k] + dd[bi][k] < aux) {
                    aux = dd[ai][k] + dd[bi][k];
                    kaux = k;
                }
            }
            if (aux < INF) {
                cost += aux;
                ans += ('a' + kaux);
            } else {
                cost = -1;
                break;
            }
        }
        if (cost != -1) {
            cout << cost << endl;
            cout << ans << endl;
        } else {
            cout << "-1\n";
        }
    }
}
