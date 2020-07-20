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

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n, lv = 0, aux = 0; cin >> n;
    string s; cin >> s;
    for (auto c: s) if (c == '[') ++aux, lv = max(aux, lv); else --aux;
    lv = lv * 2 + 1;
    char ans[lv][1000];
    memset(ans, ' ', sizeof(ans));
    int dir = 0, m = 0, j = 0;
    for (int k = 0; k < n; ++k) {
        char x = s[k];
        if (x == '[') {
            if (dir == 1) ++m;
            dir = 1;
            for (int i = m; i < lv - m; ++i) {
                if (i == m || i + 1 == lv - m) {
                    ans[i][j] = '+';
                    ans[i][j + 1] = '-';
                } else ans[i][j] = '|';
            }
        } else {
            if (dir == 1) j += 3;
            else if (dir == -1) --m;
            dir = -1;
            for (int i = m; i < lv - m; ++i) {
                if (i == m || i + 1 == lv - m) {
                    ans[i][j] = '+';
                    ans[i][j - 1] = '-';
                } else ans[i][j] = '|';
            }
        }
        ++j;
    }
    for (int x = 0; x < lv; ++x) {
        for (int y = 0; y < j; ++y) {
            cout << ans[x][y];
        }
        cout << "\n";
    }
}
