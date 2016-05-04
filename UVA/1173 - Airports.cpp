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
#define MAX 10000
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
vi w(MAX + 5, 0);

int t, n, m, a, x, y, c;
ll ans;

void initset() {
	for (int i = 0; i < n + 1; ++i) {
		v[i] = i;
		w[i] = 0;
	}
}

int find(int node) {
	return node == v[node] ? node : v[node] = find(v[node]);
}

void join(int node1, int node2, int cost) {
	int root1 = find(node1);
	int root2 = find(node2);
	if (root1 != root2) {
		w[root2] = w[root2] + w[root1] + cost;
		v[root1] = root2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	for (int k = 1; k < t + 1; ++k) {
		cin >> n >> m >> a;
		vector<Edge> g(m);
		for (int i = 0; i < m; ++i) {
			cin >> x >> y >> c;
			g[i] = initEdge(x, y, c);
		}
		ans = 0;
		sort(all(g), sortedges), initset();
		for (int i = 0; i < m; ++i) {
			if (find(g[i].x) != find(g[i].y) && g[i].w < a) {
				join(g[i].x, g[i].y, g[i].w);
			}
		}
		set<int> s;
		for (int i = 1; i < n + 1; ++i) {
			if (!s.count(find(i))) {
				s.insert(find(i));
				ans += w[find(i)];
				ans += a;
			}
		}
		cout << "Case #" << k << ": " << ans << " " << sz(s) << endl;
	}
}