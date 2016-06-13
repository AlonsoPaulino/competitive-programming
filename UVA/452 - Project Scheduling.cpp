#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define ssz(x) (int) strlen(x)
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
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
#define MAX 27
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

vb visited(MAX + 1);
vi g[MAX + 1];
vi w(MAX + 1);
vi dp(MAX + 1);

int t, wi, result;
string s1, s2;
string s;

int toint(char c) {
    return (int) (c - 'A');
}

void dfs(int u) {
    visited[u] = 1;
    vi ady = g[u];
    for (int i = 0; i < sz(ady); ++i) {
        if (!visited[ady[i]]) dfs(ady[i]);
        dp[u] = max(dp[u], dp[ady[i]] + w[u]);
    }
    if (dp[u] == 0) dp[u] = w[u];
    result = max(dp[u], result);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    cin.ignore(), cin.ignore();
    while (t--) {
        result = 0;
        set<int> nodes;
        for (int i = 0; i < MAX + 1; ++i) {
            g[i].clear();
            visited[i] = 0, dp[i] = 0;
        }
        while (getline(cin, s) && s != "") {
            stringstream ss(s);
            ss >> s1 >> wi;
            nodes.insert(toint(s1[0]));
            w[toint(s1[0])] = wi;
            if (ss >> s2) {
                for (int i = 0; i < sz(s2); ++i) {
                    g[toint(s1[0])].pb(toint(s2[i]));
                }
            }
        }
        set<int>::iterator it = nodes.begin();
        while (it != nodes.end()) {
            if (!visited[*it]) {
                dfs(*it);
            }
            ++it;
        }
        cout << result << "\n";
        if (t > 0) cout << "\n";
    }
}