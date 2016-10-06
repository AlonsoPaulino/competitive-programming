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

string s, aux, ans;

int main() {
    cin >> s;
    int i = 0;
    while (i < sz(s)) {
        if (i > 0 && i + 3 < sz(s)) {
            if (s.substr(i, 3) != "dot") {
                aux += s[i++];
            } else {
                aux += ".";
                i += 3;
            }
        } else {
            aux += s[i++];
        }
    } i = 0;
    bool flag = 0;
    while (i < sz(aux)) {
        if (i > 0 && i + 2 < sz(aux)) {
            if (aux.substr(i, 2) == "at" && !flag) {
                ans += "@";
                i += 2, flag = 1;
            } else {
                ans += aux[i++];
            }
        } else {
            ans += aux[i++];
        }
    }
    cout << ans << "\n";
}