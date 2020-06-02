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

const int N = 500;

ll n, ans = 1LL, x = 0LL, y = 0LL, diff = 0LL, ii, jj;
ll v[N + 5][N + 5];
bool valid = true;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    ll sum = 0LL;
    for (int j = 0; j < n; ++j) {
      cin >> v[i][j];
      sum += v[i][j];
      if (v[i][j] == 0) {
        ii = i, jj = j;
      }
    }
    x = max(sum, x);
    y = (!y ? x : min(sum, y));
  }
  diff = x - y;
  if (x != 0) {
    ans = diff;
    v[ii][jj] = diff;
    for (int i = 0; i < n && valid; ++i) {
      ll sum = 0LL;
      for (int j = 0; j < n && valid; ++j) {
        sum += v[i][j];
      }
      if (sum != x) valid = false;
    }
    for (int j = 0; j < n && valid; ++j) {
      ll sum = 0LL;
      for (int i = 0; i < n && valid; ++i) {
        sum += v[i][j];
      }
      if (sum != x) valid = false;
    }
    ll d1 = 0LL, d2 = 0LL;
    for (int i = 0; i < n && valid; ++i) {
      d1 += v[i][i], d2 += v[i][n - i - 1];
    }
    if (d1 != x || d2 != x) valid = false;
  }
  if (!valid || ans <= 0 || ans > 1000000000000000000LL) {
    ans = -1;
  }
  cout << ans << "\n";
}
