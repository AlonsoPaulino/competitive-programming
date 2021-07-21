#include <bits/stdc++.h>
#define PI acos(-1)
#define gcd(x,y) __gcd((x),(y))
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define fi first
#define se second
#define popb pop_back
#define all(v) v.begin(),v.end()
#define debug(x) cerr<<#x<<" : "<<x<<"\n"
#define debug2(x,y) cerr<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<"\n"
#define test() cerr<<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

const int N = 100;
vi v(N);
vi cont(N);

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
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        v[i] = i, cont[i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        join(a, b);
    }
    set<int> groups;
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        groups.insert(find(i));
    }
    for (auto it: groups) {
        ans += cont[it];
        ans = ans - 1;
    }
    cout << (1LL << (ans - 1)) << endl;
}
