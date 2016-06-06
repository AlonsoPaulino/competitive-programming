#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
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
#define debug(x) cout<<#x<<" : "<<x<<endl
#define debug2(x,y) cout<<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cout<<"hola papa"<<endl
#define MAX 100000
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

ll n, k, a, ans = 0, cnt = 0;;
vector<ll> v;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (cnt < k && a < 0) {
            v.pb(a * -1), ++cnt;
        } else {
            v.pb(a);
        }
    }
    sort(all(v));
    if (cnt < k) {
        if (k - cnt & 1) {
            v[0] *= -1;
        }
    }
    for (int i = 0; i < sz(v); ++i) ans += v[i];
    cout << ans << "\n";
}