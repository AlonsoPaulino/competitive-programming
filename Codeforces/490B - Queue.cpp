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
#define debug(x) cerr<<#x<<" : "<<x<<endl
#define debug2(x,y) cerr<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n, a, b;

const int N = 1000000;

mii ady;
mii::iterator it;
vi v(2 * N + 5, -1);
int x = N + 1;

vi bfs(vi roots) {
  vi results;
  queue<int> q;
  for (int i = 0; i < sz(roots); ++i) {
    q.push(roots[i]);
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (x <= N) {
      results.pb(x);
    }
    if (ady[x]) {
      q.push(ady[x]);
    }
  }
  return results;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a >> b;
      if (b != 0) {
        ady[x] = b;
        v[b] = x;
      }
      if (a != 0) {
        ady[a] = x;
        v[x] = a;
      }
      ++x;
    }
    vi roots;
    for (it = ady.begin(); it != ady.end(); ++it) {
      if (v[it->fi] == -1) {
        roots.pb(it->fi);
      }
    }
    vi results = bfs(roots);
    for (int i = 0; i < sz(results); ++i) {
      cout << results[i] << (i + 1 < sz(results) ? " " : "\n");
    }
}
