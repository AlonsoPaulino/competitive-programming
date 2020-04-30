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

map<string, string> decoder;
string s, ans = "";
int i = 0;

int main() {
    decoder["."] = "0", decoder["-."] = "1", decoder["--"] = "2";
    cin >> s;
    while (i < sz(s)) {
        if (sz(decoder[s.substr(i, 1)]) > 0) {
            ans += decoder[s.substr(i++, 1)];
        } else {
            ans += decoder[s.substr(i, 2)];
            i += 2;
        }
    }
    cout << ans << "\n";
}