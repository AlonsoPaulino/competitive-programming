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

vi z_function(string s) {
    int l = 0, r = 0, t = sz(s), k;
    vi z(t); z[0] = 0;
    for (int i = 1; i < t; ++i) {
        if (i > r) {
            l = r = i;
            while (r < t && s[r - l] == s[r]) ++r;
            z[i] = r - l; --r;
        } else {
            k = i - l;
            if (z[k] < r - i + 1) z[i] = z[k];
            else {
                l = i;
                while (r < t && s[r - l] == s[r]) ++r;
                z[i] = r - l; --r;
            }
        }
    }
    return z;
}

string s;
int n;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> s; n = sz(s);
    vi z = z_function(s);
    int ans = -1, aux = 0;
    for (int i = 1; i < n; ++i) {
        if (z[i] + i == n && z[i] <= aux) {
            ans = max(ans, z[i]);
        }
        aux = max(z[i], aux);
    }
    if (ans != -1) {
        cout << s.substr(0, ans) << "\n";
    } else cout << "Just a legend\n";
}
