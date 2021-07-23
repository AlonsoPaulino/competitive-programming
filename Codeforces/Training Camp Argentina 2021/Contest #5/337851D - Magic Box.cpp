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

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int a, b, c; cin >> a >> b >> c;
    int x, y, z; cin >> x >> y >> z;
    int ans = 0;
    vi v(7, 0); for (int i = 1; i < 7; ++i) cin >> v[i];
    if (a > x) {
        ans += v[6];
    } else if (a < 0) {
        ans += v[5];
    }
    if (b > y) {
        ans += v[2];
    } else if (b < 0) {
        ans += v[1];
    }
    if (c > z) {
        ans += v[4];
    } else if (c < 0) {
        ans += v[3];
    }
    cout << ans << endl;
}
