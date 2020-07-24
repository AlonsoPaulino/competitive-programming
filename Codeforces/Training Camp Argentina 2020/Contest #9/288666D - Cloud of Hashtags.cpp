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

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vs v(n), ans(n);
    for (int i = 0; i < n; ++i) cin >> v[i], ans[i] = v[i];
    for (int i = n - 2; i >= 0; --i) {
        string a = v[i], b = ans[i + 1];
        if (a > b) {
            int l = 0;
            while (l < min(sz(a), sz(b)) && a[l] <= b[l]) ++l;
            a = a.substr(0, l);
        }
        ans[i] = a;
    }
    for (auto x: ans) cout << x << "\n";
}
