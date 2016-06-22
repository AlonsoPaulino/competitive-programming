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
#define debug(x) cerr <<#x<<" : "<<x<<endl
#define debug2(x,y) cerr <<#x<<" : "<<x<<" & "<<#y<<" : "<<y<<endl
#define test() cerr <<"hola papa"<<endl
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
using namespace std;

int n, m, val, aux;
string s;

int main() {
    while (cin >> n >> m) {
        bool ans = 1;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            val = s[0] - '0';
            if (i == 0 || val != aux) {
                aux = val;
            } else {
                ans = 0;
            }
            for (int j = 1; j < sz(s); ++j) {
                val = s[j] - '0';
                if (ans) {
                    if (aux != val) ans = 0;
                }
            }
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}
