#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) x.size()
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define all(v) v.begin, v.end()
#define debug(x) cout<<#x<<":"<<x<<endl
#define debug2(x,y) cout<<#x<<":"<<x<<"&"<<#y<<":"<<y<<endl
#define test() cout<<"hola papa"<<endl
#define MAX 52
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

bool ans;
char v[MAX][MAX];
bool visited[MAX][MAX];
int n, m;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

struct node {
	int x, y, l;
};

node initNode(int px, int py, int pl) {
	node n;
	n.x = px, n.y = py, n.l = pl;
	return n;
}

bool dfs(int x, int y) {
	mset2d(visited, 0, MAX);
	stack<node> q;
	for (int i = 0; i < 4; ++i) {
		if (v[x][y] == v[x + dx[i]][y + dy[i]]) {
			q.push(initNode(x + dx[i], y + dy[i], 1));
		}
	}
	while (!q.empty()) {
		node aux = q.top();
		q.pop();
		visited[aux.x][aux.y] = 1;
		for (int i = 0; i < 4; ++i) {
			int nx = aux.x + dx[i];
			int ny = aux.y + dy[i];
			if (!visited[nx][ny] && v[aux.x][aux.y] == v[nx][ny]) {
				if (nx != x || ny != y) {
					q.push(initNode(nx, ny, aux.l + 1));
				} else {
					if (aux.l >= 3) return true;
				}
			}
		}
	}
	return false;
}

int main() {
	while (cin >> n >> m) {
		ans = false;
		mset(v, '$');
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cin >> v[i][j];
			}
		}
		for (int i = 1; !ans && i <= n; ++i) {
			for (int j = 1; !ans && j <= m; ++j) {
				ans = dfs(i, j);
			}
		}
		if (ans) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}