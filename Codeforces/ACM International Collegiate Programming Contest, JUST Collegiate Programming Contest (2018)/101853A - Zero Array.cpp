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

int t, n, q, p, v, op;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n >> q;
        unordered_map<int, int> m;
        vi a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] != 0) {
                m[a[i]]++;
            }
        }
        for (int i = 0; i < q; ++i) {
            cin >> op;
            if (op == 2) {
                cout << m.size() << endl;
            } else {
                cin >> p >> v;
                int x = a[p - 1];
                a[p - 1] = v;
                if (x != 0 && --m[x] == 0) {
                    m.erase(x);
                }
                if (v != 0) {
                    m[v]++;
                }
            }
        }
    }
}