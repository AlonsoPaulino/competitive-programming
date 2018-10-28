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

const int N = 100005;

int n, a, u, v, answer = 0;

vector< vi > ady(N, vi());

void dfs() {
    vb visited(n + 1);

    stack< pii > s;
    pii top = mp(a, 1);
    s.push(top);

    while (!s.empty()) {
        top = s.top();
        s.pop();

        answer = max(top.se, answer);

        if (visited[top.fi]) continue;

        vi ad = ady[top.fi];

        for (int i = 0; i < sz(ad); ++i) {
            if (!visited[ad[i]]) {
                s.push(mp(ad[i], top.se + 1));
            }
        }

        visited[top.fi] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> a;

    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        ady[u].pb(v), ady[v].pb(u);
    }

    dfs();

    cout << answer << "\n";
}