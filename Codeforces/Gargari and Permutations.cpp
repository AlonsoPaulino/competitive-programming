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
#define K 5
#define N 1000
#define INF 1 << 20
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

vi g[N + 1];
int pos[K + 1][N + 1], lcs[N + 1];
bool visited[N + 1];

int n, k, aux, ans;

void dfs(int v) {
    visited[v] = 1;
    vi ady = g[v];
    for (int i = 0; i < sz(ady); ++i) {
        if (!visited[ady[i]]) {
            dfs(ady[i]);
        }
        lcs[v] = max(lcs[v], lcs[ady[i]] + 1);
    }
    if (lcs[v] == 0) {
        lcs[v] = 1;
    }
    ans = max(ans, lcs[v]);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> aux;
            pos[i][aux] = j;
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            if (i != j) {
                bool valid = 1;
                for (int z = 0; z < k && valid; ++z) {
                    if (pos[z][i] >= pos[z][j]) valid = 0;
                }
                if (valid) g[i].pb(j);
            }
        }
    }
    for (int i = 1; i < n + 1; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    cout << ans << "\n";
}