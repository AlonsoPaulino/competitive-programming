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

int n, m;

bool isCorrect(string s) {
    int l = sz(s);
    int w = 0, b = 0;
    int cw = 0, cb = 0;
    for (int i = 0; i < l; ++i) {
        if (s[i] == 'B') cb++, b++, cw = 0;
        else if (s[i] == 'W') cw++, w++, cb = 0;
        if (cw >= 3 || cb >= 3) return false;
    }
    return w == b;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    vector<string> v(n);
    bool ans = true;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (i == 0) m = sz(v[i]);
        ans &= isCorrect(v[i]);
    }

    if (ans) {
        for (int j = 0; j < m; ++j) {
            string s;
            for (int i = 0; i < n; ++i) {
                s += v[i][j];
            }
            ans &= isCorrect(s);
        }
    }

    cout << (ans ? 1 : 0) << endl;
}
