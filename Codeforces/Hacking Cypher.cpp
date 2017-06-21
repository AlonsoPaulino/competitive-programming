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
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

string s;
ll a, b;

set<int> matches;
int ans;

ll toLong(char c) {
  return (ll) (c - '0');
}

int main() {
  cin >> s >> a >> b;
  ans = -1;
  ll r = toLong(s[0]) % a;
  for (int i = 0; i < sz(s) - 1; ++i) {
    if (r == 0) {
      matches.insert(i);
    }
    r = ((10LL % a) * (r % a) + toLong(s[i + 1])) % a;
  }
  vector<ll> aux(1000005);
  aux[0] = 0, aux[1] = 10LL % b;
  for (int i = 2; i < sz(aux); ++i) {
    aux[i] = (aux[i - 1] * 10LL) % b;
  }
  r = toLong(s[sz(s) - 1]) % b;
  for (int i = sz(s) - 1; i >= 1; --i) {
    if (r == 0) {
      if (matches.count(i - 1) == 1 && s[i] != '0') {
        ans = i;
        break;
      }
    }
    r = ((aux[sz(s) - i] % b) * (toLong(s[i - 1]) % b) + r) % b;
  }
  if (ans == -1) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 0; i < ans; ++i) {
      cout << s[i];
    }
    cout << "\n";
    for (int i = ans; i < sz(s); ++i) {
      cout << s[i];
    }
    cout << "\n";
  }
}
