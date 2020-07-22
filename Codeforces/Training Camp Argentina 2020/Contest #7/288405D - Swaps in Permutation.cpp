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

const int MAX = 1000005;

vi p(MAX);

int find(int x) {
  return (x == p[x]) ? x : p[x] = find(p[x]);
}

void join(int x, int y) {
  p[find(x)] = find(y);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vi x(n);
    for (int i = 0; i < n; ++i) p[i] = i, cin >> x[i];
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        if (a != b) join(a - 1, b - 1);
    }
    unordered_map<int, vi> miv;
    for (int i = 0; i < n; ++i) {
        miv[find(i)].pb(i);
    }
    auto it = miv.begin();
    while (it != miv.end()) {
        vi a = it->se; vi b;
        int l = sz(a);
        sort(all(a));
        for (auto i : a) b.push_back(x[i]);
        sort(all(b));
        for (int i = 0; i < l; ++i) {
            x[a[i]] = b[l - 1 - i];
        }
        ++it;
    }
    for (int i = 0; i < n; ++i) {
        cout << x[i] << (i + 1 < n ? " " : "\n");
    }
}
