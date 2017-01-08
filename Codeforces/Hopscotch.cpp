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

int a, x, y;
int ans = -1;

int main() {
    cin >> a >> x >> y;
    if (y % a != 0) {
        int h = ceil((double) y / a);
        if (h > 1 && (h & 1)) {
            if (x > -1 * a && x < 0) {
                ans = ((h - 1) / 2) * 3;
            } else if (x > 0 && x < a) {
                ans = 1 + ((h - 1) / 2) * 3;
            }
        } else {
            if (x > (double) -1 * a / 2 && x < (double) a / 2) {
                if (h == 1) ans = 1;
                else {
                    ans = 2 + ((h - 2) / 2) * 3;
                }
            }
        }
    }
    cout << ans << "\n";
}