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

int n, m, d;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> d;
    vi v(n * m, 0);
    for (int i = 0; i < n * m; ++i) cin >> v[i];
    sort(all(v));
    int a = (n * m) / 2;
    int b = (n * m) / 2 - 1;
    int aa = 0, bb = 0;
    for (int i = 0; i < n * m; ++i) {
        int x = abs(v[a] - v[i]);
        int dd = x / d;
        if (dd * d == x) aa += dd;
        else {
            aa = -1;
            break;
        }
    }
    for (int i = 0; i < n * m; ++i) {
        int x = abs(v[b] - v[i]);
        int dd = x / d;
        if (dd * d == x) bb += dd;
        else {
            bb = -1;
            break;
        }
    }
    if (aa != -1 && bb != -1) {
        cout << min(aa, bb) << "\n";
    } else if (aa != -1) {
        cout << aa << "\n";
    } else if (bb != -1) {
        cout << b << "\n";
    } else cout << -1 << "\n";
}
