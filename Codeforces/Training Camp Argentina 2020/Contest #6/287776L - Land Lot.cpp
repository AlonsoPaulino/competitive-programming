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

int n, m;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    vector< vi > v(n, vi(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> v[i][j];
    }
    int a, b; cin >> a >> b;
    int z = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            z = 0;
            for (int ki = i; ki < min(n, i + a); ++ki) {
                for (int kj = j; kj < min(m, j + b); ++kj) {
                    if (v[ki][kj] == 0) ++z;
                    if (ki + 1 == i + a && kj + 1 == j + b) {
                        ans = max(ans, z);
                    }
                }
            }
            z = 0;
            for (int ki = i; ki < min(n, i + b); ++ki) {
                for (int kj = j; kj < min(m, j + a); ++kj) {
                    if (v[ki][kj] == 0) ++z;
                    if (ki + 1 == i + b && kj + 1 == j + a) {
                        ans = max(ans, z);
                    }
                }
            }
        }
    }
    cout << a * b - ans << endl;
}
