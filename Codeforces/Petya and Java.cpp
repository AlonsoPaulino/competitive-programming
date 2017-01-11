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

string s, ans;

int cmp(string a, string b) {
    if (sz(a) < sz(b)) return -1;
    if (sz(a) == sz(b)) {
        if (a < b) return -1;
        if (a == b) return 0;   
    }
    return 1;
}

int main() {
    cin >> s;
    if (s[0] == '-') {
        s = s.substr(1, sz(s));
        if (cmp(s, "128") <= 0) ans = "byte";
        else if (cmp(s, "32768") <= 0) ans = "short";
        else if (cmp(s, "2147483648") <= 0) ans = "int";
        else if (cmp(s, "9223372036854775808") <= 0) ans = "long";
        else ans = "BigInteger";
    } else {
        if (cmp(s, "127") <= 0)  ans = "byte";
        else if (cmp(s, "32767") <= 0) ans = "short";
        else if (cmp(s, "2147483647") <= 0) ans = "int";
        else if (cmp(s, "9223372036854775807") <= 0) ans = "long";
        else ans = "BigInteger";
    }
    cout << ans << "\n";
}