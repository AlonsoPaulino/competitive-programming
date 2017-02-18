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

int n;

int main() {
  cin >> n;
  if (n == 1) {
    cout << "1\n";
  } else if (n % 4 == 2 || n % 4 == 3) {
    cout << "-1\n";
  } else {
    vi v(n + 1);
    int x = 2, y = n;
    for (int i = 1; i <= n / 2; ++i) {
      v[i] = (i & 1) ? x : y;
      (i & 1) ? x += 2 : y -= 2;
      v[n - i +  1] = n + 1 - v[i];
    }
    if (!v[n / 2 + 1]) {
      v[n / 2 + 1] = n / 2 + 1;
    }
    for (int i = 1; i <= n; ++i) {
      cout << v[i] << (i < n ? " " : "\n");
    }
  }
}
