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

const int N = 1001;

int c, p, d, x, y;
vi ady[N];

vi bfs(int root) {
  vi ans(p);
  vb visited(N, false);
  queue< pii > q;
  q.push(mp(root, 0));
  visited[root] = 1;
  while (!q.empty()) {
      pii front = q.front();
      q.pop();
      if (front.fi != 0) {
        ans[front.fi] = front.se;
      }
      vi childs = ady[front.fi];
      for (int i = 0; i < sz(childs); ++i) {
        if (!visited[childs[i]]) {
          q.push(mp(childs[i], front.se + 1));
          visited[childs[i]] = 1;
        }
      }
  }
  return ans;
}

int main() {
  cin >> c;
  while (c--) {
    for (int i = 0; i < N; ++i) {
      ady[i].clear();
    }
    cin >> p >> d;
    for (int i = 0; i < d; ++i) {
      cin >> x >> y;
      ady[x].pb(y), ady[y].pb(x);
    }
    vi ans = bfs(0);
    for (int i = 1; i < p; ++i ){
      cout << ans[i] << "\n";
    }
    if (c) {
      cout << "\n";
    }
  }
  return 0;
}
