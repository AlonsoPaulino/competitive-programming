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
#define MAX 100001
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

ll n, m, v;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> v;
    ll aux = 1 + (n - 1) * (n - 2) / 2;
    if (m > aux || m + 1 < n || m < 2) {
        cout << -1 << "\n";
    } else {
        int v2 = (v == 1) ? 2 : 1;
        for (int i = 1; i < n + 1 && m > 2; ++i) {
            for (int j = i + 1; j < n + 1 && m > 2; ++j) {
                if (i != v && i != v2 && j != v && j != v2) {
                    cout << i << " " << j << "\n";
                    --m;
                }
            }
        }
        for (int i = 1; i < n + 1 && m > 1; ++i) {
            if (i != v && i != v2) {
                cout << v << " " << i << "\n";
                --m;
            }
        }
        debug(m);
        cout << v << " " << v2 << "\n";
    }
}
