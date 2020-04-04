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

int t;
string s;

int main() {
    ios::sync_with_stdio(false);
    
    cin >> t;
    for (int c = 1; c <= t; ++c) {
        cin >> s;
        int r = 0;
        string ans;
        for (int i = 0; i < sz(s); ++i) {
            int x = s[i] - '0';
            debug2(r, x);
            if (x > r) {
                for (int j = 0; j < x - r; ++j) {
                    ans += "(";
                }
                r += (x - r);
            } else if (x < r) {
                for (int j = 0; j < r - x; ++j) {
                    ans += ")";
                }
                r -= (r - x);
            }
            ans += s[i];
        }
        for (int i = 0; i < r; ++i) ans += ")";
        cout << "Case #" << c << ": " << ans << endl;
    }
}
