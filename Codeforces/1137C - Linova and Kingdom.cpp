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

/*
TIP: Focus on how much you can gain after considering a node to develop tourism rather than industry.
Let's image the amount of happines you can gain by considering node 'u' as industry is X, if you change
this node to develop tourism: 1. You lose the amount of happines the evoy sent from 'u' could get, which is
the number of edges from 'u' to the root, otherwise -> depth(u). 2. In the optimal solution, you can easily
proof that in order to maximize happiness, if node 'u' is choosen for industry, all its childs should be used
for industry too. Then, if you change 'u' from industry to tourism, all your childs that were supposed to be
for industries will gain 1 more happines since the node 'u' is now for tourism, and all of the childs should
go through 'u' to raise the root, in other words, you gain numberOfNodesInSubTree(u).

To sump up, the equation looks like: industry(u) = tourism(u) + depth(u) - numberOfNodesInSubstree(u)

Now the algorithm is simple, image all the nodes are for tourisms, and sort all of them in such a way that you
maximize the gain of happiness if they are turned into industry using the equation :) 
*/

const int N = 2 * 100005;

int n, k, u, v;
ll ans = 0LL;
vector< vi > g(N);
vi depth(N, -1);
vi szTree(N);
vi profits;

void dfs(int root, int level) {
    depth[root] = level;
    vi childs = g[root];
    for (auto x: childs) {
        if (depth[x] != -1) continue;
        dfs(x, level + 1);
        szTree[root] += szTree[x];
    }
    szTree[root]++;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i + 1 < n; ++i) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; ++i) {
        profits.pb(depth[i] - szTree[i] + 1);
    }
    
    sort(all(profits));

    for (int i = 1; i <= k; ++i) {
        ans += (ll) profits[n - i];
    }

    cout << ans << endl;
}
