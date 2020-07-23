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

int read(vi &bit, int x) {
  ll sum = 0;
  while (x > 0) sum += bit[x], x -= (x & -x);
  return sum;
}

void modify(vi &bit, int x, int add) {
  while (x < sz(bit)) bit[x] += add, x += (x & -x);
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n, q, a, b; cin >> n >> q;
    vi qq, v(n + 5, 0), bit(n + 5, 0), ans;
    int t = 0;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        if (a == 1) {
            qq.pb(b);
            v[b]++;
            modify(bit, b, 1);
        } else if (a == 2) {
            modify(bit, b, - (read(bit, b) - read(bit, b - 1)));
        } else {
            for (int i = t; i < b; ++i) {
                int pos = qq[i];
                v[pos] = v[pos] - 1;
                int cur = (read(bit, pos) - read(bit, pos - 1));
                if (v[pos] < cur) {
                    modify(bit, pos, v[pos] - cur);
                }
            }
            t = max(t, b);
        }
        ans.pb(read(bit, n));
    }
    for (auto x: ans) cout << x << "\n";
}
