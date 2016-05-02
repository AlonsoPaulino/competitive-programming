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
#define MAX 500
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n, s, p;
double xi, yi;
vi v(MAX + 5);

struct Edge {
    int x;
    int y;
    double w;
};

void initset() {
    for (int i = 0; i < p; ++i) {
        v[i] = i;
    }
}

int find(int x) {
    return x == v[x] ? x : v[x] = find(v[x]);
}

void join(int x, int y) {
    v[find(x)] = find(y);
}

Edge initEdge(int x, int y, double w) {
    Edge edge;
    edge.x = x, edge.y = y, edge.w = w;
    return edge;
}

bool sortEdges(Edge e1, Edge e2) {
    return e1.w < e2.w;
}

bool sameComponent(Edge e) {
    return find(e.x) == find(e.y);
}

double pointDistance(pii p1, pii p2) {
    return sqrt((p1.first - p2.first)*(p1.first - p2.first) + 
                (p1.second - p2.second)*(p1.second - p2.second));
}

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &s, &p);
        vector< pii > points(p);
        vector<Edge> edges;
        vector<Edge> mst;
        initset();
        for (int i = 0; i < p; ++i) {
            scanf("%lf %lf", &xi, &yi);
            points[i] = mp(xi, yi);
        }
        for (int i = 0; i < p; ++i) {
            for (int j = i + 1; j < p; ++j) {
                edges.pb(initEdge(i, j, pointDistance(points[i], points[j])));
            }
        }
        sort(all(edges), sortEdges);
        for (int i = 0; i < sz(edges); ++i) {
            if (!sameComponent(edges[i])) {
                join(edges[i].x, edges[i].y);
                mst.pb(edges[i]);
            }
        }
        s = s - 1;
        while (s--) {
            if (sz(mst) == 0) break;
            mst.popb();
        }
        if (sz(mst) == 0) {
            printf("0.00\n");
        } else {
            printf("%.2lf\n", mst[sz(mst) - 1].w);
        }
    }
}