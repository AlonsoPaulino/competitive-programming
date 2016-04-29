#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define pss pair<string, string>
#define mii map<int, int>
#define vi vector<int>
#define vb vector<bool>
#define mp make_pair
#define pb push_back
#define popb pop_back
#define fi first
#define se second
#define mset(v, x) memset(v, x, sizeof(v))
#define mset2d(v, x, n) memset(v, x, sizeof(v[0][0]) * n * n)
#define mset2dd(v, x, n, m) memset(v, x, sizeof(v[0][0]) * n * m)
#define debug(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
#define MAX 200005
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int t, f, k;
string s1, s2;
vi v(MAX);
vi cont(MAX);

int find(int x) {
  return (x == v[x]) ? x : v[x] = find(v[x]);
}

int join(int x, int y) {
  int rx = find(x);
  int ry = find(y);
  if (rx == ry) {
    return cont[rx];
  }
  if (cont[rx] > cont[ry]) {
    v[ry] = rx;
    cont[rx] = cont[rx] + cont[ry];
    return cont[rx];
  } else {
    v[rx] = ry;
    cont[ry] = cont[rx] + cont[ry];
    return cont[ry];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> f;
    map<string, int> m;
    k = 0;
    for (int i = 0; i < f; ++i) {
      cin >> s1 >> s2;
      int k1, k2;
      if (m.find(s1) == m.end()) {
        m[s1] = k, v[k] = k, cont[k] = 1;
        k1 = k++;
      } else {
        k1 = m[s1];
      }
      if (m.find(s2) == m.end()) {
        m[s2] = k, v[k] = k, cont[k] = 1;
        k2 = k++;
      } else {
        k2 = m[s2];
      }
      int ans = join(k1, k2);
      cout << ans << "\n";
    }
  }
  return 0;
}
