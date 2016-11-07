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
#define mod(x, m) ((x % m) + m) % m
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

const int MAX = 10;

vector< pair<string, int> > attempts(MAX);
vs variants;
string si;
ll ci, ans = 0, n, m;

struct node {
    string s;
    int n;
};

inline node make(string s, int n) {
    node x; x.s = s, x. n = n; return x;
}

vs dfs(string code, int correct) {
    vs result;
    queue<node> q;
    q.push(make("", 0));
    while (!q.empty()) {
        node current = q.front(); q.pop();
        node next;
        int i = sz(current.s);
        if (i != sz(code) && current.n != correct) {
            if (code[i] == '0') {
                q.push(make(current.s + "0", current.n + 1));
                q.push(make(current.s + "1", current.n));
            } else {
                q.push(make(current.s + "0", current.n));
                q.push(make(current.s + "1", current.n + 1));
            }
        } else {
            for (i; i < sz(code); ++i) {
                current.s += (code[i] == '0') ?  "1" : "0";
            }
            if (current.n == correct) {
                result.pb(current.s);
            }
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> si >> ci;
        attempts[i] = mp(si, ci);
    }
    variants = dfs(attempts[0].fi, attempts[0].se);
    for (int i = 1; i < m; ++i) {
        vs result;
        for (int j = 0; j < sz(variants); ++j) {
            string s = attempts[i].fi;
            int correct = attempts[i].se, count = 0;
            for (int k = 0; k < sz(s); ++k) {
                if (s[k] == variants[j][k]) count++;
            }
            if (count == correct) {
                result.pb(variants[j]);
            }
        }
        variants = result;
    }
    for (int i = 0; i < sz(variants); ++i) {
        bool found = false;
        for (int j = 0; j < m && !found; ++j) {
            if (attempts[j].fi == variants[i]) {
                found = true;
            }
        }
        if (!found) ++ans;
    }
    cout << ans << "\n";
}