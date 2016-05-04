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
#define MAX 1000
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

struct Edge {
	double x;
	double y;
	double w;
};

Edge initEdge(double x, double y, double w) {
	Edge edge;
	edge.x = x, edge.y = y, edge.w = w;
	return edge;
}

bool sortedges(Edge e1, Edge e2) {
	return e1.w < e2.w;
}

vi v(MAX + 5);

int find(int x) {
	return v[x] == x ? x : v[x] = find(v[x]);
}

double dist(pair<double, double> p1, pair<double, double> p2) {
	return sqrt((p1.first - p2.first) * (p1.first - p2.first) +
			(p1.second - p2.second) * (p1.second - p2.second));
}

void join(int x, int y) {
	v[find(x)] = find(y);
}

int t, n, cities;
double r, ans, x, y, railroads;

void initset() {
	for (int i = 0; i < n; ++i) {
		v[i] = i;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> t;
	for (int k = 1; k < t + 1; ++k) {
		cin >> n >> r;
		vector< pair<double, double> > points;
		vector< Edge > g;
		for (int i = 0; i < n; ++i) {
			cin >> x >> y;
			points.pb(mp(x, y));
		}
		for (int i = 0; i < n; ++i) {
			for (int j = i +1; j < n; ++j) {
				g.pb(initEdge(i, j, dist(points[i], points[j])));
			}
		}
		sort(all(g), sortedges), initset(), ans = 0, cities = 1, railroads = 0;
		for (int i = 0; i < sz(g); ++i) {
			if (find(g[i].x) != find(g[i].y)) {
				join(g[i].x, g[i].y);
				if (g[i].w <= r) {
					ans += g[i].w;
				} else {
					++cities;
					railroads += g[i].w;
				}
			}
		}
		cout << "Case #" << k << ": " << cities << " " << round(ans) << " " << round(railroads) << "\n"; 
	}
	return 0;
}
