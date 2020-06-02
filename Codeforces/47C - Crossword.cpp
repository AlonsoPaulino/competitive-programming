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

const int N = 6;

vs s(N), v(N / 2), h(N / 2);
vs ans;
int n, m;
bool possible = false;

bool solve() {
    for (int i = 0; i < N; ++i) {
        (i < N / 2) ? h[i] = s[i] : v[i - N / 2] = s[i];
    }
    n = sz(v[1]), m = sz(h[1]);
    if (sz(v[0]) + sz(v[2]) - 1 == sz(v[1]) && sz(h[0]) + sz(h[2]) - 1 == sz(h[1])) {
        if (h[0][0] == v[0][0] && h[0][sz(h[0]) - 1] == v[1][0] && h[1][0] == v[0][sz(v[0]) - 1] && h[1][sz(h[1]) - 1] == v[2][0] && 
            h[1][sz(h[0]) - 1] == v[1][sz(v[0]) - 1] && h[2][0] == v[1][sz(v[1]) - 1] && h[2][sz(h[2]) - 1] == v[2][sz(v[2]) - 1]) {
            vs aux;
            aux.pb(h[0]); 
            for (int i = sz(h[0]); i < m; ++i) aux[0] += ".";
            for (int i = 1; i + 1 < sz(v[0]); ++i) {
                string s1 = "", s2 = "";
                s1 += v[0][i], s2 += v[1][i];
                for (int j = 2; j < sz(h[0]); ++j) s1 += ".";
                for (int j = sz(h[0]); j < m; ++j) s2 += ".";
                aux.pb(s1 + s2);
            }
            aux.pb(h[1]);
            for (int i = 1; i + 1 < sz(v[2]); ++i) {
                string s1 = "", s2 = "";
                for (int j = 1; j < sz(h[0]); ++j) s1 += ".";
                s1 += v[1][sz(v[0]) + i - 1];
                for (int j = sz(h[0]); j + 1 < m; ++j) s2 += ".";
                s2 += v[2][i];
                aux.pb(s1 + s2);
            }
            string s3 = ""; 
            for (int i = 1; i < m - sz(h[2]) + 1; ++i) s3 += ".";
            s3 += h[2], aux.pb(s3);
            if (sz(ans) == 0 || aux < ans) {
                ans = aux;
            }
            return 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    for (int i = 0; i < N; ++i) cin >> s[i];
    sort(all(s)), possible = solve();
    while (next_permutation(all(s))) {
        bool flag = solve();
        if (!possible) {
            possible = flag;
        }
    }
    if (possible) {
        for (int i = 0; i < sz(ans); ++i) {
            cout << ans[i] << "\n";
        }
    } else {
        cout << "Impossible\n";
    }
}