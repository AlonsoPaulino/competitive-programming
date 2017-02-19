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

ull t, n, T;

int main() {
    cin >> t;
    for (ull k = 0; k < t; ++k) {
        cin >> n >> T;
        vector<ull> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        ull li = 0, ls = 1000000000000000001LL;
        ull ans = 0;
        
        while (li < ls) {
            ull mid = (li + ls) / 2;
            ull x = 0;
            for (int i = 0; i < n; ++i) {
                x += mid / v[i];
            }
            x >= T ? ls = mid, ans = mid : li = mid + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}