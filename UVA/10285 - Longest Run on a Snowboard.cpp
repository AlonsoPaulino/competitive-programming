#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
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
#define debug(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
#define MAXH 100
#define INF 1 << 20
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

vb visited(MAXH * MAXH + 5);
vi ans(MAXH * MAXH + 5);
vi g[MAXH * MAXH + 5];
int v[MAXH + 5][MAXH + 5];
int r, c, n, result;
string name;

void dfs(int u) {
    visited[u] = 1;
    vi ady = g[u];
    for (int i = 0; i < sz(ady); ++i) {
        if (!visited[ady[i]]) dfs(ady[i]);
        ans[u] = max(ans[u], ans[ady[i]] + 1);
    }
    if (ans[u] == 0) ans[u] = 1;
    result = max(ans[u], result);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    while (n--) {
        result = 0;
        cin >> name >> r >> c;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                int u = i * c + j;
                cin >> v[i][j];
                g[u].clear();
                ans[u] = 0 , visited[u] = 0;
            }
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (i > 0 && v[i - 1][j] < v[i][j]) g[i * c + j].pb((i - 1) * c + j);
                if (i + 1 < r && v[i + 1][j] < v[i][j]) g[i * c + j].pb((i + 1) * c + j);
                if (j > 0 && v[i][j - 1] < v[i][j]) g[i * c + j].pb(i * c + j - 1);
                if (j + 1 < c && v[i][j+1] < v[i][j]) g[i * c + j].pb(i * c + j + 1);
            }
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                int u = i * c + j;
                if (!visited[u]) {
                    dfs(u);
                }
            }
        }
        cout << name << ": " << result << "\n";
    }
}