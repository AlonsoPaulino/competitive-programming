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

string a, b;

int main() {
    while (cin >> a >> b) {
        if (sz(a) == 1 && sz(b) == 1 && a[0] == '0' && b[0] == '0') {
            break;
        }
        int ans = 0;
        int carry = 0;
        reverse(all(a)), reverse(all(b));
        int l = max(sz(a), sz(b));
        for (int i = 0; i < l; ++i) {
            int x = 0, y = 0, result = carry;
            x = (i < sz(a) ? a[i] - '0' : 0);
            y = (i < sz(b) ? b[i] - '0' : 0);
            result += (x + y);
            if (result > 9) {
                carry = 1;
                ++ans;
            } else {
                carry = 0;
            }
        }
        if (ans == 0) {
            cout << "No carry operation.\n";
        } else {
            cout << ans << " carry operation" << (ans > 1 ? "s.\n" : ".\n");
        }
    }
    return 0;
}