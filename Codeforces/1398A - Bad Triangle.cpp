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
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi v(n + 5, 0); 
        for (int i = 1; i <= n; ++i) cin >> v[i];
        bool ans = false; int x, y, z;
        for (int i = 2; i < n; ++i) {
            auto it = upper_bound(v.begin() + i, v.begin() + n, v[1] + v[i] - 1);
            x = 1, y = i, z = it - v.begin();
            if (v[x] + v[y] <= v[z]) {
                ans = true;
                break;
            }
        }
        if (ans) cout << x << " " << y << " " << z << endl;
        else cout << -1 << endl; 
    }
}
