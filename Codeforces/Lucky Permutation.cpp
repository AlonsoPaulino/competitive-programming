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

const int MAX = 100005;

vi f(MAX, -1);
vi fr(MAX, - 1);
vb valid(MAX, 1);
bool ans = 1;
int n;
int lastValid = 1;

int main() {
  cin >> n;
  if (n == 1) {
    cout << "1\n";
  } else {
    if (n & 1) {
      f[n / 2 + 1] = n / 2 + 1;
      valid[n / 2 + 1] = 0;
    }
    f[1] = 2, f[n] = n - 1;
    fr[2] = 1, fr[n - 1] = n;
    valid[2] = valid[n - 1] = 0;
    for (int i = 2; i <= n / 2; ++i) {
      int x = f[i], y = fr[i];
      if (x != -1 && y == -1) {
        fr[i] = n + 1 - x;
        f[n + 1 - x] = i;
        valid[i] = 0;
      } else if (y != -1 && x == -1) {
        f[i] = n + 1 - y;
        valid[n + 1 - y] = 0;
        fr[n + 1 - y] = i;
      }
      if (f[i] == -1) {
        bool update = 1;
        for (int j = lastValid; j <= n; ++j) {
          if (valid[j]) {
            if (i == j) {
              update = 0;
              continue;
            }
            f[i] = j;
            fr[j] = i;
            valid[j] = 0;
            if (update) {
              lastValid = j;
            }
            break;
          }
        }
      }
      f[n + 1 - i] = n + 1 - f[i];
      fr[f[n + 1 - i]] = n + 1 - i;
      valid[n + 1 - f[i]] = 0;
    }
    for (int i = 1; i <= n && ans; ++i) {
      if (f[f[i]] != n + 1 - i) {
        ans = 0;
      }
    }
    if (ans == 0) {
      cout << "-1\n";
    } else {
      for (int i = 0; i < n; ++i) {
        cout << f[i + 1] << (i + 1 < n ? " " : "\n");
      }
    }
  }
}
