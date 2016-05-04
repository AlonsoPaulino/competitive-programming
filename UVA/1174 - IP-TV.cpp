#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
#define vvi vector< vi >
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
#define MAX 2000
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

struct Edge {
	int x;
	int y;
	int w;
};

Edge initEdge(int x, int y, int w) {
	Edge edge;
	edge.x = x, edge.y = y, edge.w = w;
	return edge;
}

bool sortedges(Edge e1, Edge e2) {
	return e1.w < e2.w;
}

vi v(MAX + 5);
int t, n, m, c, k, ans;
string b, e;
bool bline = 0;

void initset() {
	for (int i = 1; i < n + 1; ++i) {
		v[i] = i;
	}
}

int find(int x) {
	return v[x] == x ? x : v[x] = find(v[x]);
}

void join(int x, int y) {
	v[find(x)] = find(y);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		k = 1, ans = 0;
		map<string, int> aux;
		vector<Edge> g;
		while (m--) {
			cin >> b >> e >> c;
			if (!aux[b]) {
				aux[b] = k++;
			}
			if (!aux[e]) {
				aux[e] = k++;
			}
			g.pb(initEdge(aux[b], aux[e], c));
		}
		sort(all(g), sortedges), initset();
		for (int i = 0; i < sz(g); ++i) {
			if (find(g[i].x) != find(g[i].y)) {
				join(g[i].x, g[i].y);
				ans += g[i].w;
			}
		}
		cout << ans << endl;
		if (t) cout << endl;
	}
	return 0;
}
