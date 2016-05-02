#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
#define vb vector<bool>
#define mp make_pair
#define pb push_back
#define popb pop_back
#define all(v) v.begin(),v.end()
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
#define MAX 100
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

struct Edge {
    int x;
    int y;
    int w;
};

vi v(MAX + 5);
int t, c, s, q, xi, yi, wi, ci, cj;

inline void iniset() {
    for (int i = 1; i < c + 1; ++i) {
        v[i] = i;
    }
}

bool edgesort(Edge x, Edge y) {
    return x.w < y.w;
}

Edge initEdge(int x, int y, int w) {
    Edge edge;
    edge.x = x, edge.y = y, edge.w = w;
    return edge;
}

int find(int x) {
    return x == v[x] ? x : v[x] = find(v[x]);
}

void join(int x, int y) {
    v[find(x)] = find(y);
}

bool sameComponent(int x, int y) {
    return find(x) == find(y);
}

int bfs(int x, int y, vector<Edge> mst) {
    vb visited(MAX + 5, 0);
    queue< pii > q;
    q.push(mp(x, 0));
    while (!q.empty()) {
        pii node = q.front(); q.pop();
        visited[node.first] = 1;
        if (node.first == y) {
            return node.second;
        }
        for (int i = 0; i < sz(mst); ++i) {
            if (mst[i].x == node.first && !visited[mst[i].y]) {
                q.push(mp(mst[i].y, max(node.second, mst[i].w)));
            } else if (mst[i].y == node.first && !visited[mst[i].x]) {
                q.push(mp(mst[i].x, max(node.second, mst[i].w)));
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false), t = 0;
    while (cin >> c >> s >> q) {
        if (c == 0 && s == 0 && q == 0) break;
        iniset();
        vector<Edge> edges(s);
        vector<Edge> mst;
        for (int i = 0; i < s; ++i) {
            cin >> xi >> yi >> wi;
            edges[i] = initEdge(xi, yi, wi);
        }
        sort(all(edges), edgesort);
        for (int i = 0; i < s; ++i) {
            if (!sameComponent(edges[i].x, edges[i].y)) {
                join(edges[i].x, edges[i].y);
                mst.pb(edges[i]);
            }
        }
        for (int i = 0; i < q; ++i) {
            cin >> ci >> cj;
            if (i == 0) {
                if (t > 0) cout << "\n";
                cout << "Case #" << ++t << "\n";
            }
            int ans = bfs(ci, cj, mst);
            if (ans == 0) {
                cout << "no path\n";
            } else {
                cout << ans << "\n";
            }
        }
    }
}