#include <bits/stdc++.h>
#define pi acos(-1)
#define sz(x) (int) x.size()
#define pii pair<int, int>
#define mii map<int, int>
#define vi vector<int>
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

string s, ans = "";

int main() {
    cin >> s;
    bool ignore = 0;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] != '/') {
            ans += s[i];
            ignore = 0;
        } else {
            if (!ignore) ans += '/';
            ignore = 1;
        }
    }
    if (sz(ans) > 1 && ans[sz(ans) - 1] == '/') ans = ans.substr(0, sz(ans) - 1);
    cout << ans << "\n";
}