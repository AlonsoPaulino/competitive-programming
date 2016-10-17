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

int n, m, ans;

int main() {
    cin >> n >> m;
    if (n > 1 && m > 1 && !((n * m) & 1)) {
        cout << 0 << "\n";
        if (!(n & 1)) {
            for (int j = 1; j <= m; ++j) cout << 1 << " " << j << "\n";
            for (int i = 2; i <= n; ++i) cout << i << " " << m << "\n";
            for (int j = m - 1; j >= 1; --j) cout << n << " " << j << "\n";
            for (int i = n - 1; i > 1; --i) {
                for (int j = 1; j < m; ++j) {
                    cout << i << " " << (i & 1 ? j : m - j) << "\n";
                }
            }
        } else {
            for (int i = 1; i <= n; ++i) cout << i << " " << 1 << "\n";
            for (int j = 2; j <= m; ++j) cout << n << " " << j << "\n";
            for (int i = n - 1; i >= 1; --i) cout << i << " " << m << "\n";
            for (int j = m - 1; j > 1; --j) {
                for (int i = 1; i < n; ++i) {
                    cout << (j & 1 ? i : n - i) << " " << j << "\n";   
                }
            }
        }
    } else {
        if (n * m == 2) {
            cout << 0 << "\n";
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    cout << i << " " << j << "\n";
                }
            }
        } else {
            cout << 1 << "\n";
            cout << n << " " << ((n & 1) ? m : 1) << " 1 1\n";
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    cout << i << " " << (i & 1 ? j : m - j + 1) << "\n";
                }
            }
        }
    }
    cout << "1 1\n";
}