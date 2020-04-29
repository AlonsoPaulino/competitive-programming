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

const int N = 20;

bool ady[N][N];
ll dp[1 << N][N];

ll n, m, a, b, ans = 0;

int main() {
  mset2dd(dp, 0, (1 << N), N);
  mset2d(ady, 0, N);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    ady[a - 1][b - 1] = ady[b - 1][a - 1] = 1;
  }
  for (int i = 0; i < n; ++i) {
    dp[1 << i][i] = 1;
  }
  for (int mask = 1; mask < (1 << n); ++mask) {
    if (mask & (mask - 1)) {
      int first = -1;
      ll count = 0, acum = 0;
      for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
          ++count;
          if (first != -1) {
            for (int j = 0; j < n; ++j) {
              if (mask & (1 << j) && ady[i][j]) {
                dp[mask][i] += dp[mask ^ (1 << i)][j];
              }
            }
          }
          if (first == -1) {
            first = i;
          }
          if (ady[first][i]) {
              acum += dp[mask][i];
          }
        }
      }
      if (count > 2) {
        ans += acum;
      }
    }
  }
  cout << ans / 2 << "\n";
}
